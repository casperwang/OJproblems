#include <bits/stdc++.h>
#define MAXN 30000
using namespace std;

string s, a;
map <string, int> appr;
map <string, string> name;
vector <string> ans;

int main(){
  while (cin >> s) {
    if (s == "#") break;
    a = s;
    for (int i = 0; i < s.length(); i++) {
      if (s[i] >= 'A' && s[i] <= 'Z') s[i] = s[i] - 'A' + 'a';
    }
    sort(&s[0], &s[0]+s.length());
    name[s] = a;
    appr[s]++;
  }
  for (auto i : appr) {
    if (i.second == 1) ans.push_back(name[i.first]); 
  }
  sort(ans.begin(), ans.end());
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << endl;
  }
}
