#include <bits/stdc++.h>
#define MAXN 4000
using namespace std;

int t, n, ans;
long long int a[MAXN+5], b[MAXN+5], c[MAXN+5], d[MAXN+5];
unordered_map <long long int, int> appr;

int main(){
  cin >> t;
  for (int i = 0; i < t; i++) {
    if (i) cout << endl;
    ans = 0;
    cin >> n;
    for (int j = 0; j < n; j++) {
      cin >> a[j] >> b[j] >> c[j] >> d[j];
    }
    appr.clear();
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < n; k++) {
        appr[c[j]+d[k]]++;
      }
    }
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < n; k++) {
        ans += appr[-a[j]-b[k]];
      }
    }
    cout << ans << endl;
  }
}
