#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#define int long long
#define pb push_back
using namespace std;
const int MAXN = 30000;

struct obj{
	int l, r, h;
	obj() {}
	obj(int _l, int _r, int _h) {
		l = _l, r = _r, h = _h;
	}
	const bool operator < (const obj &a) const {
		return l < a.l;
	}
} arr[MAXN+5];

class cmp{
public:
	bool operator() (const obj a, const obj b) {
		return a.h < b.h;
	}
};

int n, now, nowH;
vector <int> step;
priority_queue <obj, vector<obj>, cmp> nxt;

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	while (cin >> n) {
		if (!n) return 0;
		step.clear();
		now = nowH = 0;
		while(nxt.size()) nxt.pop();
		for (int i = 0; i < n; i++) {
			cin >> arr[i].l >> arr[i].h >> arr[i].r;
			step.pb(arr[i].l);
			step.pb(arr[i].r);
		}
		sort(arr, arr+n);
		sort(step.begin(), step.end());
		for (int i = 0; i < 2*n; i++) {
			while (now < n && arr[now].l == step[i])
				nxt.push(arr[now++]);
			while (nxt.size() && nxt.top().r <= step[i])
				nxt.pop();
			if (!nxt.size()) {
				if (!nowH) continue;
				cout << step[i] << " 0" << " \n"[i==2*n-1];
				nowH = 0;
			} else if (nowH != nxt.top().h) {
				cout << step[i] << " " << nxt.top().h << " ";
				nowH = nxt.top().h;
			}
		}
	}
 	return 0;
}