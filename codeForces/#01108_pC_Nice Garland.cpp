#include <bits/stdc++.h>
using namespace std;

int n, k, m;
string s, now, ans, p;

void f(string p) {
  now = s;
  k = 0;
  for (int i = 0; i < s.length(); i++) {
    if (now[i] != p[i%3]) k++;
    now[i] = p[i%3];
  }
  if (k < m) {
    m = k;
    ans = now;
  }
}

int main() {
  cin >> n >> s;
  m = n;
  f("RGB");
  f("RBG");
  f("BGR");
  f("BRG");
  f("GRB");
  f("GBR");
  cout << m << endl;
  cout << ans << endl;
  return 0;
}
