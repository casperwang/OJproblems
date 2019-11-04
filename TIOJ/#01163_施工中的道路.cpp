#include <bits/stdc++.h>
#define Hina ios_base::sync_with_stdio(0), cin.tie(0)
#define MAXN 50000
#define int long long
#define ff first
#define ss second
#define pb push_back
using namespace std;

struct Edge{
	int a, b, c;
};

struct node{
	int l, r;
	vector < pair<pair<int,int>,int> > todo;
} tmp, t1, t2;

int n, m, q, mmax;
int a, b;
int dsu[MAXN+5];
int ans[MAXN+5];
Edge edges[MAXN+5];
queue < node > now;

int fnd(int now) {
	if (dsu[now] != now) dsu[now] = fnd(dsu[now]);
	return dsu[now];
}

void BFS(int len) {
	for (int i = 1; i <= n; i++) dsu[i] = i;
	int k = 0, mid, cnt = 0;
	for (int i = 0; i < len; i++) {
		tmp = now.front(), now.pop();
		if (!tmp.todo.size()) continue;
		if (tmp.l == tmp.r) {
			for (int j = 0; j < tmp.todo.size(); j++) {
				ans[tmp.todo[j].ss] = tmp.l;
			}
			continue;
		}
		mid = (tmp.l + tmp.r) / 2;
		t1.l = tmp.l, t1.r = mid  , t1.todo.clear();
		t2.l = mid+1, t2.r = tmp.r, t2.todo.clear();
		for (; edges[k].c <= mid && k < m; k++) {
			dsu[fnd(edges[k].a)] = fnd(edges[k].b);
		}
		for (int j = 0; j < tmp.todo.size(); j++) {
			if (fnd(tmp.todo[j].ff.ff) == fnd(tmp.todo[j].ff.ss)) 
				t1.todo.pb(tmp.todo[j]);
			else
				t2.todo.pb(tmp.todo[j]);
		}
		if (t1.todo.size())
			now.push(t1), cnt++;
		if (t2.todo.size())
			now.push(t2), cnt++;
	}
	if (cnt) BFS(cnt);
	return;
}

bool cmp(const Edge a, const Edge b) {
	return a.c < b.c;
}

signed main() {
	Hina;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) dsu[i] = i;
	for (int i = 0; i < m; i++) {
		cin >> edges[i].a >> edges[i].b >> edges[i].c;
		mmax = max(edges[i].c, mmax);
		dsu[fnd(edges[i].a)] = fnd(edges[i].b);
	}
	sort(edges, edges+m, cmp);
	cin >> q;
	for (int i = 0; i < q; i++) {
		cin >> a >> b;
		if (fnd(a) != fnd(b)) ans[i] = -1;
		else if (a == b) ans[i] = 0;
		else tmp.todo.pb({{a, b}, i});
	}
	tmp.l = 1, tmp.r = mmax;
	now.push(tmp), BFS(1);
	for (int i = 0; i < q; i++) {
		cout << ans[i] << "\n";
	}
}