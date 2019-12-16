#include <cstdio>
#define MAXN 100
#define min(a, b) a < b ? a : b

int a, b;
unsigned short ans[MAXN+1][MAXN+1];

signed main(){
  for (register int i = 1; i <= MAXN; i++)
    for (register int j = 1; j <= MAXN; j++)
      ans[i][j] = 10000;
  for (register int i = 1; i <= MAXN; i++) {
      ans[i][i] = 1;
      ans[i][1] = ans[1][i] = i;
  }
  for (register int i = 2; i <= MAXN; i++) {
    for (register int j = 2; j <= MAXN; j++) {
      if (i ^ j) {
        for (register int k = 1; k <= i>>1; k++)
          ans[i][j] = min(ans[k][j] + ans[i-k][j], ans[i][j]);
        for (register int k = 1; k <= j>>1; k++)
          ans[i][j] = min(ans[i][k] + ans[i][j-k], ans[i][j]);
      }
    }
  }
  scanf("%d%d",&a,&b);
  printf("%d\n",ans[a][b]);
}