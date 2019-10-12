#include <bits/stdc++.h>
#define C 51
#define int long long
using namespace std;

int n, arr[6], now[6], k, ans = -1;
map <int, bool> appr;
queue <int> bfs;

int cal(int now[5]) {
  int t = 0;
  for (int i = 0; i < n; i++) {
    t = t*C + now[i];
  }
  return t;
}

void BFS(int s) {
  while (bfs.size()) {
    if (appr.size() > 500000) return;
    s = bfs.front();
    int m = s%(C*C*C*C);
    s /= C*C*C*C;
    for (int i = n-1; i >= 0; i--) {
      now[i] = s%C;
      s /= C;
    }
    bfs.pop();
    appr[cal(now)] = 1;
    int tmp, tmp2;
    for (int i = 0; i < n; i++) {
      if (now[i] == k) {
        ans = m;
        return;
      }
      if (now[i]) {
        tmp = now[i];
        now[i] = 0;
        if (!appr[cal(now)]) bfs.push(cal(now)*C*C*C*C+m+1), appr[cal(now)] = 1;
        for (int j = 0; j < n; j++) {
          if (i != j) {
            tmp2 = now[j];
            now[j] = min(tmp+tmp2, arr[j]);
            now[i] = tmp - (now[j]-tmp2);
            if (!appr[cal(now)]) bfs.push(cal(now)*C*C*C*C+m+1), appr[cal(now)] = 1;
            now[j] = tmp2;
          }
        }
        now[i] = tmp;
      } else {
        now[i] = arr[i];
        if (!appr[cal(now)]) bfs.push(cal(now)*C*C*C*C+m+1), appr[cal(now)] = 1;
        now[i] = 0;
      }
    }
  }
  return;
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> arr[i];
  cin >> k;
  bfs.push(0);
  BFS(0);
  cout << ans << endl;
  return 0;
}