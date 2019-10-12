#include <bits/stdc++.h>
#define int long long
using namespace std;

int t, n;
int a[10];
string s;

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> t;
  for (int i = 0; i < t; i++) {
    cin >> n;
    if (n == 1) {
      cout << 1 << endl;
      continue;
    }
    s = "";
    for (int j = 2; j < 10; j++) {
      a[j] = 0;
      while (n % j == 0) {
        n /= j;
        a[j]++;
      }
    }
    while (a[3]>=2) s='9'+s, a[3]-=2;
    while (a[2]>=3) s='8'+s, a[2]-=3;
    while (a[7]) s='7'+s, a[7]--;
    while (a[2]&&a[3]) s='6'+s, a[3]--, a[2]--;
    while (a[5]) s='5'+s, a[5]--;
    while (a[2]>=2) s='4'+s, a[2]-=2;
    while (a[3]) s='3'+s, a[3]--;
    while (a[2]) s='2'+s, a[2]--;
    if (n == 1) cout << s << endl;
    else cout << -1 << endl;
  }
} 