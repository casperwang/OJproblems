//¿Oªw°ÝÃD: DP
#include <iostream>
#include <cstdio>
using namespace std;

long long n, m, ans;
long long dp[16][91];

int main(){
    cin >> n >> m;
    dp[0][0] = 1;
    for (long long i = 0; i <= m; i++) {
        for (long long j = 0; j <= min(i, n); j++) {
            dp[0][i+1] += dp[j][i];
            dp[j+1][i+1] += dp[j][i];
        }
    }
    for (int i = 0; i <= n; i++) {
        ans += dp[i][m];
    }
    printf("%lld", ans);
}
