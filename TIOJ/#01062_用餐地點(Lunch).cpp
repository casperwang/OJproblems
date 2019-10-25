#include <bits/stdc++.h>
#define Hina ios_base::sync_with_stdio(0),cin.tie(0)
#define MAXN 100
#define int long long
using namespace std;

int n, m, k, t, x, y;
int arr[MAXN+5][MAXN+5];

signed main() {
	Hina;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
			k += arr[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			t += arr[i][j];
		}
		if (t >= k/2+k%2) {
			y = i;
			break;
		}
	}
	t = 0;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			t += arr[j][i];
		}
		if (t >= k/2+k%2) {
			x = i;
			break;
		}
	}
	cout << y << " " << x << endl;
	return 0;
}