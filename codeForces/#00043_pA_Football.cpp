#include <bits/stdc++.h>
using namespace std;

int n, k;
string a, ans;
map <string, int> appr;

int main() {
  cin >> n;
  for (int i = 0;i < n; i++) {
    cin >> a;
    appr[a]++;
  }
  for(auto i : appr) {
    if (i.second > k) {
      k = i.second;
      ans = i.first;
    }
  }
  cout << ans << endl;
  return 0;
} 
