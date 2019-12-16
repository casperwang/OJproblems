#include <bits/stdc++.h>
#define MAXN 60
#define pb push_back
#define int long long
#define pii pair<int,int>
#define ff first
#define ss second
using namespace std;

int n, a, ans;

signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int SG[61] = {0,1,1,2,2,2,3,3,3,3,4,4,4,4,4,5,5,5,5,5,5,6,6,6,6,6,6,6,7,7,7,7,7,7,7,7,8,8,8,8,8,8,8,8,8,9,9,9,9,9,9,9,9,9,9,10,10,10,10,10,10};
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a;
    ans ^= SG[a];
  }
  if (ans) cout << "NO\n";
  else cout << "YES\n";
}