#include <iostream>
#include <cstdio>
#define N 200000
using namespace std;

int n;
long double a[N+5];
long long int b[2*N+5];

int main() {
    scanf("%d",&n);
    for (int i = 0; i < n/2; i++) {
        cin >> a[i];
    }
    b[0] = 0;
    b[n-1] = a[0];
    for (int i = 1; i < n/2; i++) {
        if (b[n-i] - a[i]/2 < a[i]/2 - b[i-1]) {
            b[n-i-1] = b[n-i];
            b[i] = a[i] - b[n-i];
        } else {
            b[i] = b[i-1];
            b[n-i-1] = a[i] - b[i-1];
        }
    }
    for (int i = 0; i < n; i++) {
        if (i) cout << " ";
        cout << b[i];
    }
    cout << endl;
    return 0;
}
