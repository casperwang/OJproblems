#include <iostream>
#include <cstdio>
#define N 100
using namespace std;
string a, b, ans[N+5][N+5];
int dp[N+5][N+5], n;
int main() {
  while (getline(cin,a)) {
  	if (a == "#") return 0;
  	getline(cin,b);
  	n++;
  	for (int i = 1; i <= a.length(); i++) {
  	  for (int j = 1; j <= b.length(); j++) {
  	  	dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
  	  	if (a[i-1] == b[j-1]) {
  	  	  dp[i][j] = dp[i-1][j-1]+1;
		}
	  }
	}
	printf("Case #%d: you can visit at most %d cities.\n",n,dp[a.length()][b.length()]);
  }
  return 0;
}
