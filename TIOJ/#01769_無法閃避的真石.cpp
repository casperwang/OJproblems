#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#define int unsigned long long
using namespace std;

const int MAXN = 2000000;
int n, t, tf;
int arr[MAXN+5];

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> t;
	while (t--) {
		cin >> n;
		tf = 1;
		for (int i = 1; i <= (1<<(n+1))-1; i++) {
			cin >> arr[i];
		}
		sort(arr+1, arr+(1<<(n+1)));
		for (int i = 1; i <= (1<<n)-1; i++) {
			if (arr[i*2] / 2 != arr[i]) tf = 0;
			if (arr[i*2+1] / 2 != arr[i]) tf = 0;
		}
		if (tf) cout << "dodge\n";
		else cout << "do not dodge\n";
	}
 	return 0;
}