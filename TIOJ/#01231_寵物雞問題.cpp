#include <bits/stdc++.h>
#define MAXN 100000
#define int long long
using namespace std;

int n, val, t, f;
int dsu[MAXN+5];
int k[MAXN+5];
int ans, m;
priority_queue < pair<int,int> > arr;
map <int, int> appr;

int Find(int a) {
	if (dsu[a] != a) dsu[a] = Find(dsu[a]);
	return dsu[a];
}

void Union(int a, int b) {
	dsu[Find(b)] = Find(a);
}
 
signed main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
  	cin >> val >> t;
  	arr.push({val, t});
  	appr[t]++;
  }
  cin >> f;
  m = f, appr[f]++;
  int j = 0, tmp = 0;
  for (auto i : appr) {
  	appr[i.first] = ++j;
  	k[j] = i.first - tmp;
  	tmp = i.first;
  }
  for (int i = 0; i <= j+2; i++) {
  	dsu[i] = i; 
  	if (i > appr[f]) dsu[i] = appr[f];
  }
  for (int i = 0; i < f && arr.size(); i++) {
  	while (arr.size() && !Find(appr[arr.top().second])) arr.pop();
  	if (!arr.size()) break;
  	k[Find(appr[arr.top().second])]--;
	if (!k[Find(appr[arr.top().second])])
	  Union(Find(appr[arr.top().second])-1, Find(appr[arr.top().second]));
	ans += arr.top().first;
	arr.pop();
	m--;
  }
  cout << ans-m << endl;
  return 0;
}