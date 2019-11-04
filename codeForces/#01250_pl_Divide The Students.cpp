#include <bits/stdc++.h>
#define Hina ios_base::sync_with_stdio(0), cin.tie(0)
#define MAXN 200000
#define L (int)__lg(MAXN)
#define pb push_back
#define ff first
#define ss second
using namespace std;

int t;
int a, b, c;

signed main() {
	Hina;
	cin >> t;
	for (int i = 0; i < t ; i++) {
		cin >> a >> b >> c;
		cout << max(max(max(min(a, c), (a+b+c+2)/3), (c+1)/2), (a+1)/2) << '\n';
	}
	return 0;
}