#include <iostream>
#define N 100000
using namespace std;

int n, a, tmp[N+5];
int hats[N+5], same[N+5];
bool tf = 1;

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> hats[i];
    hats[i] = n-hats[i];
    same[hats[i]]++;
  }
  for (int i = 1; i <= n; i++) {
    if (same[i] % i) tf = 0;
    tmp[i] = a;
    a += same[i] / i;
  }
  if (tf) {
    cout << "Possible" << endl;
    for (int i = 0; i < n; i++) {
      if (i) cout << " ";
      same[hats[i]]--;
      hats[i] = tmp[hats[i]] + (same[hats[i]]+hats[i])/hats[i];
      cout << hats[i];
    }
    cout << endl;
  } else {
    cout << "Impossible" << endl;
  }
  return 0;
}
