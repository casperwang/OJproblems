#include <bits/stdc++.h>
#define Hina ios_base::sync_with_stdio(0),cin.tie(0)
using namespace std;
 
int a, b, c;

signed main() {
	Hina;
	cin >> a >> b >> c;
	for (int i = a; i != b+c; i+=c) {
		cout << i << " \n"[i==b];
	}
	return 0;
}