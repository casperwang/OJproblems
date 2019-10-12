#include <bits/stdc++.h>
#define MAXN 1000
#define pb push_back
#define int long long
using namespace std;

int n, num[MAXN+5][MAXN+5], k;
int ans[MAXN+5];
bool tf;
vector <int> divi;

int gcd(int a, int b) {
  return (b==0) ? a : gcd(b, a%b);
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  k = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> num[i][j];
      if (!i) k = gcd(k, num[i][j]);
    }
  }
  for (int i = 1; i <= sqrt(k); i++) {
    if (k % i == 0) divi.pb(i), divi.pb(k/i);
  }
  for (int p = 0; p < divi.size(); p++) {
    ans[0] = divi[p];
    for (int i = 1; i < n; i++) {
      ans[i] = num[0][i]/divi[p];
    }
    tf = 1;
    for (int i = 1; i < n && tf; i++) {
      for (int j = 0; j < n && tf; j++) {
        if (i != j && num[i][j] != ans[i]*ans[j]) {
          tf = 0;
        }
      }
    }
    if (tf) {
      for (int i = 0; i < n; i++) {
        cout << ans[i] << " \n"[i==n-1];
      }
      return 0;
    }
  }
  return 0;
}