#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, ans;

signed main() {
	cin >> n;
	int i = 1;
	n--;
	while (i <= n) i <<= 1;
	i >>= 1;
	for (; i >= 1; i >>= 1) {
		ans += ((n+i)/(i*2))*i;
	}
	cout << ans << endl;
	return 0;
}
