#include <bits/stdc++.h>
#define MAXN 200000
using namespace std;

int n, num[MAXN+5], a, b;

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> num[i];
    if (num[i]) a = i;
    else b = i;
  }
  cout << min(a, b) << endl;
}
