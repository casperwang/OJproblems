#include <bits/stdc++.h>
#define MAXN 100000
#define int long long
using namespace std;

int n, K;
int rec[MAXN*2+5];
pair <int, int> arr[MAXN+5];
map <int, int> appr;
priority_queue <int> p;

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> K;
  for (int i = 0; i < n; i++) {
    cin >> arr[i].first >> arr[i].second;
    appr[arr[i].first] = appr[arr[i].second] = 1;
  }
  int j = 0;
  for (auto i : appr) appr[i.first] = ++j;
  for (int i = 0; i < n; i++) {
    arr[i].first = appr[arr[i].first];
    arr[i].second = appr[arr[i].second];
  }
  sort(arr, arr+n);
  int l = 0, r = n, mid;
  int k, tmp, m;
  while (l < r) {

    mid = (l+r)/2;
    k = tmp = m = 0;
    while (p.size()) p.pop();

    for (int i = 1; i <= j; i++) {
      m += rec[i];
      while (k < n && arr[k].first == i) {
        p.push(arr[k].second);
        rec[arr[k++].second]++;
      }
      while (p.size() > mid+m) {
        rec[p.top()]--;
        p.pop(), tmp++;
      }
      rec[i] = 0;
    }
    if (tmp <= K) r = mid;
    else l = mid+1;
  }
  cout << l << endl;
} 