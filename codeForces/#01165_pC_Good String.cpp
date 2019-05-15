#include <bits/stdc++.h>
using namespace std;

int n;
string s;
vector <char> ans; 

int main() {
  cin >> n >> s;
  for (int i = 0; i < n; i++) {
    if (i+1 < n && s[i] != s[i+1]) {
      ans.push_back(s[i]);
      ans.push_back(s[i+1]);
      i++;
    }
  }
  cout << s.length()-ans.size() << '\n';
  for (int i = 0; i < ans.size(); i++) cout << ans[i];
  cout << endl;
  return 0;
}
