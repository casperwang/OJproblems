#include <bits/stdc++.h>
#define MAXN 100000
using namespace std;

int n, q, a, b;
char op[10];
int dsu[MAXN+5];

int fnd(int a) {
	if (dsu[a]^a) dsu[a] = fnd(dsu[a]);
	return dsu[a];
}

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> n >> q;
	for (register int i = 1; i <= n; i++)
		dsu[i] = i;
	for (register int i = 0; i < q; i++) {
		cin >> op;
		if (op[0] == 'K') {
			cin >> a;
			cout << fnd(a) << '\n';
		} else {
			cin >> a >> b;
			dsu[fnd(b)] = fnd(a);
		}
	}
}
