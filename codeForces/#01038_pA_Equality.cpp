#include <bits/stdc++.h>
using namespace std;

int n, k, ABC[26], ans = 100000;
string s;

int main() {
  cin >> n >> k;
  cin >> s;
  for (int i = 0; i < n; i++) {
    ABC[s[i]-'A']++;
  }
  for (int i = 0; i < k; i++) {
    ans = min(ans, ABC[i]);
  } 
  cout << ans * k << endl;
}
