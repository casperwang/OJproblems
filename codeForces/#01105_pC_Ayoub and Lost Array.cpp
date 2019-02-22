#include <bits/stdc++.h>
#define MAXN 300005
#define MOD 1000000007
using namespace std;

long long int n, l, r;
long long int dp[3][MAXN], num[3][3];

int main(){
  cin >> n >> l >> r;
  dp[0][0] =   r   / 3 - (l-1) / 3;
  dp[1][0] = (r+2) / 3 - (l+1) / 3; 
  dp[2][0] = (r+1) / 3 -   l   / 3;
  for (int i = 1;i < n; i++) {
    dp[0][i] = ( (dp[0][i-1] * dp[0][0]) + (dp[1][i-1] * dp[2][0]) + (dp[2][i-1] * dp[1][0]) ) % MOD;
    dp[1][i] = ( (dp[0][i-1] * dp[1][0]) + (dp[1][i-1] * dp[0][0]) + (dp[2][i-1] * dp[2][0]) ) % MOD;
    dp[2][i] = ( (dp[0][i-1] * dp[2][0]) + (dp[1][i-1] * dp[1][0]) + (dp[2][i-1] * dp[0][0]) ) % MOD;
  }
  cout << dp[0][n-1] << endl;
	return 0;
}
