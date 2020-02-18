#include <bits/stdc++.h>
#define pb push_back
#define pii pair<int,int>
#define ff first
#define ss second
using namespace std;

const int MAXN = 100000;
const int INF = 2e9;
int n, m, a, b, d;
int n1, n2, c1, c2, p1, p2;
int ans;

inline char readchar() {
    static const size_t bufsize = 65536;
    static char buf[bufsize];
    static char *p = buf, *end = buf;
    if (p == end) end = buf + fread_unlocked(buf, 1, bufsize, stdin), p = buf;
    return *p++;
}

inline void const Read(int & p) {
	p = 0;
	int tmp = 0;
	char c = readchar();
	tmp = !(c^'-');
	while (c < '0' || c > '9') {
		c = readchar();
	}
	while (c >= '0' && c <= '9')
		p = (p<<3)+(p<<1)+(c^48), c = readchar();
	p = tmp?-p:p;
}

class Dijkstra{
public:
	vector <pii> path[MAXN+5];
	int dis[MAXN+5], now, d;
	priority_queue <pii, vector<pii>, greater<pii>> nxt;
	inline void add_edge(int a, int b, int c) {
		path[a].pb(pii(b, c));
	}
	int shortest_path(int s, int t) {
		for (int i = 1; i <= n; i++)
			dis[i] = INF;
		dis[s] = 0;
		nxt.push(pii(0, s));
		while (nxt.size()) {
			now = nxt.top().ss, d = nxt.top().ff;
			nxt.pop();
			for (pii e : path[now]) {
				if (d + e.ss < dis[e.ff]) {
					dis[e.ff] = d + e.ss;
					nxt.push(pii(dis[e.ff], e.ff));
				}
			}
			while (nxt.size() && nxt.top().ff > dis[nxt.top().ss])
				nxt.pop();
		}
		return dis[t];
	}
} a1, a2;

signed main() {
	//ios_base::sync_with_stdio(0), cin.tie(0);
	Read(n), Read(m), Read(a), Read(b), Read(d);
	for (int i = 0; i < m; i++) {
		Read(n1), Read(n2), Read(c1), Read(p1), Read(c2), Read(p2);
		a1.add_edge(n1, n2, c1);
		a2.add_edge(n1, n2, c1+(d-1)*p1);
		a1.add_edge(n2, n1, c2);
		a2.add_edge(n2, n1, c2+(d-1)*p2);
	}
	ans = min(a1.shortest_path(a, b) + a1.shortest_path(b, a)
		      , a2.shortest_path(a, b) + a2.shortest_path(b, a));
	cout << ans << "\n";
}