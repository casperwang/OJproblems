#include <bits/stdc++.h>
#define Hina ios_base::sync_with_stdio(0),cin.tie(0)
#define MAXN 10000
#define int long long
using namespace std;

int n, k, ans;
int arr1[MAXN+5], arr2[MAXN+5];
bool tf = 1;

signed main() {
	Hina;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> arr2[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> arr1[i];
	}
	for (int i = 0; i < n; i++) {
		//cout << arr2[i] << " ";
		if (arr1[i] != arr2[i]) {
			if (i+k <= n) {
				int tmp = (arr1[i]+9-arr2[i])%9;
				for (int j = i; j < i+k; j++) {
					arr2[j] += tmp;
					arr2[j] = (arr2[j]-1)%9+1;
				}
				ans += tmp;
			} else {
				tf = 0;
			}
		}
	}
	if (!tf) cout << 0 << endl;
	else cout << ans << endl;
	return 0;
}