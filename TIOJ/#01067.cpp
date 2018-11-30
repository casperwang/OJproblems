//NPSC 2005 pC: DP+math(mod)
#include <iostream>
#define M 10000
using namespace std;

int n, m, a, ans;
int dp[M+5];
int tmp[M+5];

int gcd(int a, int b)
    return (b==0)?a:gcd(b, a%b);

int main(){
    while (cin >> n >> m) {
        if (!n && !m) return 0;
        ans = 0;
        for (int i = 0; i <= m; i++) {
            dp[i] = 0;
            tmp[i] = -1;
        }
        for (int i = 0; i < n; i++) {
            cin >> a;
            for (int j = 0; j < m; j++) {
                if ((!j || dp[j]) && tmp[(j*10+a)%m] <= dp[j]) {
                    tmp[(j*10+a)%m] = dp[j]+1;
                }
            }
            for (int j = 0; j < m; j++) dp[j] = max(dp[j], tmp[j]);
            for (int j = 0; j < m; j++) tmp[j] = -1;
        }
        for (int i = 1; i < m; i++) {
            if (gcd(i, m) == 1) ans = max(ans, dp[i]);
        }
        if (m == 1) ans = max(ans, dp[0]); // exception
        cout << ans << endl;
    }
}
