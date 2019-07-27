#include <bits/stdc++.h>
#define int long long
#define MAXN 100000
using namespace std;

int n;
int c[MAXN+5], t[MAXN+5];
map <int, int> appr;

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> c[i];
    if (i) appr[c[i]-c[i-1]]++;
  }
  for (int i = 0; i < n; i++) {
    cin >> t[i];
    if (i) appr[t[i]-t[i-1]]--;
  }
  bool tf = 1;
  for (auto i : appr) if (i.second != 0) tf = 0;
  if (tf && c[0] == t[0] && c[n-1] == t[n-1]) cout << "Yes" << endl;
  else cout << "No" << endl; 
  return 0;
}
