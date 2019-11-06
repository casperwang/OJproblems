#include <bits/stdc++.h>
#define MAXN 100
#define INF 1e9
using namespace std;

int n;
int arr[MAXN+5];
bool tf = 1;

signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  sort(arr, arr+n);
  for (int i = 1; i < n; i++) {
    if (arr[i] != arr[i-1]+1) tf = 0;
  }
  cout << arr[0] << " " << arr[n-1] << " " << (tf?"yes":"no") << '\n';
  return 0;
}