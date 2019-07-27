#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define MAXN 100000
using namespace std;

int n, a, sum;
map <int, int> appr;
int tf = 2;

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a;
    appr[a]++;
    sum += a;
  }
  if (n == 1 && a == 0) tf = 0;
  if (appr[0] >= 2) tf = 0;
  for (auto i : appr) {
    if (i.second >= 3) tf = 0;
    if (i.second == 2) tf--;
    if (i.second == 2 && appr[i.first-1] == 1) tf = 0;
  }
  if ((sum - n*(n-1)/2)%2 == 0) tf = 0;
  if (tf > 0) cout << "sjfnb" << endl;
  else cout << "cslnb" << endl;
  return 0;
}
