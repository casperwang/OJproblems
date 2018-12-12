#include <iostream>
#include <cstdio>
#define N 1000000
using namespace std;

int n;
int arr[N+5];

int main() {
    scanf("%d",&n);
    for (int i = 1; i <= n; i++) {
        scanf("%d",&arr[i]);
        arr[i] += N/2;
    }
    printf("%d\n", n+1);
    printf("1 %d %d\n", n, N/2);
    for (int i = 1; i <= n; i++) {
        printf("2 %d %d\n", i, arr[i]-i);
    }
    return 0;
}
