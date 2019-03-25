#include <bits/stdc++.h>
using namespace std;

int n, k, a, ans;
int num[100];

int main() {
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> a;
    num[a % k]++;
  }
  ans += num[0]/2;
  for (int i = 1; i <= k/2; i++) {
    if (i != k-i) ans += min(num[i], num[k-i]);
  }
  if (k % 2 == 0) ans += num[k/2]/2;
  cout << ans * 2 << endl;
} 
