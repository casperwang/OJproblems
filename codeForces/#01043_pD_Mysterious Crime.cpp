#include <bits/stdc++.h>
#define MAXN 100000+5
using namespace std;

int n, m;
bool tf;
long long int ans, cnt;
int num[10][MAXN];
int pos[10][MAXN];

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) {
  	for (int j = 1; j <= n; j++) {
  	  scanf("%d", &num[i][j]);
  	  pos[i][num[i][j]] = j;
	}
  }
  cnt = 1;
  for (int i = 2; i <= n; i++) {
  	tf = 1;
  	for (int j = 1; j < m; j++) {
  	  if (num[j][pos[j][num[0][i-1]]+1] != num[0][i]) {
  	  	tf = 0;
  	  	break;
	  }
	}
	if (tf) {
	  cnt++;
	} else {
	  ans += cnt * (cnt + 1) / 2;
	  cnt = 1;
	}
  }
  ans += cnt * (cnt + 1) / 2;
  cout << ans << endl;
  return 0;
}
