#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

const int MAXN = 500;
int n;
int ans[3];
string m[MAXN+5];
int dx[8] = {-1, 0, 1, 1, 1, 0,-1,-1};
int dy[8] = { 1, 1, 1, 0,-1,-1,-1, 0};

bool in_map(int x, int y) {
	if (x >= 0 && x < n && y >= 0 && y < n)
		return 1;
	return 0;
}

int dfs(int x, int y, int dir, int len) {
	if (len == 5 && (!in_map(x+dx[dir], y+dy[dir]) || m[x+dx[dir]][y+dy[dir]] != m[x][y])) return 1;
	if (in_map(x+dx[dir], y+dy[dir]) && m[x+dx[dir]][y+dy[dir]] == m[x][y])
		return dfs(x+dx[dir], y+dy[dir], dir, len+1);
	return 0;
}

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	while (cin >> n) {
		if (!n) return 0;
		for (int i = 0; i < n; i++)
			cin >> m[i];
		ans[0] = ans[1] = ans[2] = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				for (int k = 0; k < 8; k++)
					if (in_map(i+dx[k], j+dy[k]) && m[i+dx[k]][j+dy[k]] == m[i][j] && m[i][j] != '.')
						if (!in_map(i+dx[(k+4)%8], j+dy[(k+4)%8]) || m[i+dx[(k+4)%8]][j+dy[(k+4)%8]] != m[i][j])
							ans[m[i][j]-'A'] += dfs(i+dx[k], j+dy[k], k, 2);
		cout << "A " << ans[0]/2 << "\n";
		cout << "B " << ans[1]/2 << "\n";
		cout << "C " << ans[2]/2 << "\n\n";
	}
}