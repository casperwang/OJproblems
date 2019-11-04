#include <bits/stdc++.h>
#define Hina ios_base::sync_with_stdio(0), cin.tie(0)
#define int long long
#define MAXN 100000
#define ff first
#define ss second
using namespace std;

int n, m, a, b;
int arr[MAXN+5];
pair <int,int> ans[MAXN+5];
int pos[MAXN+5];

signed main() {
	//Hina;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) 
		ans[i].ff = ans[i].ss = pos[i] = arr[i] = i;
	for (int i = 1; i <= m; i++) {
		cin >> a;
		if (pos[a] > 1) {
			b = arr[pos[a]-1];
			swap(arr[pos[a]], arr[pos[b]]);
			pos[b]++;
			pos[a]--;
			ans[a].ff = min(ans[a].ff, pos[a]);
			ans[a].ss = max(ans[a].ss, pos[a]);
			ans[b].ff = min(ans[b].ff, pos[b]);
			ans[b].ss = max(ans[b].ss, pos[b]);
		}
	}
	for (int i = 1; i <= n; i++) {
		cout << ans[i].ff << ' ' << ans[i].ss << '\n';
	}
	return 0;
}