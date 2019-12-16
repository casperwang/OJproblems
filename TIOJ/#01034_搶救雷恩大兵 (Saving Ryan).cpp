#include <bits/stdc++.h>
#define MAXN 20
#define INF 1e9
#define pii pair<int,int>
#define ff first
#define ss second
using namespace std;

int n, q, ans;
int x_1, y_1, x_2, y_2, s, t;
int dis[MAXN*MAXN+5][MAXN*MAXN+5];
pii dir[4] = {pii(1,0),pii(0,1),pii(-1,0),pii(0,-1)};

bool ok(int x, int y) {
	if (x >= 0 && x < n && y >= 0 && y < n) return 1;
	return 0;
}

signed main() {
	cin >> n;
	for (int i = 0; i < n*n; i++)
		for (int j = 0; j < n*n; j++)
			dis[i][j] = INF;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> dis[i*n+j][i*n+j];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			for (int d = 0; d < 4; d++)
				if (ok(i+dir[d].ff,j+dir[d].ss))
					dis[i*n+j][(i+dir[d].ff)*n+j+dir[d].ss]
					 = dis[i*n+j][i*n+j]+dis[(i+dir[d].ff)*n+j+dir[d].ss][(i+dir[d].ff)*n+j+dir[d].ss];
	for (int k = 0; k < n*n; k++)
		for (int i = 0; i < n*n; i++)
			for (int j = 0; j < n*n; j++)
				if (dis[i][k]+dis[k][j]-dis[k][k]<dis[i][j])
					dis[i][j] = dis[i][k]+dis[k][j]-dis[k][k];
	cin >> q;
	for (int i = 0; i < q; i++) {
		cin >> x_1 >> y_1 >> x_2 >> y_2;
		x_1--, y_1--, x_2--, y_2--;
		s = x_1*n+y_1, t = x_2*n+y_2;
		ans = INF;
		for (int k = 0; k < n*n; k++) {
			ans = min(ans, dis[s][k]+dis[k][t]-2*dis[k][k]);
		}
		cout << ans << '\n';
	}
}