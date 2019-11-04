#include <bits/stdc++.h>
#define MAXN 200000
#define INF 1e18
#define pii pair<int,int>
#define pb push_back
#define ff first
#define ss second
#define int long long
using namespace std;

int n, k, ans;
int a, b, c, cnt, x, tmp;
vector < pair<int,int> > path[MAXN+5];
int sze[MAXN+5];
int vis[MAXN+5];
int pos[MAXN+5];
vector <int> dis;

void dfs(int now, int par, int c, int x, bool tf) {
	pos[now] = dis.size();
	if (c - x >= k) tf = 1, cnt++;
	else if (tf) cnt++;
	else if (par >= 0) dis.pb(max(c, dis[pos[par]]));
	else dis.pb(max(c, (int)0));
	for (auto i : path[now]) {
		if (i.ff != par && !vis[i.ff]) {
			dfs(i.ff, now, c+i.ss, min(x, c), tf);
		}
	}
}

void find_size(int now, int par) {
	sze[now] = 1;
	for (auto i : path[now]) {
		if (i.ff != par && !vis[i.ff]) {
			find_size(i.ff, now);
			sze[now] += sze[i.ff];
		}
	}
}

int find_cntr(int now, int par, int s) {
	for (auto i : path[now]) {
		if (i.ff != par && !vis[i.ff] && sze[i.ff] > s/2)
			return find_cntr(i.ff, now, s);
	}
	return now;
}

void find_ans(int now) {
	dis.clear();
	int t;
	cnt = 0;
	for (auto i : path[now]) {
		int p = dis.size();
		if (!vis[i.ff]) {
			tmp = cnt;
			dfs(i.ff, -1, i.ss, INF, 0);
			sort(dis.begin()+p, dis.end());
			for (int l = p; l < dis.size(); l++) {
				t = lower_bound(dis.begin()+l+1, dis.end(), k-dis[l])-dis.begin();
				ans -= dis.size()-t;
			}
			ans -= (cnt-tmp)*((cnt-tmp)-1)/2 + (cnt-tmp)*(dis.size()-p);
		}
	}
	dis.pb(0);
	sort(dis.begin(), dis.end());
	for (int l = 0; l < dis.size(); l++) {
		t = lower_bound(dis.begin()+l+1, dis.end(), k-dis[l])-dis.begin();
		ans += dis.size()-t;
	}
	ans += cnt*(cnt-1)/2 + cnt*dis.size();
}

void DFS(int now) {
	vis[now] = 1;
	find_ans(now);
	for (auto i : path[now]) {
		if (!vis[i.ff]) {
			find_size(i.ff, -1);
			a = find_cntr(i.ff, 0, sze[i.ff]);
			DFS(a);
		}
	}
}

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> n >> k;
	for (int i = 1; i < n; i++) {
		cin >> a >> b >> c;
		a--, b--;
		path[a].pb({b, c});
		path[b].pb({a, c});
	}
	find_size(0, -1);
	a = find_cntr(0, -1, n);
	DFS(a);
	cout << ans << '\n';
	return 0;
}