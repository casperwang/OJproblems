//一元二次方程式: trivial
#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int m, a, b, c;

int main() {
    scanf("%d",&m);
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d",&a,&b,&c);
        if (b*b >= 4*a*c && floor(sqrt(b*b-4*a*c)) * floor(sqrt(b*b-4*a*c)) == b*b-4*a*c) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
