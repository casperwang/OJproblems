#include <bits/stdc++.h>
#define int long long
#define MAXN 200000
#define INF 2147483647 
using namespace std;

int t, n, k;

signed main() {
  cin >> t;
  int num[MAXN+5];
  int pos;
  for (int i = 0; i < t; i++) {
    cin >> n >> k;
    int m = INF;
    for (int j = 0; j < n; j++) {
      cin >> num[j];
    }
    for (int j = 0; j+k < n; j++) {
      if (num[j+k]-num[j] < m) {
        m = num[j+k]-num[k];
        pos = j;
      }
    }
    cout << (num[pos+k]+num[pos])/2 << endl;
  } 
  return 0;
}
