#include <iostream>
#include <cstdio>
#define N 10000
using namespace std;
string a, b;
int dp[N+5][N+5], t;
int main() {
  cin >> t;
  getline(cin,a);
  for (int i = 0; i < t; i++) {
  	getline(cin,a);
  	b = "";
  	for (int i = 0; i < a.length(); i++) b = a[i] + b;
  	for (int i = 1; i <= a.length(); i++) {
  	  for (int j = 1; j <= b.length(); j++) {
  	  	dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
  	  	if (a[i-1] == b[j-1]) {
  	  	  dp[i][j] = dp[i-1][j-1]+1;
		}
	  }
	}
	printf("%d\n",dp[a.length()][b.length()]);
  }
  return 0;
}

