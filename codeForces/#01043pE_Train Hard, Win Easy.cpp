#include <bits/stdc++.h>
#define MAXN 300000+5
using namespace std;

struct player {
  long long int x, y, i;
  player() {}
  player(long long int _x, long long int _y, long long int _i) : x(_x), y(_y), i(_i) {}
};

bool cmp(player a, player b) {
  return a.x-a.y < b.x-b.y;
}

int n, m;
int x, y, a, b;
player num[MAXN];
long long int pre_x[MAXN], pre_y[MAXN];
long long int ans[MAXN];

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &x, &y);
    num[i] = player(x, y, i);
  }
  for (int i = 0; i < m; i++) {
    scanf("%d%d", &a, &b);
    int tmp = min(num[a-1].x+num[b-1].y, num[a-1].y+num[b-1].x);
    ans[a-1] -= tmp;
    ans[b-1] -= tmp;
  }
  sort(num, num+n, cmp);
  pre_x[0] = num[0].x;
  pre_y[0] = num[0].y;
  for (int i = 1; i < n; i++) {
  	pre_x[i] = pre_x[i-1] + num[i].x;
  	pre_y[i] = pre_y[i-1] + num[i].y;
  }
  for (int i = n-1; i >= 0; i--) {
  	ans[num[i].i] += num[i].y * i + pre_x[i-1];
  	ans[num[i].i] += num[i].x * (n-i-1) + pre_y[n-1]-pre_y[i];
  }
  for (int i = 0; i < n; i++) {
  	if (i) printf(" ");
  	printf("%lld",ans[i]);
  }
  printf("\n");
  return 0;
}
