#include <bits/stdc++.h>
using namespace std;

int n, num[100], a, b;

int main() {
  cin >> n;
  a = b = 2147483647;
  for (int i = 0;i < n; i++) {
    cin >> num[i];
    a = min(a, num[i]);
  }
  for (int i = 0;i < n; i++) {
    if (num[i] > a) b = min(b, num[i]);
  }
  if (b == 2147483647) cout << "NO" << endl;
  else cout << b << endl; 
  return 0;
}
