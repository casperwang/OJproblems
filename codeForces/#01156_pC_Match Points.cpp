#include <bits/stdc++.h>
#define MAXN 200000
#define pb push_back
#define int long long
using namespace std;

int n, z, k;
int arr[MAXN+5];
int l, r, mid;
bool tf;

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> z;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  sort(arr, arr+n);
  l = 0, r = n/2;
  while (l < r) {
    mid = (l+r+1)/2;
    k = mid;
    tf = 0;
    for (int i = 0; i < mid && k < n; i++) {
      while (k < n && arr[k]-arr[i] < z) k++;
      k++;
      if (i+1 == mid && k <= n) tf = 1;
    }
    if (!tf) r = mid-1;
    else l = mid;
  }
  cout << l << endl;
  return 0;
}