#include <bits/stdc++.h>
#define MAXN 200000
using namespace std;

int n, ans[MAXN+5];
string a, b;

int main() {
  cin >> n >> a >> b;
  a = ' '+a;
  b = ' '+b; 
  for (int i = n; i >= 0; i--) {
    ans[i] += a[i]-'a' + b[i]-'a';
    if (ans[i] >= 26) {
      ans[i-1] += 1;
      ans[i] -= 26;
    }
    if (ans[i] % 2) {
      if (ans[i+1] + 13 >= 26) ans[i]++;
      else ans[i+1] += 13;
    }
    ans[i] /= 2;
  }
  for (int i = 1; i <= n; i++) {
    cout << char(ans[i]+'a');
  }
  cout << endl;
  return 0;
} 
