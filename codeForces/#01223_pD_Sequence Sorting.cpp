#include <bits/stdc++.h>
#define Hina ios_base::sync_with_stdio(0), cin.tie(0)
#define MAXN 300000
#define ff first
#define ss second
#define pb push_back
using namespace std;

int q, n, ans, sum;
int arr[MAXN+5];
pair <int,int> num[MAXN+5];
vector <int> appr;

signed main() {
	Hina;
	cin >> q;
	for (int i = 0; i < q; i++) {
		cin >> n;
		ans = sum = 0;
		appr.clear();
		for (int j = 1; j <= n; j++) num[j].ff = 0;
		for (int j = 1; j <= n; j++) {
			cin >> arr[j];
			if (!num[arr[j]].ff) {
				num[arr[j]].ff = num[arr[j]].ss = j;
				sum++;
			} else {
				num[arr[j]].ss = j;
			}
		}
		for (int j = 1; j <= n; j++) {
			if (!num[j].ff) continue;
			appr.pb(j);
		}
		sum = 1;
		for (int j = 0; j < appr.size()-1; j++) {
			if (num[appr[j]].ss > num[appr[j+1]].ff) sum = 0;
			sum++;
			ans = max(sum, ans);
		}
		ans = max(sum, ans);
		cout << appr.size() - ans << endl;
	}
	return 0;
}