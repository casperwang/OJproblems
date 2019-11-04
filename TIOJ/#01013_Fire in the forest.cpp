#include <bits/stdc++.h>
#define pii pair<int,int>
#define pb push_back
#define ff first
#define ss second
using namespace std;

string bd[10] = {
"*****************",
"*...*.......**..*",
"**..*....*.*.*..*",
"*......*.**.**.**",
"*..**...**..**.**",
"**.....**..*.*..*",
"*....*..........*",
"*.....****.*...**",
"****.*.*........*",
"*****************"};
pii dir[4] = {pii(-1,0), pii(0,1), pii(1,0), pii(0,-1)};
int fx, fy, t;
int sx, sy, ex, ey;
int fire[10][17], path[10][17];
int x, y;

void BFS_fire() {
	queue <pii> nxt;
	nxt.push(pii(fx, fy));
	fire[fx][fy] = 1;
	pii tmp;
	while (nxt.size()) {
		tmp = nxt.front(), nxt.pop();
		for (int i = 0; i < 4; i++) {
			x = tmp.ff+dir[i].ff, y = tmp.ss+dir[i].ss;
			if (bd[x][y] == '.' && !fire[x][y]) {
				fire[x][y] = fire[tmp.ff][tmp.ss]+1;
				nxt.push(pii(x, y));
			}
		}
	}
}

void BFS_path() {
	queue <pii> nxt;
	path[sx][sy] = 1;
	nxt.push(pii(sx, sy));
	pii tmp;
	while (nxt.size()) {
		tmp = nxt.front(), nxt.pop();
		for (int i = 0; i < 4; i++) {
			x = tmp.ff+dir[i].ff, y = tmp.ss+dir[i].ss;
			if (bd[x][y] == '.' && !path[x][y] && (!fire[x][y] || fire[x][y]-t > path[tmp.ff][tmp.ss])) {
				path[x][y] = path[tmp.ff][tmp.ss]+1;
				nxt.push(pii(x, y));
			}
		}
	}
}

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> fx >> fy;
	cin >> t;
	cin >> sx >> sy >> ex >> ey;
	bd[ex][ey] = '*';
	BFS_fire();
	bd[ex][ey] = '.';
	BFS_path();
	if (path[ex][ey] && fire[sx][sy] > t) cout << path[ex][ey]-1 << '\n';
	else cout << "Help!" << '\n';
}