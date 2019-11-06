#include <bits/stdc++.h>
#define MAXN 3000
#define ff first
#define ss second
#define pii pair<int,int>
#define int long long
using namespace std;

int n, a, b;
double ans;
pii pts[MAXN+5];

double dis(int i, int j) {
  return sqrt((pts[i].ff-pts[j].ff)*(pts[i].ff-pts[j].ff)+(pts[i].ss-pts[j].ss)*(pts[i].ss-pts[j].ss));
}

signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  while (cin >> n) {
    if (!n) return 0;
    ans = 0;
    for (int i = 0; i < n; i++) {
      cin >> pts[i].ff >> pts[i].ss;
    }
    for (int i = 0; i < n; i++) {
      for (int j = i+1; j < n; j++) {
        if (dis(i, j) - ans > 0)
          ans = dis(i, j), a = i, b = j;
      }
    }
    cout << a << ' ' << b << '\n';
  }
  return 0;
}