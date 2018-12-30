#include <iostream>
using namespace std;
long long int n, a, b;
string s;
int main() {
  cin >> n >> s;
  while (a < n && s[a] == s[0]) a++;
  while (b < n && s[n-1-b] == s[n-1]) b++;
  if (s[0] == s[n-1]) {
    cout << (a+1)*(b+1) % 998244353 << endl;
  } else {
    cout << a+b+1 << endl;
  }
}
