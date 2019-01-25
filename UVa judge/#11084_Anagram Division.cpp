#include <iostream>
#include <algorithm>
#include <cstdio>
#include <map>
using namespace std;
long long int t, d, ans, tmp, n;
string s, p;
int appr[12];
long long int q[11] = {1,1,2,6,24,120,720,5040,40320,362880,3628800};
void dfs(int now, long long int num, int p) {
  if (p == s.length()-1) {
  	if ((num*10+s[now]-'0') % d == 0) ans++;
  	return;
  }
  appr[now] = p+1;
  for (int i = 0; i < s.length(); i++) {
  	if (!appr[i]) dfs(i, num*10+s[now]-'0', p+1);
  }
  appr[now] = 0;
}
int main() {
  scanf("%lld",&t);
  for (int i = 0; i < t; i++) {
  	cin >> s >> d;
  	ans = 0;
  	n = tmp = 1;
  	sort(&s[0],&s[0]+s.length());
  	for (int i = 0; i < s.length(); i++) appr[i] = 0;
  	for (int i = 0; i < s.length(); i++) {
  	  dfs(i, 0, 0);
  	  if (i && s[i] == s[i-1]) {
  	  	tmp++;
	  } else {
	  	n *= q[tmp];
	  	tmp = 1;
	  }
    }
    n *= tmp;
    ans /= n;
    printf("%lld\n",ans);
  }
}
