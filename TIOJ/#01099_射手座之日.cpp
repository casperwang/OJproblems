#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#define y1 y_1
using namespace std;

const int MAXN = 3001;
int n;
int x1, y1, z1;
int x2, y2, z2;
bitset <MAXN*MAXN> appr;

void DFS(int x, int y, int z) {
	if (appr[x2*MAXN+y2]) return;
	if (!appr[y*MAXN+x]) {
		appr[y*MAXN+x] = 1;
		DFS(y, x, z);
	}
	if (!appr[x*MAXN+z]) {
		appr[x*MAXN+z] = 1;
		DFS(x, z, y);
	}
	if (!appr[z*MAXN+y]) {
		appr[z*MAXN+y] = 1;
		DFS(z, y, x);
	}
	if (2*y-x+1 < 0 || 2*y-x+1 > n
	 || 2*x-y-1 < 0 || 2*x-y-1 > n) return;
	if (!appr[(2*y-x+1)*MAXN+(2*x-y-1)]) {
		appr[(2*y-x+1)*MAXN+(2*x-y-1)] = 1;
		DFS(2*y-x+1, 2*x-y-1, z);
	}
}

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	while (cin >> n) {
		if (!n) return 0;
		cin >> x1 >> y1 >> z1;
		cin >> x2 >> y2 >> z2;
		if (x1 + y1 + z1 != x2 + y2 + z2) {
			cout << "No\n";
			continue;
		}
		appr.reset();
		appr[x1*MAXN+y1] = 1;
		DFS(x1, y1, z1);
		if (appr[x2*MAXN+y2])
			cout << "Yes\n";
		else
			cout << "No\n";
	}
}