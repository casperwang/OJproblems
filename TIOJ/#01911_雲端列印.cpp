#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;

int n;
queue <int> nxt;
multiset <int> appr;

signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  while (cin >> n) {
    if (!n) return 0;
    if (n == -2 && appr.size()) {
      cout << *appr.rbegin() << " ";
      appr.erase(prev(appr.end()));
    } else if (n == -1 && appr.size()) {
      cout << *appr.begin() << " ";
      appr.erase(appr.begin());
    } else if (n > 0) {
      appr.insert(n);
    }
  }
}