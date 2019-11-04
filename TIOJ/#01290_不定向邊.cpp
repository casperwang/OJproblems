#include <bits/stdc++.h>
#define Hina ios_base::sync_with_stdio(0), cin.tie(0)
#define MAXN 1000
#define INF 1e18
#define pb push_back
#define pii pair<int,int>
#define int long long
#define ff first
#define ss second
using namespace std;

int n, m, s, t;
int a, b, c;
int dis[MAXN+5];
bool vis[MAXN+5];
vector < pii > path[MAXN+5];
pii tmp;
priority_queue < pii , vector< pii >, greater < pii > > nxt;

signed main() {
	Hina;
	while (cin >> n >> m) {
		cin >> s >> t;
		for (int i = 1; i <= n; i++) {
			dis[i] = INF;
			vis[i] = 0;
			path[i].clear();
		}
		while (nxt.size()) nxt.pop();
		for (int i = 0; i < m; i++) {
			cin >> a >> b >> c;
			path[a].pb({b,c});
			path[b].pb({a,c});
		}
		dis[s] = 0;
		nxt.push({0, s});
		for (int i = 0; i < n; i++) {
			while (nxt.size() && vis[nxt.top().ss]) nxt.pop();
			if (!nxt.size()) break;
			tmp = nxt.top();
			//cout << tmp.ss << " " << tmp.ff << endl;
			vis[tmp.ss] = 1;
			for (int j = 0; j < path[tmp.ss].size(); j++) {
				if (tmp.ff + path[tmp.ss][j].ss < dis[path[tmp.ss][j].ff]) {
					dis[path[tmp.ss][j].ff] = tmp.ff + path[tmp.ss][j].ss;
					nxt.push({dis[path[tmp.ss][j].ff], path[tmp.ss][j].ff});
				}
			}
		}
		if (dis[t] == INF) {
			cout << "He is very hot" << endl;
		} else {
			cout << dis[t] << endl;
		}
	}
	return 0;
}