#include <bits/stdc++.h>
#define MAXN 100000
#define INF 256
#define int long long
using namespace std;

int n, p[MAXN+5], num[64], b[64];
int path[INF][INF];
int graph[INF][INF];
vector <int> tmp;
vector <int> a;
bool tf = 1;

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  num[0] = 1;
  for (int j = 1; j <= 60; j++) {
    num[j] = num[j-1] * 2; 
  }
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> p[i];
    for (int j = 0; j <= 60; j++) {
      if (p[i] & num[j]) b[j]++;
    }
    if (p[i]) a.push_back(p[i]);
  }
  n = a.size();
  for (int i = 0; i <= 60; i++) {
    if (b[i] >= 3) tf = 0;
  }
  if (!tf) {
    cout << 3 << endl;
    return 0;
  } else if (n) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (i != j && (a[i] & a[j])) path[i][j] = graph[i][j] = 1;
        else path[i][j] = graph[i][j] = INF;
      }
    }
    int ans = INF*INF; 
    for (int k = 0; k < n; k++) {
      for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
          if (k != i && k != j && i != j)
            ans = min(ans, path[i][j] + graph[i][k] + graph[k][j]);
        }
      }
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          path[i][j] = min(path[i][j], path[i][k] + path[k][j]);
        }
      }
    }
    if (ans >= INF) cout << -1 << endl;
    else cout << ans << endl;
  } else {
    cout << -1 << endl;
  }
} 

