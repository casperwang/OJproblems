#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#define int long long
#define pb push_back
#define pii pair<int,int>
#define pid pair<int,double>
#define pdi pair<double,int>
#define ff first
#define ss second
using namespace std;

const int MAXN = 10000;
const double eps = 1e-7;
const int INF = 100000;
int n, m, s, t;
int now, x, a, b;
double dis[MAXN+5], c, d;
bool vis[MAXN+5];
vector <pid> path[MAXN+5];
priority_queue <pdi, vector<pdi>, greater<pdi>> nxt;

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m >> s >> t;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		path[a].pb(pid(b, log10(c+1)));
	}
	for (int i = 1; i <= n; i++)
		dis[i] = INF;
	dis[s] = 0;
	nxt.push(pdi(0, s));
	while (nxt.size()) {
		now = nxt.top().ss, d = nxt.top().ff;
		nxt.pop();
		vis[now] = 1;
		for (pid i : path[now]) {
			if (vis[i.ff]) continue;
			if (dis[now] + i.ss + eps < dis[i.ff]) {
				dis[i.ff] = dis[now] + i.ss;
				nxt.push(pdi(dis[i.ff], i.ff));
			}
		}
	}
	x = (int)(floor(dis[t] + eps) + eps);
	dis[t] -= x;
	printf("%.2lfe+%03ld\n", pow(10, dis[t]), x);
 	return 0;
}