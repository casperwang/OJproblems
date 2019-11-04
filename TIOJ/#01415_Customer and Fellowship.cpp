#include <bits/stdc++.h>
#define pii pair<int,int>
#define MAXN 10000
#define ff first
#define ss second
using namespace std;

int d, n, a, ans;
map <int,int> appr;

signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  while (cin >> d) {
    appr.clear();
    ans = 0;
    for (int i = 0; i < d; i++) {
      cin >> n;
      for (int j = 0; j < n; j++) {
        cin >> a;
        appr[a]++;
      }
      ans += appr.rbegin()->ff - appr.begin()->ff;
      appr[appr.begin()->ff]--;
      if (appr.begin()->ss == 0) appr.erase(appr.begin()->ff);
      appr[appr.rbegin()->ff]--;
      if (appr.rbegin()->ss == 0) appr.erase(appr.rbegin()->ff);
    }
    cout << ans << '\n';
  }
  return 0;
}