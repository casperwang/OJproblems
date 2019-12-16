#include <bits/stdc++.h>
#define MAXN 50
#define pb push_back
#define pii pair<int,int>
#define ff first
#define ss second
using namespace std;

int t, n, m;
int a, b;
char c1, c2;
bool path[MAXN+5][MAXN+5];
int vis[MAXN+5];
int arr[MAXN+5];
stack <int> dfs;
bool tf;

void DFS(int now) {
	vis[now] = 1;
	for (int i = 1; i <= 2*n; i++) {
		if (path[now][i] && !vis[i]) DFS(i);
	}
	dfs.push(now);
}

void reDFS(int now) {
	if (arr[(now+1)/2]) tf = 0;
	arr[(now+1)/2]++;
	vis[now] = 1;
	for (int i = 1; i <= 2*n; i++)
		if (path[i][now] && !vis[i])
			reDFS(i);
}

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> t;
	while (t--) {
		tf = 1;
		cin >> n >> m;
		for (int i = 1; i <= 2*n; i++)
			for (int j = 1; j <= 2*n; j++)
				path[i][j] = 0;
		for (int i = 0; i < m; i++) {
			cin >> c1 >> a >> c2 >> b;
			path[a*2-(c1=='m')][b*2-(c2!='m')] = 1;
			path[b*2-(c2=='m')][a*2-(c1!='m')] = 1;
		}
		memset(vis, 0, sizeof(vis));
		for (int i = 1; i <= 2*n; i++)
			if (!vis[i]) DFS(i);
		memset(vis, 0, sizeof(vis));
		while (dfs.size()) {
			memset(arr, 0, sizeof(arr));
			if (!vis[dfs.top()]) reDFS(dfs.top());
			dfs.pop();
		}
		if (tf) cout << "GOOD\n";
		else cout << "BAD\n";
	}
	return 0;
}