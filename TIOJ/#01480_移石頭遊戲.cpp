#include <bits/stdc++.h>
#define MAXN 2000
using namespace std;

int t, n, ans;
int x, y, cnt;
int arr[MAXN+5][MAXN+5];

signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> t;
  x = y = n;
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < i*2-1; j++)
      arr[x--][y] = cnt++;
    for (int j = 0; j < i*2-1; j++)
      arr[x][y++] = cnt++;
    for (int j = 0; j < i*2; j++)
      arr[x++][y] = cnt++;
    for (int j = 0; j < i*2; j++)
      arr[x][y--] = cnt++;
  }
  for (int i = 0; i < n*2-1; i++)
    arr[x--][y] = cnt++;
  while (t--) {
    ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> x >> y;
      ans ^= arr[x][y];
    }
    if (ans) cout << "A Win!\n";
    else cout << "B Win.\n";
  }
  return 0;
}