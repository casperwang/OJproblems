#include <bits/stdc++.h>
#define MAXN 300
#define ff first
#define ss second
using namespace std;

string pre, in;
int pos[MAXN+5], p[MAXN+5];
pair<int,int> path[MAXN+5];

void DFS(int now, int l, int r) {
	//cout << in[pos[now]] << " ";
	if (pos[now] != l) {
		path[(int)pre[now]].ff = (int)pre[now+1];
		DFS(now+1, l, pos[now]-1);
	}
	if (pos[now] != r) {
		path[(int)pre[now]].ss = (int)pre[now+pos[now]-l+1];
		DFS(now+pos[now]-l+1, pos[now]+1, r);
	}
}

void print(int now) {
	if (path[now].ff) print(path[now].ff);
	if (path[now].ss) print(path[now].ss);
	cout << (char)now;
}

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	while (cin >> pre >> in) {
		for (int i = 0; i < in.size(); i++) {
			p[in[i]] = i;
			path[(int)in[i]].ff = path[(int)in[i]].ss = 0;
		}
		for (int i = 0; i < pre.size(); i++) {
			pos[i] = p[pre[i]];
		}
		DFS(0, 0, pre.size()-1);
		print((int)pre[0]);
		cout << '\n';
	}
}