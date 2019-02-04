#include <iostream>
#include <stack>
using namespace std;
int n, l, r, c, d;
char tmp;
bool tf = 0;
stack <bool> s;
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> tmp;
    if (tmp == ')' && i == 0) tf = 1;
    if (tmp == '(' && i == n-1) tf = 1;
    if (tmp == '(') {
      if (s.size() == 1) c = i;
      s.push(1);
    } else if (s.size()) s.pop();
    else {
      if (!l) d = i;
      l++;
    }
  }
  if (tf && ((l == 2 && !s.size()) || (l == 0 && s.size() == 2))) cout << tf << endl;
  else if (l == 2 && !s.size()) cout << d/2+1 << endl;
  else if (l == 0 && s.size() == 2) cout << (n-c)/2+1 << endl;
  else cout << 0 << endl;
}
