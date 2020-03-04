#include <bits/stdc++.h>
#define y1 y_1
using namespace std;

const int MAXN = 100;
int n, m, k, a, cnt;
int x1, y1, x2, y2;
bool vis[2][MAXN+5][MAXN+5];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m;
	cin >> x1 >> y1 >> x2 >> y2;
	cin >> k;
	vis[1][x1][y1] = 1;
	for (int p = 0; p < k; p++) {
		cin >> a;
		cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (!vis[(p+1)&1][i][j]) continue;
				cnt++;
				for (int d = 0; d < 4; d++) {
					vis[p&1][((i+a*dx[d])%n+n)%n][((j+a*dy[d])%m+m)%m] = 1;
				}
				vis[(p+1)&1][i][j] = 0;
			}
		}
		if (cnt == n*m && p%2 != k%2) break;
	}
	if (vis[(k+1)&1][x2][y2])
		cout << "YES\n";
	else
		cout << "NO\n";
}