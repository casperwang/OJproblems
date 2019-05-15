#include <bits/stdc++.h>
#define int long long
using namespace std;

int n;
vector <int> ans;
int po[40];
bool tf = 1, d;

signed main() {
  cin >> n;
  d = n % 2;
  for (int i = 0, k = 1; i < 40; i++, k *= 2) {
    po[i] = k;
  }
  for (int i = 0, k = 1; i < 20; i++, k *= 2) {
    if ((n & k) == 0) {
      tf = 0;
      for (int j = 0, p = 1; j < i; j++, p*=2) {
        if (n & p) {
          n -= p;
        } else {
          n += p;
        }
      }
      ans.push_back(i);
    }
  }
  if (d) cout << ans.size()*2 << endl;
  else cout << ans.size()*2-1 << endl;
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }
  return 0;
}
