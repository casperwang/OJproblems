#include <bits/stdc++.h>
#define MAXN 200000
#define pb push_back
#define int long long
using namespace std;

int q, n, now;
bool tf;
pair <int, int> arr[MAXN+5];

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> q;
  for (int i = 0; i < q; i++) {
    cin >> n;
    for (int j = 0; j < n; j++) {
      cin >> arr[j].second >> arr[j].first;
    }
    sort(arr, arr+n);
    now = 0;
    tf = 1;
    for (int j = 0; j < n; j++) {
      now += arr[j].second;
      if (now > arr[j].first) tf = 0;
    }
    if (tf) cout << "schedulable" << endl;
    else cout <<  "unschedulable" << endl;
  }
  return 0;
}