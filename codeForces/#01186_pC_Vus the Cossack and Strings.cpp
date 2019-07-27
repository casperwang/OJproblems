#include <bits/stdc++.h>
#define int long long
using namespace std;

string a, b;
int ans, k, s;
queue <int> dif;

signed main() {
  cin >> a >> b;
  for (int i = 0; i < b.length(); i++) {
    if (a[i] != b[i]) s++;
  }
  if (s % 2 == 0) ans++;
  for (int i = 1; i < b.length(); i++) {
    if (a[i] != a[i-1]) k++;
    dif.push(a[i] != a[i-1]);
  }
  for (int i = b.length(); i < a.length(); i++) {
    if (a[i] != a[i-1]) k++;
    dif.push(a[i] != a[i-1]);
    if ((s+k)%2 == 0) ans++;
    s = s+k;
    if (dif.front()) k--;
    dif.pop();
  }
  cout << ans << endl; 
  return 0;
}
