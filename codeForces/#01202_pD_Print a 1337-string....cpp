#include <bits/stdc++.h>
#define int long long
#define MAXN 100000
using namespace std;
 
int t, n, k, p;
int a[MAXN+5];
vector <int> ans;
 
signed main() {
  for (int i = 1; i < MAXN; i++) {
    a[i] = i*(i-1)/2;
  }
  cin >> t;
  for (int i = 0; i < t; i++) {
    ans.clear();
    cin >> n;
    while (n) {
      ans.push_back((upper_bound(a, a+MAXN, n)-a-1));
      n -= a[(upper_bound(a, a+MAXN, n)-a-1)];
    }
    k = ans[0];
    p = 0;
    while (p < ans.size()) {
      cout << 1;
      p++;
      while(k > ans[p]) {
        cout << 3;
        k--;
      }
    }
    while (k > 0) {
      cout << 3;
      k--;
    }
    cout << 7 << endl;
  }
}
