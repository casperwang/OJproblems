#include <bits/stdc++.h>
#define MAXN 200000+5
using namespace std;

int n, ans;
int num[MAXN];

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> num[i];
  }
  sort(num, num+n);
  for (int i = 0; i < n; i++) {
    ans = max(ans, (int)(upper_bound(num+i, num+n, num[i]+5)-(num+i)));
  }
  cout << ans << endl;
} 
