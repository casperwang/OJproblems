#include <bits/stdc++.h>
#define MAXN 100000+5
using namespace std;

struct line{
  long long int a, b;
  line() {}
  line(long long int a, long long int b) : a(a), b(b) {}
};

double val(double L1_a, double L1_b, double L2_a, double L2_b) {
  return (L2_b - L1_b) / (L1_a - L2_a);
};

long long int n, m, p, h, t;
long long int dis[MAXN], a[MAXN], s[MAXN];
long long int dp[100+5][MAXN];
deque <line> arr;
deque <double> pos;

int main() {
  cin >> n >> m >> p;
  for (int i = 2; i <= n; i++) {
    cin >> dis[i];
    dis[i] += dis[i-1];
  }
  for (int i = 1; i <= m; i++) {
    cin >> h >> t;
    a[i] = t - dis[h];
    s[i] = s[i-1] + a[i];
  }
  sort(a+1, a+m+1);
  for (int j = 1; j <= m; j++) {
    dp[1][j] = j * a[j] - s[j];
  }
  for (int i = 2; i <= p; i++) {
    while (arr.size()) arr.pop_back();
    while (pos.size()) pos.pop_back();
    for (int j = 1; j <= m; j++) {
      line p = line(-j, dp[i-1][j] + s[j]);
      while (arr.size() > 1 && val(p.a, p.b, arr.back().a, arr.back().b) < pos.back()) {
        pos.pop_back();
        arr.pop_back();
      }
      if (arr.size()) pos.push_back(val(p.a, p.b, arr.back().a, arr.back().b));
      arr.push_back(p);
      while (pos.size() && pos.front() < a[j]) {
        pos.pop_front();
        arr.pop_front();
      }
      dp[i][j] = arr.front().a * a[j] + arr.front().b + j * a[j] - s[j];
    }
  }
  cout << dp[p][m] << endl;
  return 0;
}
