#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#define psp pair<string,pii>
#define pii pair<int,int>
#define ff first
#define ss second
using namespace std;

const string ans = "123456780";
int t, a, k;
bool tf;
string now;
psp tmp;
queue <psp> nxt;
unordered_set <string> vis;

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> t;
	while (t--) {
		now = "", tf = 0;
		for (int i = 0; i < 9; i++) {
			cin >> a;
			if (!a) k = i;
			now = now + (char)('0'+a);
		}
		vis.clear();
		while (nxt.size()) nxt.pop();
		nxt.push(psp(now, pii(k, 0)));
		vis.insert(now);
		while (nxt.size()) {
			tmp = nxt.front(), nxt.pop();
			if (tmp.ff == ans) {tf = 1;break;}
			k = tmp.ss.ff;
			if (k-3 >= 0) {
				swap(tmp.ff[k], tmp.ff[k-3]);
				if (!vis.count(tmp.ff) && tmp.ss.ss < 20)
					vis.insert(tmp.ff), nxt.push(psp(tmp.ff, pii(k-3, tmp.ss.ss+1)));
				swap(tmp.ff[k], tmp.ff[k-3]);
			}
			if (k+3 <= 8) {
				swap(tmp.ff[k], tmp.ff[k+3]);
				if (!vis.count(tmp.ff) && tmp.ss.ss < 20)
					vis.insert(tmp.ff), nxt.push(psp(tmp.ff, pii(k+3, tmp.ss.ss+1)));
				swap(tmp.ff[k], tmp.ff[k+3]);
			}
			if (k % 3 != 0) {
				swap(tmp.ff[k], tmp.ff[k-1]);
				if (!vis.count(tmp.ff) && tmp.ss.ss < 20)
					vis.insert(tmp.ff), nxt.push(psp(tmp.ff, pii(k-1, tmp.ss.ss+1)));
				swap(tmp.ff[k], tmp.ff[k-1]);
			}
			if (k % 3 != 2) {
				swap(tmp.ff[k], tmp.ff[k+1]);
				if (!vis.count(tmp.ff) && tmp.ss.ss < 20)
					vis.insert(tmp.ff), nxt.push(psp(tmp.ff, pii(k+1, tmp.ss.ss+1)));
				swap(tmp.ff[k], tmp.ff[k+1]);
			}
		}
		if (tf) cout << "Easy\n";
		else cout << "Hard\n";
	}
	return 0;
}