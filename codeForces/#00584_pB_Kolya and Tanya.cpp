#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

long long int n, ans = 1, k = 1;

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    ans = (ans * 27) % MOD;
    k = (k * 7) % MOD;
  }
  cout << (ans - k + MOD) % MOD << endl;
  return 0;
}
