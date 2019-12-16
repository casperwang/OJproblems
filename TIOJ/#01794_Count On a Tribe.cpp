#include <bits/stdc++.h>
#define MAXN 3000
#define pii pair<int,int>
#define x first
#define y second
using namespace std;

int n, m, ans, sum;
int arr[MAXN+5][MAXN+5];
pii d[4] = {pii(0,-1),pii(-1,0),pii(0,1),pii(1,0)};

void DFS(int x, int y) {
	int t = arr[x][y];
	arr[x][y] = 0;
	sum++;
	for (int i = 0; i < 4; i++) {
		if (arr[x+d[i].x][y+d[i].y] == t)
			DFS(x+d[i].x, y+d[i].y);
	}
}

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			sum = 0;
			if (arr[i][j]) DFS(i, j);
			ans = max(ans, sum);
		}
	}
	cout << ans << '\n';
	return 0;
}