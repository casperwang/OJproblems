#include <bits/stdc++.h>
#define Hina ios_base::sync_with_stdio(0),cin.tie(0)
#define ff first
#define ss second
#define MAXN 1000000
using namespace std;
 
int n;
long long ans;
int arr[MAXN+5];
int nxt[MAXN+5], lst[MAXN+5];
bool appr[MAXN+5];
priority_queue < pair<int, pair<int,int> >, vector< pair<int, pair<int,int> > >, greater< pair<int, pair<int,int> > > > now;

signed main() {
	Hina;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		nxt[i] = i<n?i+1:-1;
		lst[i] = i>1?i-1:-1;
		if (i > 1) {
			if (arr[i] > arr[i-1]) {
				now.push({arr[i], {i-1, i}});
			} else {
				now.push({arr[i-1], {i, i-1}});
			}
		}
	}
	pair<int, pair<int,int> > tmp;
	while (now.size()) {
		tmp = now.top();
		while (now.size() && (appr[tmp.ss.ff] || appr[tmp.ss.ss])) {
			now.pop();
			if (now.size()) tmp = now.top();
		}
		if (!now.size()) break;
		now.pop();
		ans += tmp.ff;
		appr[tmp.ss.ff] = 1;
		if (lst[tmp.ss.ff] == -1 || nxt[tmp.ss.ff] == -1) continue;
		nxt[lst[tmp.ss.ff]] = nxt[tmp.ss.ff];
		lst[nxt[tmp.ss.ff]] = lst[tmp.ss.ff];
		if (arr[lst[tmp.ss.ff]] > arr[nxt[tmp.ss.ff]]) {
			now.push({arr[lst[tmp.ss.ff]], {nxt[tmp.ss.ff], lst[tmp.ss.ff]}});
		} else {
			now.push({arr[nxt[tmp.ss.ff]], {lst[tmp.ss.ff], nxt[tmp.ss.ff]}});
		}
	}
	cout << ans << endl;
	return 0;
}