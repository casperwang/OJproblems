#include <bits/stdc++.h>
using namespace std;

long long int n, a, l, r;
string s;

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a >> s;
    l = 0;
    while(l < a && s[l] != '>') l++;
    r = a-1;
    while(r >= 0 && s[r] != '<') r--;
    cout << min(l, a-1-r) << endl;
  }
  return 0;
}
