#include <bits/stdc++.h>
#define int long long
using namespace std;

int x;
map <int, int> h;
int g(int z) {
	if (z <= 2) return z*z-1;
	return 2;
}
int f(int x) {
	if (x > h[x]) return f(x-1)-h[x];
	else if (x < h[x]) return f(g(x))-g(x);
	else return 1;
}

signed main() {
	for (int y = -1000; y < 2; y++) h[y] = -1;
	for (int y = 2; y <= 90000; y++) h[y] = 2+h[y-1]-h[y-2];
	cin >> x;
	cout << f(x) << '\n';
}