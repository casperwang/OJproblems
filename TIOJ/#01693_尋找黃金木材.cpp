#include <bits/stdc++.h>
#define MAXN 100
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
using namespace std;

int n;
string ans;
pii pos[MAXN+5];
bool tf[MAXN*2+5];
int r[MAXN+5], h[MAXN+5];
int path[MAXN*2+5][MAXN*2+5];

bool intersect(int a, int b) {
	if (pos[a].ff-r[a] > pos[b].ff+r[b]) return 0;
	if (pos[b].ff-r[b] > pos[a].ff+r[a]) return 0;
	if (pos[a].ss-h[a] > pos[b].ss+h[b]) return 0;
	if (pos[b].ss-h[b] > pos[a].ss+h[a]) return 0;
	return 1;
}

void dfs(int now) {
	for (int i = 0; i < 2*n; i++) {
		if (!path[now][i]) continue;
		if (ans[i>>1] == '?')
			ans[i>>1] = i%2?'V':'H', dfs(i);
	}
}

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> pos[i].ff >> pos[i].ss >> r[i] >> h[i];
		h[i] = max(r[i], h[i]);
		ans += '?';
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) continue;
			if (intersect(i, j))
				path[i*2][j*2+1] = path[j*2][i*2+1] = 1;
			swap(r[j], h[j]);
			if (intersect(i, j))
				path[i*2][j*2] = path[j*2+1][i*2+1] = 1;
			swap(r[j], h[j]);
			swap(r[i], h[i]);
			if (intersect(i, j))
				path[i*2+1][j*2+1] = path[j*2][i*2] = 1;
			swap(r[j], h[j]);
			if (intersect(i, j))
				path[i*2+1][j*2] = path[j*2+1][i*2] = 1;
			swap(r[j], h[j]);
			swap(r[i], h[i]);
		}
	}
	for (int k = 0; k < n*2; k++) {
		for (int i = 0; i < n*2; i++) {
			for (int j = 0; j < n*2; j++) {
				path[i][j] |= path[i][k] && path[k][j];
			}
		}
	}
	for (int i = 0; i < 2*n; i++) {
		for (int j = 0; j < 2*n; j++) {
			//cout << path[i][j] << " \n"[j==2*n-1]; 
		}
	}
	for (int i = 0; i < n; i++) {
		if (path[i*2+1][i*2]) ans[i] = 'H', dfs(i*2);
		if (path[i*2][i*2+1]) ans[i] = 'V', dfs(i*2+1);
	}
	for (int i = 0; i < n; i++) {
		if (ans[i] == '?')
			ans[i] = 'H', dfs(i*2);
	}
	cout << ans << '\n';
}