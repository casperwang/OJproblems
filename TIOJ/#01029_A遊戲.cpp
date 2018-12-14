#include <iostream>
#include <cstdio>
#define N 1000
using namespace std;

struct c {
    int f, s;
};

int n, num[N+5];
c ans[N+5][N+5]; // dp
int a, b;

int main() {
    scanf("%d",&n);
    for (int i = 0; i < n; i++) {
        scanf("%d",&num[i]);
        ans[i][i].f = num[i];
        ans[i][i].s = 0;
    }
    for (int i = 1; i < n; i++) {
        for (int j = i-1; j >= 0; j--) {
            if (ans[j+1][i].f < ans[j][i-1].f) {
                ans[j][i].f = ans[j+1][i].s + ans[j][j].f;
                ans[j][i].s = ans[j+1][i].f;
            } else {
                ans[j][i].f = ans[j][i-1].s + ans[i][i].f;
                ans[j][i].s = ans[j][i-1].f;
            }
        }
    }
    printf("%d %d\n", ans[0][n-1].f, ans[0][n-1].s);
    return 0;
}
