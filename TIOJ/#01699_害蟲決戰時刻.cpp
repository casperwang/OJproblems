#include <bits/stdc++.h>
#define MAXN 50000
#define int long long
#define ppp pair<pii,pii>
#define pii pair<int,int>
#define ff first
#define ss second
using namespace std;

int n, q, k;
int l, r;
int arr[MAXN+5], cpy[MAXN+5];
int idx[MAXN+5], cnt[MAXN+5];
int ans[MAXN+5];
ppp qry[MAXN+5];

bool cmp (const ppp a, const ppp b) {
	return a.ff.ss < b.ff.ss;
}

signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
  	cin >> arr[i];
  	cpy[i-1] = arr[i];
  }
  sort(cpy, cpy+n);
  for (int i = 1; i <= n; i++) {
  	arr[i] = lower_bound(cpy, cpy+n, arr[i])-cpy;
  }
  for (int i = 0; i < q; i++) {
  	cin >> qry[i].ff.ff >> qry[i].ff.ss >> qry[i].ss.ff;
  	qry[i].ss.ss = i;
  }
  sort(qry, qry+q);
  k = sqrt(q);
  for (int i = 0; i*i < q; i++) {
  	sort(qry+i*k, qry+min(q, (i+1)*k), cmp);
  }
  l = 1, r = k = 0;
  for (int i = 0; i < q; i++) {
  	while (r < qry[i].ff.ss) {
  		r++;
  		cnt[idx[arr[r]]]--;
  		cnt[++idx[arr[r]]]++;
  		if (k < idx[arr[r]])
  			k++;
  	}
  	while (l > qry[i].ff.ff) {
  		l--;
  		cnt[idx[arr[l]]]--;
  		cnt[++idx[arr[l]]]++;
  		if (k < idx[arr[l]])
  			k++;
  	}
  	while (l < qry[i].ff.ff) {
  		cnt[idx[arr[l]]]--;
  		if (!cnt[idx[arr[l]]] && k == idx[arr[l]])
  			k--;
  		cnt[--idx[arr[l]]]++;
  		l++;
  	}
  	while (r > qry[i].ff.ss) {
  		cnt[idx[arr[r]]]--;
  		if (!cnt[idx[arr[r]]] && k == idx[arr[r]])
  			k--;
  		cnt[--idx[arr[r]]]++;
  		r--;
  	}
  	if (k * qry[i].ss.ff >= qry[i].ff.ss-qry[i].ff.ff+1)
  		ans[qry[i].ss.ss] = 1;
  }
  for (int i = 0; i < q; i++)
  	if (ans[i]) cout << "Yes\n";
  	else cout << "No\n";
  return 0;
}