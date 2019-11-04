#include <bits/stdc++.h>
#define Hina ios_base::sync_with_stdio(0), cin.tie(0)
#define int long long
#define MAXN 1000000
using namespace std;

int n, ans;
int arr[MAXN+5];
map <int,int> appr;

signed main() {
	Hina;
	while (cin >> n) {
		ans = 0;
		appr.clear();
		appr[0] = 0;
		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
			if (arr[i] > 0) arr[i] = 1;
			else if (arr[i] < 0) arr[i] = -1;
			arr[i] += arr[i-1];
			if (appr.count(arr[i])) ans = max(ans, i-appr[arr[i]]);
			else appr[arr[i]] = i;
		}
		cout << ans << "\n";
	}
	return 0;
}