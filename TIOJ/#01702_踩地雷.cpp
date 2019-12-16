#include <bits/stdc++.h>
#define MAXN 100
#define pii pair<int,int>
#define ff first
#define ss second
using namespace std;

int n, m;
pii dir[8] = {pii(0,1),pii(1,1),pii(1,0),pii(1,-1),pii(0,-1),pii(-1,-1),pii(-1,0),pii(-1,1)};
int arr[MAXN+5][MAXN+5];
char ans[MAXN+5][MAXN+5];

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	while (cin >> n >> m) {
		memset(arr, 0, sizeof(arr));
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				cin >> arr[i][j];
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (arr[i][j]) ans[i][j] = 'X';
				else {
					ans[i][j] = '0';
					for (int k = 0; k < 8; k++) {
						ans[i][j] += arr[i+dir[k].ff][j+dir[k].ss];
					}
				}
				cout << ans[i][j] << " \n"[j==m];
			}
		}
	}
}