#include <bits/stdc++.h>
#define Hina ios_base::sync_with_stdio(0),cin.tie(0)
#define int long long
#define MAXN 100000
#define pb push_back
using namespace std;

int n, a, b, ans, s;
int Q[3];
int val[MAXN+5][3];
int deg[MAXN+5];
int arr[MAXN+5];
bool vis[MAXN+5];
bool tf = 1;
vector <int> path[MAXN+5];

void DFS(int now, int k) {
	arr[now] = k;
	vis[now] = 1;
	if (path[now].size() > 2) tf = 0;
	for (int i = 0; i < path[now].size(); i++) {
		if (!vis[path[now][i]]) DFS(path[now][i], (k+1)%3);
	}
}

int cnt(int a, int b, int c) {
	int tmp = 0;
	for (int i = 1; i <= n; i++) {
		if (arr[i] == 0) tmp += val[i][a-1];
		if (arr[i] == 1) tmp += val[i][b-1];
		if (arr[i] == 2) tmp += val[i][c-1];
	}
	return tmp;
}

signed main() {
	Hina;
	cin >> n; 
	for (int i = 1; i <= n; i++) cin >> val[i][0];
	for (int i = 1; i <= n; i++) cin >> val[i][1];
	for (int i = 1; i <= n; i++) cin >> val[i][2];
	for (int i = 1; i < n; i++) {
		cin >> a >> b;
		path[a].pb(b);
		deg[a]++;
		path[b].pb(a);
		deg[b]++;
	}
	for (int i = 1; i <= n; i++) if (deg[i] == 1) s = i;
	for (int i = 1; i <= n; i++) if (deg[i] > 2) tf = 0;
	DFS(s, 0);
	ans = 1e18;
	if (cnt(1,2,3) < ans) ans = cnt(1,2,3), Q[0]=1,Q[1]=2,Q[2]=3;
	if (cnt(1,3,2) < ans) ans = cnt(1,3,2), Q[0]=1,Q[1]=3,Q[2]=2;
	if (cnt(2,1,3) < ans) ans = cnt(2,1,3), Q[0]=2,Q[1]=1,Q[2]=3;
	if (cnt(2,3,1) < ans) ans = cnt(2,3,1), Q[0]=2,Q[1]=3,Q[2]=1;
	if (cnt(3,2,1) < ans) ans = cnt(3,2,1), Q[0]=3,Q[1]=2,Q[2]=1;
	if (cnt(3,1,2) < ans) ans = cnt(3,1,2), Q[0]=3,Q[1]=1,Q[2]=2;
	if (!tf) {
		cout << -1 << endl;
		return 0;
	}
	cout << ans << endl;
	for (int i = 1; i <= n; i++) {
		cout << Q[arr[i]] << " \n"[i==n];
	}
	return 0;
}