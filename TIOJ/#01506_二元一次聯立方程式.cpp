#include <bits/stdc++.h>
#define x b2
#define y b1
using namespace std;

double a1, a2, b1, b2;

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> a1 >> a2 >> b1 >> b2;
	x = (b2-b1)/(a1-a2);
	y = x*a1+b1;
	x = round((int)(x * 100))/100;
	y = round((int)(y * 100))/100;
	cout << fixed << setprecision(2) << x << '\n';
	cout << fixed << setprecision(2) << y << '\n';
}