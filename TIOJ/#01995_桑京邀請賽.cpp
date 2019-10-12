#include "lib1995.h"
//#include <bits/stdc++.h>
using namespace std;

int n, m;
int SP[2500000+1];
int l[1000000], r[1000000];
bitset <1000000> tf;

signed main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) scanf("%d%d", &l[i], &r[i]);
	for (int i = 1; i <= n; i++) scanf("%d", &SP[i]);
	for (int i = 0; i < m; i++) {
		if (l[i] == r[i]) l[i] = SP[l[i]], tf[i] = 1;
	}
	for (int k = 2, j = 1; k <= n; k *= 2, j++) {
		for (int i = 1; i <= n-k+1; i++) SP[i] = max(SP[i],SP[i+k/2]);
		for (int i = 0; i < m; i++) {
			if (r[i]-l[i]+1<k*2 && !tf[i]) {
				l[i] = max(SP[l[i]], SP[r[i]-(1<<j)+1]);
				tf[i] = 1;
			}
		}
	}
	for (int i = 0; i < m; i++) printf("%d\n",l[i]);
	return 0;
}