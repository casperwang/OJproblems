#include <bits/stdc++.h>
#define Hina ios_base::sync_with_stdio(0),cin.tie(0)
#define int long long
#define MAXN 100000
using namespace std;

int n, m, a, b, ans;
set <int> arr;

signed main() {
	Hina;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		if (a > b) swap(a, b);
		if (arr.count(a)) arr.erase(a);
		else arr.insert(a);
		if (arr.count(b+1)) arr.erase(b+1);
		else arr.insert(b+1);
		ans = max(ans, (int)arr.size()/2);
	}
	cout << ans<< endl;
	return 0;
}