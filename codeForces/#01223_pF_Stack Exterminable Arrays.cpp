#include <bits/stdc++.h>
#define Hina ios_base::sync_with_stdio(0),cin.tie(0)
#define int long long
#define pb push_back
#define MAXN 300000
#define MOD 4398042316799
#define X 300009
using namespace std;

int q, n;
int arr[MAXN+5];
int num[MAXN+5];
int hsh[MAXN+5];
map <int, int> appr;

int DQ(int l, int r) {
	if (l == r) return 0;
	int mid = (l+r)/2, now = 1, tmp = 0;
	int cnt = DQ(l, mid)+DQ(mid+1, r);
	appr.clear();
	hsh[1] = 0;
	for (int i = mid; i >= l; i--) {
		if (num[now-1] == arr[i]) {
			now--;
			appr[hsh[now]]++;
		} else {
			num[now] = arr[i];
			now++;
			hsh[now] = now?(hsh[now-1]*X+arr[i])%MOD:arr[i];
			appr[hsh[now]]++;
		}
	}
	now = 1;
	for (int i = mid+1; i <= r; i++) {
		if (num[now-1] == arr[i]) {
			now--;
			tmp += appr[hsh[now]];
		} else {
			num[now] = arr[i];
			now++;
			hsh[now] = now?(hsh[now-1]*X+arr[i])%MOD:arr[i];
			tmp += appr[hsh[now]];
		}
	}
	return tmp+cnt;
}

signed main() {
	Hina;
	cin >> q;
	for (int i = 0; i < q; i++) {
		cin >> n;
		for (int j = 1; j <= n; j++) {
			cin >> arr[j];
		}
		cout << DQ(1, n) << "\n";
	}
	return 0;
}