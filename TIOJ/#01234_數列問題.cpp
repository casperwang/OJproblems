#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#define pb push_back
#define pii pair<int,int>
#define ff first
#define ss second
using namespace std;

const int MAXN = 70;
int n;
vector <pii> arr;

const bool cmp(const pii a, const pii b) {
	return a.ff * b.ss > a.ss * b.ff;
}

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	if (n == 2) {
		cout << "1\n1/2\n";
		return 0;
	}
	for (int i = 2; i <= n; i++)
		for (int j = 1; j < i; j++)
			if (__gcd(i, j) == 1)
				arr.pb(pii(j, i));
	sort(arr.begin(), arr.end(), cmp);
	cout << arr.size() << "\n";
	cout << arr[arr.size()-n].ff << "/" << arr[arr.size()-n].ss << "\n";
}