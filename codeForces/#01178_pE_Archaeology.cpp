#include <bits/stdc++.h>
#define int long long
#define MAXN 2000000
using namespace std;
 
char a[MAXN+5];
int len;
int abc[3];
vector <char> ans;
 
signed main() {
  cin >> a;
  while (a[len]) len++;
  int i = 0;
  for (i = 0;len-2-i > i+1; i+=2) {
    abc[0] = abc[1] = abc[2] = 0;
    abc[a[i]-'a']++;
    abc[a[i+1]-'a']++;
    abc[a[len-1-i]-'a']++;
    abc[a[len-2-i]-'a']++;
    if (abc[0] >= 2) ans.push_back('a');
    else if (abc[1] >= 2) ans.push_back('b');
    else if (abc[2] >= 2) ans.push_back('c');
  }
  for (int j = 0; j < ans.size(); j++) {
    cout << ans[j];
  }
  if ((int)ans.size()*2 < len/2) cout << a[i];
  for (int j = (int)ans.size()-1; j >= 0; j--) {
    cout << ans[j];
  }
  cout << endl;
  return 0;
}
