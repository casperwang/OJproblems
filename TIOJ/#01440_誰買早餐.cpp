#include <bits/stdc++.h>
#define Hina ios_base::sync_with_stdio(0),cin.tie(0)
#define int long long
#define MAXN 1000000
#define ff first
#define ss second
using namespace std;

int n, m, k;
int ans;
int arr[MAXN+5];
pair <int, int> bft[MAXN+5];
priority_queue <int, vector<int>, greater<int> > now;

signed main() {
	Hina;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr+n);
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> bft[i].ff >> bft[i].ss;
	}
	sort(bft, bft+m);
	k = m-1;
	for (int i = n-1; i >= 0; i--) {
		while (k >= 0 && bft[k].ff >= arr[i]) {
			now.push(bft[k].ss);
			k--;
		}
		if (now.size() == 0) {
			cout << "Impossible." << endl;
			return 0;
		}
		ans += now.top();
		now.pop();
	}
	cout << ans << endl;
}