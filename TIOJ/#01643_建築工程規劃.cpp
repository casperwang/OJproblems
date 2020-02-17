#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#define pii pair<int,int>
#define ff first
#define ss second
#define max(a,b) a>b?a:b
#define min(a,b) a<b?a:b
using namespace std;

const int MAXN = 1000;
const int INF = 2e9;
int n, m, k, ans, tmp;
int arr[MAXN+1][MAXN+1];
pii mm[MAXN+1];
deque <pii> mmin, mmax;

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> arr[i][j];
	for (int l = 1; l <= n; l++) {
		for (int j = 1; j <= m; j++)
			mm[j] = {-INF, INF};
		for (int r = l; r <= n; r++) {
			tmp = 1;
			for (int j = 1; j <= m; j++) {
				mm[j].ff = max(mm[j].ff, arr[r][j]);
				mm[j].ss = min(mm[j].ss, arr[r][j]);
			}
			if ((r-l+1) * m <= ans) continue;
			for (int j = 1; j <= m; j++) {
				if ((r-l+1) * (m-tmp+1) <= ans) break;
				if (mm[j].ff - mm[j].ss > k) {
					tmp = j+1;
					continue;
				}

				while (mmin.size() && mm[j].ss <= mmin.back().ff)
					mmin.pop_back();
				mmin.push_back(pii(mm[j].ss, j));
				while (mmin.size() && mmin.back().ff - mmin.front().ff > k)
					tmp = max(tmp, mmin.front().ss+1), mmin.pop_front();

				while (mmax.size() && mm[j].ff >= mmax.back().ff)
					mmax.pop_back();
				mmax.push_back(pii(mm[j].ff, j));
				while (mmax.size() && mmax.front().ff - mmax.back().ff > k)
					tmp = max(tmp, mmax.front().ss+1), mmax.pop_front();

				while (mmin.size() && mmax.size() && mmax.front().ff - mmin.front().ff > k) {
					if (mmax.front().ss < mmin.front().ss)
						tmp = max(tmp, mmax.front().ss+1), mmax.pop_front();
					else
						tmp = max(tmp, mmin.front().ss+1), mmin.pop_front();
				}

				while (mmin.size() && mmin.front().ss < tmp)
					mmin.pop_front();
				while (mmax.size() && mmax.front().ss < tmp)
					mmax.pop_front();

				if (tmp > j) continue;
				ans = max(ans, (r-l+1) * (j-tmp+1));
			}
			mmin.clear();
			mmax.clear();
		}
	}
	cout << ans << "\n";
	return 0;
}