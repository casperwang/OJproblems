#include <bits/stdc++.h>
#define int long long
#define MAXN 300000
using namespace std;

int n, m;
int l, r, mid;
int num[MAXN+5], tmp[MAXN+5];

signed main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> num[i];
  }
  l = 0, r = m;
  while (r > l) {
    mid = (l+r)/2;
    bool tf = 1;
    for (int i = 1; i <= n; i++) {
      tmp[i] = num[i];
      if (tmp[i-1]+m-tmp[i] <= mid) tmp[i] = tmp[i-1];
      else if (tmp[i-1]>tmp[i] && tmp[i-1]-tmp[i]<=mid) tmp[i] = tmp[i-1];
      else if (tmp[i]>=tmp[i-1]) continue; 
      else tf = 0;
    }
    if (tf) r = mid;
    else l = mid+1;
  }
  cout << r << endl;
  return 0;
}
