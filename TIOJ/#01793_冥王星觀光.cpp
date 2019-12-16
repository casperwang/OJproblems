#include <bits/stdc++.h>
#define MAXN 5000
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define int long long
using namespace std;

struct edge{
	int s, d, c;
	edge(){}
	edge(int s, int d, int c) : s(s), d(d), c(c) {}
};

class cmp{
public:
	bool operator() (const edge a, const edge b) {
		return a.d > b.d;
	}
};
const int inf = 1e9;
int n, m;
int ans = inf;
int a, b, c, d;
int dis1[MAXN+5], anc[MAXN+5], dis2[MAXN+5];
vector <pii> path[MAXN+5];
priority_queue <edge, vector<edge>, cmp> nxt;

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m;
	fill(dis1, dis1+n+1, inf);
	fill(dis2, dis2+n+1, inf);
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c >> d;
		path[a].pb(pii(b, c));
		path[b].pb(pii(a, d));
	}
	for (pii e : path[1]) {
		nxt.push(edge(e.ff, e.ss, e.ff));
	}
	while (nxt.size()) {
		edge now = nxt.top();
		nxt.pop();
		if(now.d > dis2[now.c]) continue;
		for (pii i : path[now.c]) {
			if (i.ff == 1 || i.ff == now.s) continue;
			if (i.ss + now.d < dis1[i.ff]) {
				if (anc[i.ff] != now.s) dis2[i.ff] = dis1[i.ff];
				dis1[i.ff] = i.ss + now.d;
				anc[i.ff] = now.s;
				nxt.push(edge(now.s, i.ss + now.d, i.ff));
			} else if (i.ss + now.d < dis2[i.ff] && now.s != anc[i.ff]) {
				dis2[i.ff] = i.ss + now.d;
				nxt.push(edge(now.s, i.ss + now.d, i.ff));
			}
		}
	}
	for (int i = 2; i <= n; i++) {
		for (pii e : path[i]) {
			if (e.ff == 1) ans = min(ans, e.ss + dis1[i]);
		}
	}
	cout << ans << '\n';
}