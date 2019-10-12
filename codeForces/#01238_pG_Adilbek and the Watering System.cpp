#include <bits/stdc++.h>
#define MAXN 500000
#define Hina ios_base::sync_with_stdio(0),cin.tie(0)
#define int long long
using namespace std;

struct man{
	int t, a, b;
	man():t(0){}
	man(int t, int a, int b): t(t), a(a), b(b) {}
};

bool cmp(const man a, const man b) {
	return a.t < b.t;
}

int q, ans, sum;
int n, m, c0, c;
int tmp, rt, k;
bool tf = 1;
man arr[MAXN+5];
map <int, int> now;

signed main() {
	Hina;
	cin >> q;
	for (int i = 0; i < q; i++) {
		cin >> n >> m >> c >> c0;
		for (int i = 0; i < n; i++) {
			cin >> arr[i].t >> arr[i].a >> arr[i].b;
		}
		sort(arr, arr+n, cmp);
		arr[n] = man(m, 0, 0);
		now.clear(), ans = 0, tf = 1;
		now[0] = c0, sum = c0;
		rt = 0;
		for (int i = 0; i <= n; i++) {
			k = arr[i].t - rt;
			auto it = now.begin();
			while (now.size() && k) {
				it = now.begin();
				tmp = min(k, it->second);
				ans += tmp * it->first;
				now[it->first] -= tmp;
				k -= tmp;
				sum -= tmp;
				if (!now[it->first]) now.erase(now.begin());
			}
			now[arr[i].b] += arr[i].a;
			sum += arr[i].a;
			it = now.end();
			while (now.size() && sum > c) {
				it = now.end();
				it--;
				tmp = min(sum-c, now[it->first]);
				now[it->first] -= tmp;
				sum -= tmp;
				if (now[it->first] == 0) now.erase(it);
			}
			rt = arr[i].t;
			if (k) {
				cout << -1 << endl;
				tf = 0;
				break;
			}
		}
		if (tf) cout << ans << endl;
	}
	return 0;
}