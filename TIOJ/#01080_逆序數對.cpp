#include <bits/stdc++.h>
#define Hina ios_base::sync_with_stdio(0),cin.tie(0)
#define int long long
#define MAXN 100000
using namespace std;

int n, ans, tmp, t;
int arr[MAXN+5], cpy[MAXN+5];

class BIT{
public:
	int arr[MAXN+5];
	int lowbit(int a) {
		return a&-a;
	}
	void init(int now) {
		for (int i = 1; i <= n; i++) arr[i] = 0;
	}
	void mdy(int now) {
		arr[now] += 1;
		if (now+lowbit(now) <= MAXN) mdy(now+lowbit(now));
	}
	int qry(int now) {
		return now?arr[now]+qry(now-lowbit(now)):0;
	}
} bit;

signed main() {
	Hina;
	while (cin >> n) {
		if (!n) return 0;
		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
			cpy[i] = arr[i];
		}
		sort(cpy+1, cpy+1+n);
		ans = 0;
		bit.init(n);
		for (int i = 1; i <= n; i++) {
			tmp = lower_bound(cpy+1, cpy+1+n, arr[i])-cpy;
			ans += bit.qry(n)-bit.qry(tmp);
			bit.mdy(tmp);
		}
		cout << "Case #" << ++t << ": ";
		cout << ans << endl;
	}
	return 0;
}