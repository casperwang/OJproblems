#include <cstdio>
#include <iostream>
#include <map>
#include <stack>
#define N 100000
using namespace std;
int n, l, r, ans;
string brackets[N+5];
map <int, int> match;
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
  	cin >> brackets[i];
  	l = 0;
  	r = 0;
  	for (int j = 0; j < brackets[i].length(); j++) {
  	  if (brackets[i][j] == '(') l++;
  	  else r++;
	}
	bool tf = 1;
	if (l > r) {
	  int now = 0;
	  for (int j = 0; j < brackets[i].length(); j++) {
	    if (brackets[i][j] == '(') now++;
	    else now--;
	    if (now < 0) tf = 0;
	  }
	  if (tf && match[-now] > 0) {
	  	match[-now]--;
	  	ans++;
	  } else if (tf) {
	  	match[now]++;
	  }
	} else {
	  int now = 0;
	  for (int j = brackets[i].length()-1; j >= 0; j--) {
	    if (brackets[i][j] == ')') now++;
	    else now--;
	    if (now < 0) tf = 0;
	  }
	  if (tf && match[now] > 0) {
	  	match[now]--;
	  	ans++;
	  } else if (tf) {
	  	match[-now]++;
	  }
	}
  }
  cout << ans << endl; 
  return 0;
}
