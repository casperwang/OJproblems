#include <cstdio>
using namespace std;

int a, b;

signed main() {
	scanf("%d",&a);
	b = 1;
	for (int i = 1; i <= a; i++)
		b *= i;
	printf("%d\n",b);
}