#include <bits/stdc++.h>
#define Hina ios_base::sync_with_stdio(0),cin.tie(0)
#define MAXN 100
#define INF (int)1e18
using namespace std;
 
int C, S, Q;
int a, b, c;
int tf = 0;
int path[MAXN+5][MAXN+5];

signed main() {
	Hina;
	while (cin >> C >> S >> Q) {
		if (!C && !S && !Q) return 0;
		if (tf) cout << endl;
		cout << "Case #" << ++tf << endl;
		for (int i = 1; i <= C; i++) {
			for (int j = 1; j <= C; j++) {
				path[i][j] = INF;
			}
		}
		for (int i = 0; i < S; i++) {
			cin >> a >> b >> c;
			path[a][b] = path[b][a] = c;
		}
		for (int k = 1; k <= C; k++) {
			for (int i = 1; i <= C; i++) {
				for (int j = 1; j <= C; j++) {
					path[i][j] = min(path[i][j], max(path[i][k], path[k][j]));
				}
			}
		}
		for (int i = 0; i < Q; i++) {
			cin >> a >> b;
			if (path[a][b] == INF) cout << "no path" << endl;
			else cout << path[a][b] << endl;
		}
	}
	return 0;
}