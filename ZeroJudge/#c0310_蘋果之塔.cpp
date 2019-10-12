#include <bits/stdc++.h>
#define Hina ios_base::sync_with_stdio(0),cin.tie(0)
#define MAXN 50000
#define pb push_back
#define ff first
#define ss second
using namespace std;

int n, q;
int a, b, k;
pair <int, int> rge[MAXN+5];
vector <int> path[MAXN+5];

void DFS(int now) {
	rge[now].ff = ++k;
	for (int i = 0; i < path[now].size(); i++) {
		DFS(path[now][i]);
	}
	rge[now].ss = k;
}

class BIT{
public:
	int arr[MAXN+5];
	int lowbit(int a) {
		return a&-a;
	}
	void mdy(int now, int k) {
		arr[now] += k;
		if (now+lowbit(now)<=MAXN) mdy(now+lowbit(now),k);
	}
	int qry(int now) {
		return now?arr[now]+qry(now-lowbit(now)):0;
	}
} bit;

signed main() {
	Hina;
	cin >> n;
	for (int i = 1; i < n; i++) {
		cin >> a >> b;
		if (a > b) swap(a, b);
		path[a].pb(b);
	}
	DFS(1);
	for (int i = 1; i <= n; i++) bit.mdy(i,1);
	cin >> q;
	for (int i = 0; i < q; i++) {
		cin >> a >> b;
		if (a == 1) {
			if (bit.qry(rge[b].ff)-bit.qry(rge[b].ff-1)==1) bit.mdy(rge[b].ff,-1);
			else bit.mdy(rge[b].ff,1);
		} else {
			cout << bit.qry(rge[b].ss) - bit.qry(rge[b].ff-1) << endl;
		}
	}
	return 0;
}