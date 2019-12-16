#include <bits/stdc++.h>
#define INF 32767
using namespace std;

int n, m, ans;
int arr[100][100];

void DFS(int x, int y, int arr[100][100], int len) {
	if (len >= ans) return;
	for (register int i = 0; i < n; i++) {
		for (register int j = 0; j < m; j++) {
			if (i == x || j == y || i+j==x+y || i+y==x+j)
				arr[i][j]++;
		}
	}
	int cnt = 0, a, b;
	for (register int i = 0; i < n; i++) {
		a = (i+(n>>1)+n-2)%n;
		if (a == x) continue;
		for (register int j = 0; j < m; j++) {
			b = (j+(m>>1)+n-2)%m;
			if (!arr[a][b] && cnt <= 10) DFS(a, b, arr, len+1), cnt++;
		}
	}
	for (register int i = 0; i < n; i++) {
		for (register int j = 0; j < m; j++) {
			if (i == x || j == y || i+j==x+y || i+y==x+j)
				arr[i][j]--;
		}
	}
	if (!cnt) ans = min(ans, len);
	return;
}

signed main() {
	cin >> n >> m;
	ans = (n*m+9-1)/9;
	ans = min(ans, min(n, m));
	if (m > n) swap(n, m);
	if (n*m <= 120) {
		for (int i = 0; i < n; i++) {
			for (int j = i+1; j < m; j++) {
				DFS(i, j, arr, 1);
			}
		}
	} else {
		DFS(1, 1, arr, 1);
		DFS(1, (m-1)/2, arr, 1);
		DFS((n-1)/2, (m-1)/2, arr, 1);
	}
	cout << ans << '\n';
}