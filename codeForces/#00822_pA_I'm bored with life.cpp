#include <bits/stdc++.h>
using namespace std;

int a, b;
long long int ans = 1;

int main() {
  cin >> a >> b;
  for (int i = 1; i <= min(a, b); i++) {
    ans *= i;
  }
  cout << ans << endl;
  return 0;
} 
