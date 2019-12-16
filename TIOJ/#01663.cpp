#include <cstdio>
using namespace std;

int t, a, b;

signed main() {
	while (scanf("%d%d%d",&t,&a,&b) != EOF) {
		if (t == 1) printf("%d\n",a+b);
		if (t == 2) printf("%d\n",a-b);
		if (t == 3) printf("%d\n",a*b);
		if (t == 4) printf("%d\n",a%b);
	}
}