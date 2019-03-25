#include <bits/stdc++.h>
#define MAXN 2000
using namespace std;

long long int n, m, a, b, k;
bool arr[MAXN][MAXN];

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    arr[i][i] = 1;
  }
  for (int i = 1; i <= m; i++) {
    cin >> a >> b;
    if (b > a) swap(a, b);
    arr[a][n+i] = 1;
    arr[b][n+i] = 1;
  }
  for (int i = 1;i <= n; i++) {
    k = 0;
    for (int j = 1; j <= n+m; j++) {
      if (arr[i][j]) k++;
    }
    cout << k << endl;
    for (int j = 1; j <= n+m; j++) {
      if (arr[i][j]) cout << i << " " << j << endl;
    }
  }
  return 0;
}
