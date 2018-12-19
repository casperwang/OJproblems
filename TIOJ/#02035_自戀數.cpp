#include <iostream>
using namespace std;
int base, n, len, cmp, tmp;
string num;
int main() {
  cin >> base >> num;
  len = num.length();
  for (int i = 0; i < len; i++) {
    n = n * base + (num[i]-'0');
    tmp = 1;
    for (int j = 0; j < len; j++) tmp *= (num[i]-'0');
    cmp += tmp;
  }
  if (cmp == n) cout << "YES" << endl;
  else cout << "NO" << endl;
  return 0;
}
