#include <cstdio>
using namespace std;

int a, b;

signed main() {
	while (scanf("%d%d",&a,&b) != EOF) {
		for (int i = 1; i <= a; i++) {
			for (int j = 1; j <= b; j++) {
				printf("%d*%d=%d%c",i,j,i*j," \n"[j==b]);
			}
		}
	}
}