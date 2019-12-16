#include <bits/stdc++.h>
#define MAXN 300000
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define int long long
using namespace std;

int n, m;
pii arr[MAXN+5];
vector <int> pos[MAXN+5];
int ans[MAXN+5];

class BIT{
public:
	int arr[MAXN+5];
	inline int lowbit(int a) {
		return a&-a;
	}
	void mdy(int now, int k) {
		if (now > n) return;
		arr[now] += k;
		mdy(now+lowbit(now), k);
	}
	int qry(int now) {
		return now?arr[now]+qry(now-lowbit(now)):0;
	}
} bit;

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> m >> n;
	for (int i = 1; i <= n; i++) 
		pos[0].pb(i);
	for (int i = 0; i < m; i++) {
		cin >> arr[i].ff >> arr[i].ss;
		bit.mdy(arr[i].ff, 1);
		bit.mdy(arr[i].ss+1, -1);
	}
	sort(arr, arr+m);
	int now = 0, nowR = 0;
	for (int i = 0; i < m; i++) {
		while (now < arr[i].ff) {
			while (nowR < m && arr[nowR].ff <= now)
				bit.mdy(arr[nowR++].ss+1, 1);
			for (int j = 0; j < pos[now].size(); j++) {
				if (now+pos[now][j] > n) continue;
				pos[now+pos[now][j]].pb(pos[now][j]);
				ans[pos[now][j]] += bit.qry(now+pos[now][j])-bit.qry(now);
			}
			pos[now++].clear();
		}
	}
	for (int i = 1; i <= n; i++)
		cout << ans[i] << '\n';
}