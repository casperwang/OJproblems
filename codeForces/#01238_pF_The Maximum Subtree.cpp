#include <bits/stdc++.h>
#define Hina ios_base::sync_with_stdio(0),cin.tie(0)
#define MAXN 300000
#define pb push_back
#define ff first
#define ss second
using namespace std;

int q, n;
int a, b;
int ans;
bool vis[MAXN+5];
int deg[MAXN+5];
vector <int> path[MAXN+5];

pair<int, int> DFS(int now) {
	vis[now] = 1;
	if (now != 1) deg[now]--;
	pair <int, int> tmp;
	int mmax1=0, mmax2=0;
	for (int i = 0; i < path[now].size(); i++) {
		if (vis[path[now][i]]) continue;
		tmp = DFS(path[now][i]);
		//cout << now << " " << path[now][i] << " " << tmp.ff << endl;
		ans = max(ans, tmp.ss+1);
		if (tmp.ff > mmax1) {
			mmax2 = mmax1;
			mmax1 = tmp.ff;
		} else if (tmp.ff > mmax2) {
			mmax2 = tmp.ff;
		}
	}
	ans = max(ans, deg[now]+max(0,mmax1-1)+max(0,mmax2-1)+1);
	return {deg[now]+max(0,mmax1-1)+1
		  , deg[now]+max(0,mmax1-1)+max(0,mmax2-1)+1};
}

signed main() {
	Hina;
	cin >> q;
	for (int i = 0; i < q; i++) {
		cin >> n;
		for (int i = 1; i <= n; i++) vis[i] = 0, deg[i] = 0;
		ans = 0;
		for (int j = 1; j <= n; j++) path[j].clear();
		for (int j = 1; j < n; j++) {
			cin >> a >> b;
			path[a].pb(b), deg[a]++;
			path[b].pb(a), deg[b]++;
		}
		DFS(1);
		cout << ans << endl;
	}
	return 0;
}