#include <bits/stdc++.h>
#define Hina ios_base::sync_with_stdio(0), cin.tie(0)
#define int long long
using namespace std;

int n, ans;
int d, w;
stack <int> stk;

signed main() {
	Hina;
	cin >> n;
	ans = n;
	for (int i = 0; i < n; i++) {
		cin >> w >> d;
		while (stk.size() && d < stk.top()) stk.pop();
		if (stk.size() && d == stk.top()) ans--;
		else stk.push(d);
	}
	cout << ans << endl;
	return 0;
}