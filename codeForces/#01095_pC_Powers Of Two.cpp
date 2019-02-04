#include <iostream>
using namespace std;
int n, k, i, j, s, t;
int p[100];
int main() {
  cin >> n >> k;
  t = k;
  for (i = n, j = 0; i > 0; i /= 2, j++) {
    if (i%2) {
      p[j] = 1;
      k--;
    }
  }
  if (k < 0 || t > n) {
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;
    while (k) {
      for (int i = 1; i < j && k; i++) {
        if (p[i]) {
          p[i]--;
          p[i-1] += 2;
          k--;
        }
      }
    }
    bool tf = 0;
    for (int i = 0, c = 1; i < j; i++, c*= 2) {
      while (p[i]) {
        if (tf) cout << " ";
        cout << c;
        if (p[i]) tf = 1;
        p[i]--;
      }
    }
    cout << endl;
  }
}
