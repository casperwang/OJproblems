#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ff first
#define ss second
#define MAXN 100000
using namespace std;

int n, m;
int t, a, op;
int k;
vector <int> path[MAXN+5];
pair<int,int> dfs[MAXN+5];

void DFS(int now) {
	dfs[now].ff = ++k;
	for (int i = 0; i < path[now].size(); i++) {
		if (!dfs[path[now][i]].ff)
			DFS(path[now][i]);
	}
	dfs[now].ss = k;
}

class BIT{
private:
	int arr[MAXN+5];
	int lowbit(int a) { return a &- a; }
public:
	void mdy(int now, int k) {
		arr[now] += k;
		if (now+lowbit(now) > MAXN) return;
		mdy(now+lowbit(now), k);
	}
	int qry(int now) {
		return now ? arr[now] + qry(now-lowbit(now)) : 0;
	}
} bit;

signed main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> t;
		for (int j = 0; j < t; j++) {
			cin >> a;
			path[i].pb(a);
		}
	}
	DFS(1);
	for (int i = 0; i < m; i++) {
		cin >> op >> a;
		if (op == 0) {
			bit.mdy(dfs[a].ff, 1);
			bit.mdy(dfs[a].ss+1, -1);
		} else {
			if (bit.qry(dfs[a].ff) % 2) cout << 1 << endl;
			else cout << 0 << endl;
		}
	}
	return 0;
}