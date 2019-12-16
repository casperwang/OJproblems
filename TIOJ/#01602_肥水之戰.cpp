#include <bits/stdc++.h>
#define MAXN 1500
#define pii pair<int,int>
#define ff first
#define ss second
using namespace std;

int n, m;
int x, y;
int arr[MAXN+5][MAXN+5];
pii d[4] = {pii(0,-1),pii(0,1),pii(1,0),pii(-1,0)};
bool vis[MAXN+5][MAXN+5];

void DFS(int y, int x) {
	if (x > m || x < 1 || y > n || y < 1) return;
	vis[y][x] = 1;
	for (int i = 0; i < 4; i++) {
		if (vis[y+d[i].ff][x+d[i].ss]) continue;
		if (arr[y][x] <= arr[y+d[i].ff][x+d[i].ss])
			DFS(y+d[i].ff, x+d[i].ss);
	}
}

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> arr[i][j];
	cin >> x >> y;
	DFS(y+1, x+1);
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
			if (vis[j][i])
				cout << "(" << i-1 << "," << j-1 << ")\n";
	return 0;
}