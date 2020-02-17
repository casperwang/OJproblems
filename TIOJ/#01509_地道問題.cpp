#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#define ll long long
#define pb push_back
#define pii pair<int,int>
#define ff first
#define ss second
using namespace std;

const int MAXN = 10050;
const int INF = (1<<30);

int n, m;
ll ans;
int a, b, c;
int now, d;
int dis[MAXN];
bool vis[MAXN];
vector <pii> path1[MAXN], path2[MAXN];
priority_queue <pii, vector <pii>, greater<pii>> nxt;

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m;
	while (m--) {
		cin >> a >> b >> c;
		path1[a].pb(pii(b, c));
		path2[b].pb(pii(a, c));
	}
	for (int i = 1; i <= n; i++)
		dis[i] = INF, vis[i] = 0;
	dis[1] = 0;
	nxt.push(pii(0, 1));
	while (nxt.size()) {
		now = nxt.top().ss, d = nxt.top().ff;
		ans += d, nxt.pop(), vis[now] = 1;
		for (pii e : path1[now]) {
			if (d + e.ss < dis[e.ff]) {
				dis[e.ff] = d + e.ss;
				nxt.push(pii(dis[e.ff], e.ff));
			}
		}
		while (nxt.size() && vis[nxt.top().ss])
			nxt.pop();
	}
	for (int i = 1; i <= n; i++)
		dis[i] = INF, vis[i] = 0;
	dis[1] = 0;
	nxt.push(pii(0, 1));
	while (nxt.size()) {
		now = nxt.top().ss, d = nxt.top().ff;
		ans += d, nxt.pop(), vis[now] = 1;
		for (pii e : path2[now]) {
			if (d + e.ss < dis[e.ff]) {
				dis[e.ff] = d + e.ss;
				nxt.push(pii(dis[e.ff], e.ff));
			}
		}
		while (nxt.size() && vis[nxt.top().ss])
			nxt.pop();
	}
	cout << ans << "\n";
	return 0;
}