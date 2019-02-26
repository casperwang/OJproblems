#include <bits/stdc++.h>
#define MAXN 1000+5
using namespace std;

long long int n, m, s, ans;
long long int num[MAXN], appr[MAXN];

int main(){
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    num[i] = (i * i) % m;
    appr[i] = (n + m - i) / m;
  }
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= m; j++) {
      if ((num[i] + num[j]) % m == 0) ans += appr[i] * appr[j];
    }
  }
  cout << ans << endl;
	return 0;
}
