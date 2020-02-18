#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#define int long long
using namespace std;

const int MAXN = 1000;
int n, m, id;
string arr[MAXN+5];
bool vis[MAXN+5][MAXN+5];
int dx[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int dy[8] = {1, 1, 1, 0, -1, -1, -1, 0};

void DFS(int x, int y) {
	for (int i = 0; i < 8; i++) {
		if (!vis[x+dx[i]][y+dy[i]] && arr[x+dx[i]][y+dy[i]] == '1') {
			vis[x+dx[i]][y+dy[i]] = 1;
			DFS(x+dx[i], y+dy[i]);
		}
	}
}

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	while (cin >> n >> m) {
		if (!n && !m) return 0;
		id = 0;
		memset(vis, 0, sizeof(vis));
		arr[0] = arr[n+1] = "";
		for (int i = 0; i <= m+1; i++)
			arr[0] += '0', arr[n+1] += '0';
		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
			arr[i] = '0' + arr[i] + '0';
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (!vis[i][j] && arr[i][j] == '1') {
					vis[i][j] = 1;
					id++, DFS(i, j);
				}
			}
		}
		cout << id << "\n";
	}
	return 0;
}