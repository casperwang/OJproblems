#include <bits/stdc++.h>
#define Hina ios_base::sync_with_stdio(0),cin.tie(0)
#define int long long
#define ff first
#define ss second
#define MAXN 100
using namespace std;

int R, C;
pair<int,int> dir[8] = {{-1,-1},{0,-1},{-1,0},{0,1},{1,0},{1,1},{1,-1},{-1,1}};
bool mines[MAXN+5][MAXN+5];
char ans[MAXN+5][MAXN+5];

signed main() {
	Hina;
	while (cin >> R >> C) {
		for (int i = 0; i <= R+1; i++) {
			for (int j = 0; j <= C+1; j++) {
				mines[i][j] = 0;
			}
		}
		for (int i = 1; i <= R; i++) {
			for (int j = 1; j <= C; j++) {
				cin >> mines[i][j];
			}
		}
		for (int i = 1; i <= R; i++) {
			for (int j = 1; j <= C; j++) {
				if (mines[i][j]) ans[i][j] = 'X';
				else {
					ans[i][j] = '0';
					for (int k = 0; k < 8; k++) {
						ans[i][j] += mines[i+dir[k].ff][j+dir[k].ss];
					}
				}
				cout << ans[i][j] << " \n"[j==C];
			}
		}
	}
	return 0;
}