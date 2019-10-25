#include <bits/stdc++.h>
#define Hina ios_base::sync_with_stdio(0),cin.tie(0)
#define pb push_back
#define ff first
#define ss second
#define MAXN 200000
using namespace std;
 
int n, m, tmp, k, c, u;
int p[MAXN+5];
pair <int, int> s[MAXN+5];
int a[MAXN+5], b[MAXN+5];
set <pair<int,int> > appr;
 
signed main() {
	Hina;
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> p[i], appr.insert({p[i],i});
	for (int i = 0; i < m; i++) cin >> s[i].ff, s[i].ss = i;
	sort(s, s+m);
	for (int i = 0; i < m; i++) {
		tmp = s[i].ff, k = 0;
		bool tf = 1;
		while (appr.size() && (tmp > 1 || tf)) {
			if (tmp == 1) tf = 0;
			auto it = appr.lower_bound({tmp, 0});
			if (it != appr.end() && it->ff == tmp) {
				a[s[i].ss] = k;
				b[it->ss] = s[i].ss+1;
				c++, u += k;
				appr.erase(it);
				break;
			}
			tmp = (tmp+1)/2, k++;
		}
	}
	cout << c << " " << u << endl;
	for (int i = 0; i < m; i++) cout << a[i] << " \n"[i==m-1];
	for (int i = 0; i < n; i++) cout << b[i] << " \n"[i==n-1];
	return 0;
}