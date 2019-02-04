#include <iostream>
#include <cstdio>
#include <map>
#include <algorithm>
#define N 100000
using namespace std;

long long int n, m, a[N+5], sum;
long long int necessity;
map <long long int, bool> appr;

int main() {
    scanf("%ld%ld",&n,&m);
    for (int i = 0; i < n; i++) {
        scanf("%ld",&a[i]);
        sum += a[i];
    }
    sort(a, a+n);
    reverse(a, a+n);
    appr[a[0]] = 1;
    for (int i = 1; i < n; i++) {
        if(a[i] >= a[i-1]) a[i] = a[i-1]-1;
        if(a[i] > 0) appr[a[i]] = 1;
    }
    necessity = n + (a[0] - appr.size());
    cout << sum-necessity << endl;
    return 0;
}
