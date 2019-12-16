#include <cstdio>
#define MAXN 100
using namespace std;

int n, a, b;
int i, q;
int arr[MAXN];

signed main() {
	while (scanf("%d", &n) != EOF) {
		for (i = 0; i < n; i++)
			scanf("%d", &arr[i]);
		scanf("%d", &q);
		while (q--) {
			scanf("%d%d", &a, &b);
			i = arr[a], arr[a] = arr[b], arr[b] = i;
		}
		for (i = 0; i < n; i++)
			printf("%d ", arr[i]);
		printf("\n");
	}
}