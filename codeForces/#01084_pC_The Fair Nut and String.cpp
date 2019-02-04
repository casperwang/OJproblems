#include <iostream>
#include <cstdio>
#define N 100000
#define NUM 1000000007
using namespace std;

string s;
long long int dp[N+5], now_i, now_sum;
long long int ans;

int main() {
    cin >> s;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'a') {
            dp[i] += now_sum+1;
            dp[i] %= NUM;
        } else if (s[i] == 'b') {
            for (; now_i < i; now_i++) {
                now_sum += dp[now_i];
                now_sum %= NUM;
            }
        }
    }
    for (int i = 0; i < s.length(); i++) {
        ans += dp[i];
        ans %= NUM;
    }
    printf("%d\n", ans);
    return 0;
}
