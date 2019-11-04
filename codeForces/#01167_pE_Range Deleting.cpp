#include <bits/stdc++.h>
#define Hina ios_base::sync_with_stdio(0), cin.tie(0)
#define int long long
#define ff first
#define ss second
#define pb push_back
#define MAXN 1000000
using namespace std;

int n, x;
int l, r, sum;
int ans[MAXN+5];
int a[MAXN+5];
pair<int,int> arr[MAXN+5];
vector <int> appr;

signed main() {
	Hina;
	cin >> n >> x;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (!arr[a[i]].ff) arr[a[i]].ff = i;
		arr[a[i]].ss = i;
	}
	appr.pb(0);
	for (int i = 1; i <= x; i++) {
		if (arr[i].ff) appr.pb(i);
	}
	l = -1, r = n+1;
	int k = x;
	while (k > 1 && arr[k].ss < r) {
		if (arr[k].ff) r = arr[k].ff;
		k--;
	}
	for (int i = 1; i <= x; i++) {
		k = max(i, k);
		while (k != x && arr[k+1].ff < l) {
			r = arr[k+1].ss;
			k++;
		}
		if(!arr[k].ff) {
			k = appr[lower_bound(appr.begin(), appr.end(), k)-appr.begin()-1];
			k = max(i, k);
		}
		ans[i] = k;
		if (!arr[i].ff) continue;
		if (arr[i].ff < l) break;
		l = arr[i].ss;
	}
	for (int i = 1; i <= x; i++) {
		if (ans[i]) sum += (x - ans[i] + 1);
	}
	cout << sum << endl;
	return 0;
}