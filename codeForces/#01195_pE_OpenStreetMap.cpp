#include <bits/stdc++.h>
#define int long long
#define INF 2147483647
#define MAXN 3000
using namespace std;

int n, m, a, b;
int g, x, y, z;
int ans;
int num[MAXN+5][MAXN+5];
int dp[MAXN+5][MAXN+5];

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m >> a >> b;
  cin >> g >> x >> y >> z;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      num[i][j] = g;
      g = (g*x+y)%z;
    }
  }
  deque <pair<int, int>> arr;
  for (int i = 0; i < n; i++) {
    arr.clear();
    for (int j = 0; j < m; j++) {
      while (arr.size() && arr.back().second > num[i][j]) arr.pop_back();
      while (arr.size() && arr.front().first <= j-b) arr.pop_front();
      arr.push_back({j, num[i][j]});
      dp[i][j] = arr.front().second;
    }
  }
  for (int j = 0; j < m; j++) {
    arr.clear();
    for (int i = 0; i < n; i++) {
      while (arr.size() && arr.back().second > dp[i][j]) arr.pop_back();
      while (arr.size() && arr.front().first <= i-a) arr.pop_front();
      arr.push_back({i, dp[i][j]});
      dp[i][j] = arr.front().second;
    }
  }
  for (int i = a-1; i < n; i++) {
    for (int j = b-1; j < m; j++) {
      ans += dp[i][j];
    }
  }
  cout << ans << endl;
  return 0;
}
