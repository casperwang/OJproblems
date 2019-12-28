#include <bits/stdc++.h>
#define MAXN 100000
#define pii pair<int,int>
#define ppi pair<pii,int>
#define ff first
#define ss second
using namespace std;
 
int n, q, l, r, t, k;
int arr[MAXN+5];
ppi qry[MAXN+5];
int ans[MAXN+5];
int pos[MAXN+5];
int cnt[MAXN+5];

bool cmp (const ppi a, const ppi b) {
  return a.ff.ss < b.ff.ss;
}

signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> q;
  for (int i = 1; i <= n; i++)
    cin >> arr[i];
  for (int i = 0; i < q; i++) {
    cin >> qry[i].ff.ff >> qry[i].ff.ss;
    qry[i].ss = i;
  }
  k = sqrt(q);
  sort(qry, qry+q);
  for (int i = 0; i < q; i += k) {
    sort(qry+i, qry+min(q, (int)(i+k)), cmp);
  }
  l = 1, r = 0;
  for (int i = 0; i < q; i++) {
    while (l > qry[i].ff.ff) {
      pos[cnt[arr[--l]]]--;
      pos[++cnt[arr[l]]]++;
      t = max(t, cnt[arr[l]]);
    }
    while (r < qry[i].ff.ss) {
      pos[cnt[arr[++r]]]--;
      pos[++cnt[arr[r]]]++;
      t = max(t, cnt[arr[r]]);
    }
    while (l < qry[i].ff.ff) {
      pos[cnt[arr[l]]--]--;
      if(!pos[cnt[arr[l]]+1] && t == cnt[arr[l]]+1) t--;
      pos[cnt[arr[l++]]]++;
    }
    while (r > qry[i].ff.ss) {
      pos[cnt[arr[r]]--]--;
      if(!pos[cnt[arr[r]]+1] && t == cnt[arr[r]]+1) t--;
      pos[cnt[arr[r--]]]++;
    }
    ans[qry[i].ss] = t;
  }
  for (int i = 0; i < q; i++)
    cout << ans[i] << "\n";
}