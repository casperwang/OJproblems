#include <bits/stdc++.h>
#define MAXN 200000
#define pb push_back
using namespace std;

int n, now, ans, s, m;
int x, y;
int a[MAXN+5];
vector <int> pts[MAXN+5];
bool vis[MAXN+5];
vector <int> path[MAXN+5];
bool not_prime[MAXN+5];
vector <int> primes;
vector <int> appr;

void DFS(int now, int len, int p) {
  if (len > s) s = len, m = now;
  vis[now] = 1;
  appr.pb(now);
  for (int i = 0; i < path[now].size(); i++) {
    if (!vis[path[now][i]] && a[path[now][i]]%p == 0) {
      DFS(path[now][i], len+1, p);
    }
  }
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i < n; i++) {
    cin >> x >> y;
    path[x].pb(y);
    path[y].pb(x);
  }

  // make prime list
  not_prime[1] = 1;
  for (int i = 2; i <= MAXN; i++) {
    if (!not_prime[i]) primes.pb(i);
    for (int j = 0; j < primes.size() && primes[j]*i <= MAXN; j++) {
      not_prime[primes[j]*i] = 1;
      if (i % primes[j] == 0) break;
    }
  }

  // create a set of pts for each prime
  int tmp = 0;
  for (int i = 1; i <= n; i++) {
    tmp = a[i];
    for (int j = 2; j*j <= a[i]; j++) {
      if (tmp%j == 0 && !not_prime[j]) pts[j].pb(i);
      while (tmp%j == 0) tmp /= j;
    }
    if (tmp && !not_prime[tmp]) pts[tmp].pb(i);
  }

  for (int i = 2; i < MAXN; i++) {
    if (pts[i].size()) {
      for (int j = 0; j < pts[i].size(); j++) {
        vis[pts[i][j]] = 0;
      }
      for (int j = 0; j < pts[i].size(); j++) {
        if (!vis[pts[i][j]]) {
          s = 0;
          DFS(pts[i][j], 1, i);
          for (int k = 0; k < appr.size(); k++) {
            vis[appr[k]] = 0;
          }
          appr.clear();
          DFS(m, 1, i);
          appr.clear();
          ans = max(ans, s);
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}