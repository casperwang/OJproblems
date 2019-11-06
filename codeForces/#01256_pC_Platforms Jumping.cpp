#include <bits/stdc++.h>
#define MAXN 1000
#define int long long
#define pb push_back
using namespace std;

int n, m, d, now, sum, k, tmp;
int arr[MAXN+5];
vector <int> ans;

signed main() {
	cin >> n >> m >> d;
	now = 1;
	for (int i = 0; i < m; i++) {
		cin >> arr[i], sum += arr[i];
		ans.pb(now+d-1);
		now = now+d+arr[i]-1;
	}
	if (now > n) {
		tmp = now-n-1;
		for (int i = ans.size()-1; i >= 0 && tmp>0; i--) {
			ans[i] -= tmp;
			if (i) tmp = ans[i-1]+arr[i-1]-ans[i];
		}
	}
	if (n-ans[m-1]-arr[m-1]+1 >= d || sum > n) cout << "NO" << '\n';
	else {
		cout << "YES" << '\n';
		now = 1;
		for (int i = 0; i < ans.size(); i++) {
			while (now < ans[i]) cout << 0 << " ", now++;
			while (now < ans[i]+arr[i]) cout << i+1 << " ", now++;
		}
		while (now <= n) cout << 0 << " ", now++;
		cout << '\n';
	}
}