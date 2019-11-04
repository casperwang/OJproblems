#include <bits/stdc++.h>
#define Hina ios_base::sync_with_stdio(0), cin.tie(0)
#define int long long
#define INF 1e18
using namespace std;

int t, k, p;
int arr[10];

signed main() {
	Hina;
	cin >> t;
	for (int i = 0; i < t; i++) {
		k = INF;
		for (int j = 0; j < 10; j++) {
			cin >> arr[j];
			if (arr[j] < k || (arr[j] <= k && p == 0)) {
				k = arr[j], p = j;
			}
		}
		if (p == 0) {
			cout << 1;
			for (int j = 0; j <= arr[0]; j++) cout << 0;
			cout << endl;
		} else {
			for (int j = 0; j <= arr[p]; j++) cout << p;
			cout << endl;
		}
	}
	return 0;
}