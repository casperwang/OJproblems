#include <cstdio>
#define MAXN 100
using namespace std;

int n, m, t;
int a, b;
char s[2];
bool tf;
bool arr[MAXN+2][MAXN+2];

signed main() {
	scanf("%d%d%d",&n,&m,&t);
	for (int i = 0; i < m; i++) {
		scanf("%d%s%d",&a,&s,&b);
		if (s[0] == '-') arr[a][b] = 1;
		else arr[b][a] = 1;
	}
	if (t == 0) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				printf("%d",arr[i][j]);
				if (j==n) printf("\n");
				else printf(" ");
			}
		}
	} else {
		for (int i = 1; i <= n; i++) {
			printf("%d ->",i);
			tf = 0;
			for (int j = 1; j <= n; j++)
				if (arr[i][j]) tf = 1, printf(" %d",j);
			if (!tf) printf(" 0\n");
			else printf("\n");
		}
	}
}