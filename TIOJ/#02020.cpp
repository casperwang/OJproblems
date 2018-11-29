//NPSC 2016 pE: DP
#include <iostream>
using namespace std;

int a, b;
int ans[100+5][100+5];

int main(){
    // initialize
    for (int i = 1; i <= 100; i++) {
        for (int j = 1; j <= 100; j++) {
            ans[i][j] = 2147483647;
        }
    }
    for (int i = 1; i <= 100; i++) {
        ans[i][1] = i;
        ans[1][i] = i;
        ans[i][i] = 1; // square
    }
    for (int i = 2; i <= 100; i++) {
        for (int j = 2; j <= 100; j++) {
            if (i != j) {
                for (int k = 1; k <= i/2; k++) {
                    ans[i][j] = min(ans[k][j] + ans[i-k][j], ans[i][j]);
                }
                for (int k = 1; k <= j/2; k++) {
                    ans[i][j] = min(ans[i][k] + ans[i][j-k], ans[i][j]);
                }
            }
        }
    }
    while (cin >> a >> b) {
        cout << ans[a][b] << endl;
    }
}
