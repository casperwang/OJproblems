#include <bits/stdc++.h>
#define pii pair<int,int>
#define ff first
#define ss second
#define dec decr
using namespace std;

const int MAXN = 200;
int t, n, m, ans;
int arr[MAXN+1][MAXN+1];
int pre[MAXN+1][MAXN+1];
int now[MAXN+1];
deque <pii> dec, qry;

signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> t;
  while (t--) {
  	cin >> n >> m;
  	ans = 0;
  	for (int i = 1; i <= n; i++) {
  		for (int j = 1; j <= m; j++) {
  			cin >> arr[i][j];
  			if (arr[i][j] == 1) arr[i][j] = -1;
  			else arr[i][j] = 1;
  			pre[i][j] = pre[i][j-1] + arr[i][j];
  		}
  	}
  	for (int l = 1; l <= m; l++) {
  		for (int r = l; r <= m; r++) {
  			while (dec.size()) dec.pop_back();
  			dec.push_back(pii(0, 0));
  			for (int i = 1; i <= n; i++) {
  				now[i] = now[i-1] + pre[i][r] - pre[i][l-1];
  				if (!dec.size() || now[i] < dec.back().ff)
  					dec.push_back(pii(now[i], i));
  				while (qry.size() && now[i] >= qry.back().ff)
  					qry.pop_back();
  				qry.push_back(pii(now[i], i));
  			}
  			while (qry.size()) {
  				pii tmp = qry.front();
  				qry.pop_front();
  				if (!dec.size()) continue;
  				while (dec.size() && tmp.ff - dec.front().ff <= 0)
  					dec.pop_front();
  				if (!dec.size()) continue;
  				ans = max(ans, (r-l+1) * (tmp.ss-dec.front().ss));
  			}
  		}
  	}
  	cout << ans << "\n";
  }
  return 0;
}