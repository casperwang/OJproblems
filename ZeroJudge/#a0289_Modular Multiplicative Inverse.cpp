#include <bits/stdc++.h>
#define Hina ios_base::sync_with_stdio(0),cin.tie(0)
#define int long long
#define ff first
#define ss second
using namespace std;

int n, a;

pair <int, int> exgcd(int a, int b) {
	if (!b) return {1, 0};
	pair <int, int> q = exgcd(b, a%b);
	return {q.ss, q.ff - q.ss * (a/b)};
}

int gcd(int a, int b) {
	return (!b)?a:gcd(b, a%b);
}

signed main() {
	Hina;
	while (cin >> a >> n) {
		if (gcd(a, n) > 1 || a == n || n == 1) cout << "No Inverse" << endl;
		else cout << ((exgcd(a, n).ff%n)+n)%n << endl;
	}
	return 0;
}