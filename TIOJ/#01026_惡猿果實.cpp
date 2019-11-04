#include <bits/stdc++.h>
#define Hina ios_base::sync_with_stdio(0), cin.tie(0)
#define int long long
using namespace std;

int d, a;
string ans;

signed main() {
	Hina;
	cin >> d;
	ans = "+";
	a = 1;
	while (a < d) a = (a*2+1), ans += '+';
	for (int i = 2, j = 1; i <= a; j++, i <<= 1) {
		if (!(d & i)) ans[j-1] = '-';
	}
	cout << ans.size() << endl;
	cout << ans << endl;
}