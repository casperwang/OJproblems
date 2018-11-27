//Divisibility: DP
#include <iostream>
#define N 10000
using namespace std;

int T, n, k;
int num[N+5];
bool dp[N+5][100+5];

int main(){
	cin >> T;
	dp[0][0] = 1;
	for (int Q = 0; Q < T; Q++) {
        cin >> n >> k;
        for (int i = 1;i <= n; i++) {
            for (int j = 0; j < k; j++) {
                dp[i][j] = 0;
            }
        }
        for (int i = 0; i < n; i++) {
            cin >> num[i];
            num[i] %= k;
            for (int j = 0; j < k; j++) {
                if (dp[i][j]) {
                    dp[i+1][(j+num[i]+k)%k] = 1;
                    dp[i+1][(j-num[i]+k)%k] = 1;
                }
            }
        }
        if (dp[n][0]) cout << "Divisible" << endl;
        else cout << "Not divisible" << endl;
	}
}

