//Combinations: math
#include <iostream>
#define N 100
using namespace std;

int n, m, ans;
int num[N+5];

int gcd(int a, int b) {
    return (b==0) ? a : gcd(b, a%b);
}

int main(){
	while (cin >> n >> m) {
        if (!n || !m) return 0;
        ans = 1;
        for (int i = 2; i <= n; i++) num[i] = i;
        for (int i = 2; i <= m; i++) num[i] = 0;
        for (int i = n-m; i >= 2; i--) {
            int k = i;
            for (int j = 2; k > 1; j++) {
                if (num[j] && gcd(num[j], k) > 1) {
                    int tmp = gcd(num[j], k);
                    num[j] /= tmp;
                    k /= tmp;
                }
            }
        }
        for (int i = 2; i <= n; i++) {
            if (num[i]) ans *= num[i];
        }
        cout << n << " things taken " << m << " at a time is " << ans << " exactly." << endl;
	}
}

