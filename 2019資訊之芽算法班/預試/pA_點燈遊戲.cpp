//pA: math
#include <iostream>
#include <cmath>
#define N 100000
using namespace std;

int n, ans;
bool bulb[N+5];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> bulb[i];
    }
    for (int i = n; i >= 1; i--) {
        if (!bulb[i]) {
            ans ++;
            for (int j = 1; j <= (int)sqrt(i); j++) {
                if (i%j == 0) {
                    bulb[j] = !bulb[j];
                    bulb[i/j] = !bulb[i/j];
                }
                if (j*j == i) bulb[j] = !bulb[j];
            }
        }
    }
    cout << ans << endl;
}
