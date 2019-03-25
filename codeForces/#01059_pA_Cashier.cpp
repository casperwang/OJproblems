#include <bits/stdc++.h>
#define MAXN 10000+5
using namespace std;

int n, L, a;
int s, f, now;
int ans;

int main() {
  cin >> n >> L >> a;
  for (int i = 0; i < n; i++) {
    cin >> s >> f;
    ans += (s - now) / a; 
    now = s+f;
  }
  ans += (L - now) / a; 
  cout << ans << endl;
} 
