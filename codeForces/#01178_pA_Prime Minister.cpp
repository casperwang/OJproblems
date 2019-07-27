#include <bits/stdc++.h>
#define int long long
#define MAXN 100
using namespace std;
 
int n, sum, k;
int num[MAXN+5];
vector <int> ans;
 
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> num[i];
    if (num[i]*2 <= num[1] || i == 1) {
      ans.push_back(i);
      k += num[i];
    }
    sum += num[i];
  }
  if (k > sum/2) {
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++) {
      cout << ans[i] << " \n"[i==ans.size()-1];
    }
  } else {
    cout << 0 << endl;
  }
  return 0;
}

