#include <bits/stdc++.h>
#define int long long
#define MAXN 1000
using namespace std;

int n;
int a_now[MAXN+5], b_now[MAXN+5];
int a_out[MAXN+5], b_out[MAXN+5];
vector <pair<pair<int, int>, pair<int, int>>> ans;

signed main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a_now[i];
    a_out[a_now[i]] = i;
    a_now[i] = i;
  }
  for (int i = 1; i <= n; i++) {
    cin >> b_now[i];
    b_out[b_now[i]] = i;
    b_now[i] = i;
  }
  for (int i = 1; i <= n; i++) {
    if (a_now[a_out[i]] != i || b_now[b_out[i]] != i) {
      ans.push_back({{a_now[a_out[i]], i}, {i, b_now[b_out[i]]}});
      for (int j = 1; j <= n; j++) {
        if (a_now[j] == i) a_now[j]  = a_now[a_out[i]];
      }
      a_now[a_out[i]] = i;
      for (int j = 1; j <= n; j++) {
        if (b_now[j] == i) b_now[j]  = b_now[b_out[i]];
      }
      b_now[b_out[i]] = i;
    }
  }
  cout << ans.size() << endl;
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i].first.first << " ";
    cout << ans[i].first.second << " ";
    cout << ans[i].second.first << " ";
    cout << ans[i].second.second << endl;
  }
  return 0;
}
