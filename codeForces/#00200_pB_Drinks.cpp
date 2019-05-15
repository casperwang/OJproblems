#include <bits/stdc++.h>
using namespace std;

int n;
double a, ans;

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a;
    ans += a;
  }
  cout << ans / n << endl;
}
