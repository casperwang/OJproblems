#include <bits/stdc++.h>
#define MAXN 10000
#define int long long
#define pb push_back
#define ff first
#define ss second
#define INF 1e18
using namespace std;

int n, m;
int a, b, c;
pair<int,int> now;
vector < pair<int,int> > path[MAXN+5];
int dis[MAXN+5];
priority_queue < pair<int,int>, vector< pair<int,int> >, greater< pair<int,int> > > pq;

signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		path[a].pb({b, c});
		path[b].pb({a, c});
	}
	dis[1] = 0;
	for (int i = 2; i <= n; i++) dis[i] = INF;
	pq.push({0, 1});
	for (int i = 0; i < n; i++) {
		do now = pq.top(), pq.pop();
		while (now.ff > dis[now.ss]);
		for (int j = 0; j < path[now.ss].size(); j++) {
			if (dis[path[now.ss][j].ff] > now.ff + path[now.ss][j].ss) {
				dis[path[now.ss][j].ff] = now.ff + path[now.ss][j].ss;
				pq.push({dis[path[now.ss][j].ff], path[now.ss][j].ff});
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		cout << dis[i] << endl;
	}
	return 0;
}