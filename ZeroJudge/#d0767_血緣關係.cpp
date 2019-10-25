#include <bits/stdc++.h>
#define Hina ios_base::sync_with_stdio(0),cin.tie(0)
#define MAXN 30000
#define L (int)__lg(MAXN)+1
#define ff first
#define ss second
#define pb push_back
using namespace std;
 
int n, q, k;
int a, b, t;
int ac[L+5][MAXN+5];
int dis[MAXN+5];
pair <int,int> arr[MAXN+5];
vector <int> path[MAXN+5];

void DFS(int now, int d) {
	arr[now].ff = k++;
	dis[now] = d;
	for (int i = 0; i < path[now].size(); i++) {
		DFS(path[now][i], d+1);
	}
	arr[now].ss = k++;
}

bool ancestor(int a, int b) {
	if (arr[a].ff <= arr[b].ff && arr[a].ss >= arr[b].ss) return 1;
	return 0;
}

int LCA(int a, int b) {
	if (ancestor(a, b)) return a;
	for (int i = L; i >= 0; i--) {
		if (!ancestor(ac[i][a], b)) a = ac[i][a];
	}
	return ac[0][a];
}

signed main() {
	Hina;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		while (cin >> a) {
			if (!a) break;
			ac[0][a] = i;
			path[i].pb(a);
		}
	}
	for (int i = 1; i <= n; i++) {
		if (!ac[0][i]) ac[0][i] = i, DFS(i, 0);
	}
	for (int j = 1; j <= L; j++) {
		for (int i = 1; i <= n; i++) {
			ac[j][i] = ac[j-1][ac[j-1][i]];
		}
	}
	for (int i = 0; i < q; i++) {
		cin >> a >> b;
		t = LCA(a, b);
		cout << t << " " << dis[a]+dis[b]-2*dis[t] << "\n";
	}
	return 0;
}