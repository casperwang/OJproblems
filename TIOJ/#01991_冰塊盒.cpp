#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#define y1 y_1
using namespace std;

const int MAXN = 1000000;
int n, m, q, ans;
int x1, x2, y1, y2;
vector<vector<int>> arr, cntX, cntY;

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m;
	arr.resize(n+1), cntX.resize(n+1), cntY.resize(n+1);
	arr[0].resize(m+1), cntX[0].resize(m+1), cntY[0].resize(m+1);
	for (int i = 1; i <= n; i++) {
		arr[i].resize(m+1), cntX[i].resize(m+1), cntY[i].resize(m+1);
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
			cntX[i][j] = cntX[i-1][j] + cntX[i][j-1] - cntX[i-1][j-1];
			cntY[i][j] = cntY[i-1][j] + cntY[i][j-1] - cntY[i-1][j-1];
			if (!arr[i][j]) continue;
			if (arr[i-1][j]) cntX[i][j]++;
			if (arr[i][j-1]) cntY[i][j]++;
		}
	}
	cin >> q;
	while (q--) {
		cin >> x1 >> y1 >> x2 >> y2;
		ans = 0;
		ans += cntX[x2][y2] - cntX[x2][y1-1] - cntX[x1][y2] + cntX[x1][y1-1];
		ans += cntY[x2][y2] - cntY[x2][y1] - cntY[x1-1][y2] + cntY[x1-1][y1];
		cout << ans << "\n";
	}
}