//路過的鴨duck: 0/1 knapsack
#include <iostream>
#include <cstdio>
using namespace std;

long long n, m, ans, a, b;
long long dp[200];

int main(){
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        for (int j = 100; j >= 0; j--) {
            if (!j || dp[j]) dp[j+a] = max(dp[j+a], dp[j] + b);
        }
    }
    for (int i = 1; i <= 100; i++) ans = max(ans, dp[i]);
    printf("%lld\n", ans);
}
