#include<bits/stdc++.h>
#define int long long
#define MAXN 200005
#define pb push_back
using namespace std;

int n, m, k;
int a, b, c;
priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> arr;
unordered_set <int> appr;
vector <pair<int, int>> ans;

signed main(){
  cin >> n >> m >> k;
  for (int i = 0; i < m; i++) {
    cin >> a >> b >> c;
    if (a > b) swap(a, b); 
    arr.push({c, a*MAXN+b});
  }
  while (ans.size() < k && arr.size()) {
    assert(arr.size() < MAXN*20);
    pair <int, int> tmp = arr.top();
    int a = tmp.second / MAXN, b = tmp.second % MAXN;
    int len = ans.size();
    while (arr.size() && appr.count(min(a, b)*MAXN + max(a, b))) {
      arr.pop();
      tmp = arr.top();
      a = tmp.second / MAXN, b = tmp.second % MAXN;
    }
    ans.pb({tmp.first, min(a, b)*MAXN + max(a, b)});
    appr.insert(min(a, b)*MAXN + max(a, b));
    arr.pop();
    for (int i = 0; i < len; i++) {
      int c = ans[i].second / MAXN, d = ans[i].second % MAXN;
      if (a == c && b != d) {
        arr.push({tmp.first + ans[i].first, min(b, d)*MAXN + max(b, d)});
      } else if (a == d && b != c) {
        arr.push({tmp.first + ans[i].first, min(b, c)*MAXN + max(b, c)});
      } else if (b == c && a != d) {
        arr.push({tmp.first + ans[i].first, min(a, d)*MAXN + max(a, d)});
      } else if (b == d && a != c) {
        arr.push({tmp.first + ans[i].first, min(a, c)*MAXN + max(a, c)});
      }
    }
  }
  cout << ans[ans.size()-1].first << endl;
}
