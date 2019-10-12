#include <bits/stdc++.h>
#define MAXN 200000
#define int long long
using namespace std;
  
int n, k;
int l, r, mid;
int a[MAXN+5], ans[MAXN+5];
int dsu[MAXN+5], appr[MAXN+5];
class BIT{
  public:
    int bit[MAXN+5];
    int lowbit(int a) {
      return a&-a;
    }
    void mdy(int now, int a) {
      bit[now] += a;
      if (now+lowbit(now) <= MAXN) mdy(now+lowbit(now), a);
    }
    int qry(int now) {
      return now ? bit[now]+qry(now-lowbit(now)) : 0;
    }
} p;

int finding(int now) {
  if (dsu[now] != now) dsu[now] = finding(dsu[now]);
  return dsu[now];
}
  
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    p.mdy(i, i);
    dsu[i] = i;
    appr[i] = 1;
  }
  dsu[n+1] = n+1;
  for (int i = n; i >= 1; i--) {
    l = 0, r = n, mid = (l+r)/2;
    k = p.qry(mid);
    while (l < r) {
      mid = (l+r)/2;
      k = p.qry(mid);
      if (k > a[i]) {
        r = mid-1;
      } else if (k < a[i]) {
        l = mid+1;
      } else {
        if (mid && !appr[mid]) r = mid-1;
        else break;
      }
    }
    mid = (l+r)/2+1;
    ans[i] = dsu[mid] = finding(dsu[mid]);
    appr[ans[i]] = 0;
    p.mdy(ans[i], -ans[i]);
    dsu[mid] = finding(dsu[dsu[mid]+1]);
  }
  for (int i = 1; i <= n; i++) {
    cout << ans[i] << " \n"[i==n];
  }
} 
