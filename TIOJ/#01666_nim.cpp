#include <cstdio>
using namespace std;

int a, b;

signed main() {
	while (scanf("%d%d",&a,&b) != EOF) {
		if (a-b) printf("kelvin\n");
		else printf("yiping\n");
	}
}