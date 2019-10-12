#include <bits/stdc++.h>
#define MAXN 1000
#define int long long
using namespace std;

int n, m, k;
int arr[MAXN+5];
stack <int> sta1, sta2;
map <int, bool> appr;

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  k = 1;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    while (k < arr[i]) {
      sta1.push(k);
      k++;
    }
    if (k == arr[i]) {
      k++;
      continue;
    }
    if (k > arr[i]) {
      while (sta1.size() && sta1.top() != arr[i] && sta2.size() < m && !appr[arr[i]]) {
        appr[sta1.top()] = 1;
        sta2.push(sta1.top());
        sta1.pop();
      }
      if (appr[arr[i]]) {
        while (sta2.size() && sta2.top() != arr[i]) {
          sta1.push(sta2.top());
          sta2.pop();
        }
        if (sta2.top() == arr[i]) sta2.pop();
      } else if (sta1.top() == arr[i]) {
        sta1.pop();
      } else {
        cout << "no" << endl;
        return 0;
      }
    }
  }
  cout << "yes" << endl;
  return 0;
}