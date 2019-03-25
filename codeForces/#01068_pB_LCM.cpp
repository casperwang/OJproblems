#include <bits/stdc++.h>
using namespace std;

long long int b, ans;

int main() {
  cin >> b;
  for (long long int i = 1; i * i <= b; i++) {
    if (b % i == 0) {
      if (i != b/i) ans += 2;
      else ans += 1;
    }
  } 
  cout << ans << endl;
  return 0;
}
