#include <bits/stdc++.h>
#define MAXN 1000
#define pii pair<int,int>
#define INF 1e9
#define ff first
#define ss second
using namespace std;

int t, n, s;
int arr[MAXN+5];
int ans[MAXN+5];
pii tmp;

int cnt(int i) {
	int tmp = 0;
	if (i > 1) tmp += abs(arr[i]-arr[i-1]);
	if (i < n) tmp += abs(arr[i]-arr[i+1]);
	return tmp;
}

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		for (int j = 1; j <= n; j++) cin >> arr[j];
		for (int j = 1; j <= n; j++) {
			tmp = pii(cnt(j), j);
			for (int k = 1; k <= n; k++) {
				s = cnt(k);
				swap(arr[j], arr[k]);
				tmp = min(tmp, pii(cnt(j)+cnt(k)-s, k));
				swap(arr[j], arr[k]);
			}
			cout << tmp.ss << " \n"[j==n];
		}
	}
}