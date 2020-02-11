#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#define int long long
#define pb push_back
using namespace std;

const int MAXN = 20;
int t, n, m;
string arr[MAXN+5];
int X, Y;
string ans;

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> t;
	while (t--) {
		cin >> n >> m;
		for (int i = 0; i <= n+1; i++) arr[i] = "";
		ans = "";
		for (int i = 0; i <= m+1; i++) {
			arr[0] += "#";
			arr[n+1] += "#";
		}
		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
			arr[i] = "#" + arr[i] + "#";
			for (int j = 0; j < arr[i].size(); j++)
				if (arr[i][j] == 'S') X = i, Y = j;
		}
		while (arr[X][Y] != 'T') {
			if ((arr[X+1][Y] == '.' || arr[X+1][Y] == 'T') && ans[ans.size()-1] != 'U')
				ans += 'D', X++;
			if ((arr[X-1][Y] == '.' || arr[X-1][Y] == 'T') && ans[ans.size()-1] != 'D')
				ans += 'U', X--;
			if ((arr[X][Y+1] == '.' || arr[X][Y+1] == 'T') && ans[ans.size()-1] != 'L')
				ans += 'R', Y++;
			if ((arr[X][Y-1] == '.' || arr[X][Y-1] == 'T') && ans[ans.size()-1] != 'R')
				ans += 'L', Y--;
		}
		cout << ans << "\n";
	}
 	return 0;
}