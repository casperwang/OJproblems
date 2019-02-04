#include <bits/stdc++.h>
#define MAXN 1000+5
using namespace std;

string s;
int pos, cnt;
bool ans[MAXN];

int main() {
  cin >> s; 
  for (int i = 0; i < s.length(); i++) {
  	if (s[i] == 'a') pos = i;
  }
  for (int i = pos; i >= 0; i--) {
  	if (s[i] == 'a' && cnt % 2 == 0) {
  	  ans[i] = 1;
  	  cnt++;
	} else if (s[i] == 'b' && cnt % 2 == 1) {
	  ans[i] = 1;
	  cnt++;
	}
  }
  for (int i = 0; i < s.length(); i++) {
  	if (i) cout << " ";
  	cout << ans[i];
  }
  cout << endl;
  return 0;
}
