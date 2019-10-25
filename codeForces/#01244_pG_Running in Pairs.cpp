#include <bits/stdc++.h>
#define Hina ios_base::sync_with_stdio(0),cin.tie(0)
#define int long long
#define MAXN 1000000
using namespace std;

int n, k, s;
int A[MAXN+5];

signed main() {
	Hina;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) A[i] = i, s += max(i, n-i+1);
	if (k < n*(n+1)/2) {
		cout << -1 << endl;
	} else if (k >= s) {
		cout << s << endl;
		for (int i = 1; i <= n; i++) {
			cout << i << " \n"[i==n];
		}
		for (int i = n; i >= 1; i--) {
			cout << i << " \n"[i==0];
		}
	} else {
		int l = 1, r = n, tmp = k;
		while (k-(n+1)*n/2) {
			if (k-(n+1)*n/2 >= r-l) {
				swap(A[l], A[r]);
				k -= r-l;
				l++, r--;
			} else {
				r--;
			}
		}
		cout << tmp << endl;
		for (int i = 1; i <= n; i++) {
			cout << i << " \n"[i==n];
		}
		for (int i = 1; i <= n; i++) {
			cout << A[i] << " \n"[i==n];
		}
	}

	return 0;
}