#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/priority_queue.hpp>
#define pq __gnu_pbds::priority_queue<int,less<int>,binomial_heap_tag>
#define MAXN 100000
#define pb push_back
#define ss second
#define ff first
#define int long long
using namespace std;
using namespace __gnu_pbds;

int n, m, a, r, ans;
int c[MAXN+5], l[MAXN+5];
int sze[MAXN+5];
vector <int> path[MAXN+5];
pq t;

int DFS(int now, pq &s) {
	int sum = c[now];
	if (path[now].size()) 
		sum += DFS(path[now][0], s);
	s.push(c[now]);
	pq tmp;
	for (int i = 1; i < path[now].size(); i++) {
		tmp.clear();
		sum += DFS(path[now][i], tmp);
		s.join(tmp);
	}
	while (sum > m)
		sum -= s.top(), s.pop();
	ans = max(ans, l[now] * (int)s.size());
	return sum;
}

int find_sze(int now) {
	sze[now] = 1;
	for (int i : path[now])
		sze[now] += find_sze(i);
	return sze[now];
}

bool cmp(const int a, const int b) {
	return sze[a] > sze[b];
}

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a >> c[i] >> l[i];
		if (a) path[a].pb(i);
		else r = i;
	}
	find_sze(r);
	for (int i = 1; i <= n; i++)
		sort(path[i].begin(), path[i].end(), cmp);
	DFS(r, t);
	cout << ans << '\n';
}