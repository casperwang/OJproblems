#include <bits/stdc++.h>
#define MAXN 2000
using namespace std;

int n, a, b, k, ans;
int num[MAXN+5];

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> num[i];
    if (num[i] % 2) a++;
    else b++;
  }
  sort(num, num+n);
  if (a > b + 1) {
    k = a - b - 1;
    for (int i = 0; i < n && k; i++) {
      if (num[i] % 2) {
        ans += num[i];
        k--;
      }
    }
  } else if (b > a + 1) {
    k = b - a - 1;
    for (int i = 0; i < n && k; i++) {
      if (num[i] % 2 == 0) {
        ans += num[i];
        k--;
      }
    }
  }
  cout << ans << endl;
  return 0;
} 
