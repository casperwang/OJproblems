#include <bits/stdc++.h>
using namespace std;

int n, ans;
string a;

int main() {
  cin >> n >> a;
  for (int i = 0; i < n; i++) {
    if (a[i]%2 == 0) ans += i+1; 
  }
  cout << ans << endl;
  return 0;
}
