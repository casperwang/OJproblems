#include <bits/stdc++.h>
#define MAXN 67170
#define pb push_back
using namespace std;

int f(int a) {
	int tmp = 0;
	while (a) {
		tmp += (a%10)*(a%10);
		a /= 10;
	}
	return tmp;
}

vector <int> ans;
bool is_ans[MAXN+5];
bool vis[MAXN+5];

bool DFS(int now, int s) {
	if (vis[now]) return is_ans[now];
	vis[now] = 1;
	is_ans[now] = DFS(f(now), s);
	return is_ans[now];
}
signed main() {
	is_ans[1] = 1, ans.pb(1);
	for (int i = 2; i <= MAXN; i++) {
		if (!vis[i]) DFS(i, i);
		if (is_ans[i]) ans.pb(i);
	}
	cout << ans[9] << '\n';
	cout << ans[49] << '\n';
	cout << ans[99] << '\n';
	cout << ans[999] << '\n';
	cout << ans[9999] << '\n';
}