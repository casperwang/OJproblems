#include <bits/stdc++.h>
using namespace std;

int n;
int ans[20] = {1, 1, 2, 5, 14, 42, 132, 429, 1430, 4862, 16796, 58786, 208012, 742900, 2674440, 9694845, 35357670, 129644790, 477638700, 1767263190};

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	while (cin >> n) cout << ans[n] << '\n';
}