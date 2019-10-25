#include <bits/stdc++.h>
#define Hina ios_base::sync_with_stdio(0),cin.tie(0)
#define int long long
using namespace std;

int n, p, d, w;
int x, y, z;

int gcd(int a, int b) {
	return (!b)?a:gcd(b,a%b);
}

signed main() {
	Hina;
	cin >> n >> p >> w >> d;
	if (p % gcd(w, d) || n < (p+w-1)/w) cout << -1 << endl;
	else {
		int cnt = 0;
		while ((p-cnt*d) % w != 0) cnt++;
		if ((p-cnt*d) / w < 0) {
			cout << -1 << endl;
			return 0;
		}
		cout << (p-cnt*d) / w << " " << cnt << " " << n - (p-cnt*d) / w - cnt << endl;
	}
	return 0;
}