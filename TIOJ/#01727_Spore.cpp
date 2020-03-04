#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#define pb push_back
#define pii pair<int,int>
#define pip pair<int,pii>
#define ff first
#define ss second
using namespace std;

const int MAXN = 2000;
const int INF = 1e9;
int t, n, k, c;
int cnt, sum, ans;
pii mmin;
pii pts[MAXN+5];
#define x(i) (pts[i].ff)
#define y(i) (pts[i].ss)
int C[MAXN+5];
pip edges[MAXN*MAXN/2];
int dsu[MAXN+5];
pip mmax[MAXN+5];
vector <pii> newpath[MAXN+5];

int find(int a) {
	if (dsu[a] != a) dsu[a] = find(dsu[a]);
	return dsu[a];
}

void Union(int a, int b) {
	dsu[find(a)] = find(b);
}

void DFS(int now, int par) {
	for (pii i : newpath[now]) {
		if (i.ff == par || i.ff < 0) continue;
		mmax[i.ff] = max(mmax[now], pip(i.ss, pii(now, i.ff)));
		DFS(i.ff, now);
	}
}

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> t;
	while (t--) {
		cin >> n >> k;
		cnt = sum = 0;
		mmin.ff = ans = INF;
		for (int i = 0; i <= n; i++) {
			dsu[i] = i;
			newpath[i].clear();
		}
		for (int i = 0; i < n; i++) {
			cin >> x(i) >> y(i) >> c;
			C[i] = c;
			mmin = min(mmin, pii(c, i));
			for (int j = 0; j < i; j++) {
				c = (x(i)-x(j))*(x(i)-x(j))+(y(i)-y(j))*(y(i)-y(j));
				edges[cnt++] = pip(c, pii(i, j));
			}
		}
#define A(i) (edges[i].ss.ff)
#define B(i) (edges[i].ss.ss)
		sort(edges, edges+cnt);
		c = 1;
		for (int i = 0; i < cnt && c < n; i++) {
			if (find(A(i)) != find(B(i))) {
				sum += edges[i].ff, c++;
				newpath[A(i)].pb(pii(B(i), edges[i].ff));
				newpath[B(i)].pb(pii(A(i), edges[i].ff));
				Union(A(i), B(i));
			}
		}
		if (k <= 1) {
			cout << sum << "\n";
			continue;
		}
		sum += mmin.ff, C[mmin.ss] = INF;
		newpath[n].pb(pii(mmin.ss, mmin.ff));
		newpath[mmin.ss].pb(pii(n, mmin.ff));
		ans = sum;
#undef A
#undef B
#define A(i) (mmax[i].ss.ff)
#define B(i) (mmax[i].ss.ss)
		for (int i = 2; i <= min(k, n); i++) {
			for (int j = 0; j < n; j++)
				mmax[j].ff = -INF;
			DFS(n, -1);
			mmin.ff = INF;
			for (int j = 0; j < n; j++)
				mmin = min(mmin, pii(C[j] - mmax[j].ff, j));
			if (mmin.ff >= 0) break;
			int id = mmin.ss;
			sum += C[id] - mmax[id].ff;
			for (int j = 0; j < newpath[A(id)].size(); j++) {
				if (newpath[A(id)][j].ff == B(id)) {
					newpath[A(id)].erase(newpath[A(id)].begin()+j);
					break;
				}
			}
			for (int j = 0; j < newpath[B(id)].size(); j++) {
				if (newpath[B(id)][j].ff == A(id)) {
					newpath[B(id)].erase(newpath[B(id)].begin()+j);
					break;
				}
			}
			newpath[n].pb(pii(mmin.ss, C[mmin.ss]));
			newpath[mmin.ss].pb(pii(n, C[mmin.ss]));
			C[mmin.ss] = INF;
			ans = min(ans, sum);
		}
		cout << ans << "\n";
	}
	return 0;
}