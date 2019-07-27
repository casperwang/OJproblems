#include <bits/stdc++.h>
#define MAXN 10000
using namespace std;

int num;
string str;

string itos(int n) {
  string s;
  while (n > 0) {
    s = (char)('0'+n%10) + s;
    n /= 10;
  }
  return s;
}

signed main() {
  for (int i = 0; i <= 4000; i++) {
    str = str + itos(i);
  } 
  cin >> num;
  cout << str[num-1];
  return 0;
}
