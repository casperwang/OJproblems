#include<bits/stdc++.h>
#define int long long
#define MAXN 20
#define INF 18446744073709551615
using namespace std;

int n, m, k, tmp;
int arr[MAXN+5][MAXN+5];
map <int, int> appr[MAXN+5];

void DFS(int x, int y, int p) {
  if (x+y == (n+m-1)/2) {
    appr[x][p]++;
    //cout << x << ", " << y << ": " << p << endl;
    return;
  }
  if (x+1 < n) DFS(x+1, y, p^arr[x+1][y]);
  if (y+1 < m) DFS(x, y+1, p^arr[x][y+1]);
  return;
}

int reDFS(int x, int y, int p) {
  if (x+y == (n+m-1)/2) {
    return appr[x][k^p^arr[x][y]];
  }
  int ans = 0;
  if (x > 0) ans += reDFS(x-1, y, p^arr[x-1][y]);
  if (y > 0) ans += reDFS(x, y-1, p^arr[x][y-1]);
  return ans;
}

signed main(){
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> arr[i][j];
    }
  }
  DFS(0, 0, arr[0][0]);
  cout << reDFS(n-1, m-1, arr[n-1][m-1]) << endl;
}
