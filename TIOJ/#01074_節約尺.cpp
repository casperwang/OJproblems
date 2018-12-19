#include <iostream>
using namespace std;

int n, num[20+5], sum;
bool appr[1000];

int main() {
  while (cin >> n) {
    if (!n) return 0;
    sum = 0;
    for (int i = 0; i < n; i++) {
      cin >> num[i];
      sum += num[i];
    }
    for (int i = 0; i <= sum; i++) appr[i] = 0;
    int tmp;
    for (int i = 0; i < n; i++) {
      tmp = 0;
      for (int j = i; j < n; j++) {
        tmp += num[j];
        appr[tmp] = 1;
      }
    }
    bool tf = 1;
    if (sum == n) tf = 0;
    for (int i = 1; i <= sum; i++) {
      if (!appr[i]) tf = 0;
    }
    if (tf) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
  return 0;
}
