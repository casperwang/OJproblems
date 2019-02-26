#include <bits/stdc++.h>
#define MAXN 1000+5
using namespace std;

struct pos{
  int a, b;
  pos() {}
  pos(int a, int b) : a(a), b(b) {}
};

int n, m, a, b, Ea, Eb;
int arr[MAXN][MAXN];
queue <pos> next_pos; 

int main() {
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    cin >> a >> b;
    arr[a][b] = -1;
  }
  cin >> a >> b >> Ea >> Eb;
  next_pos.push(pos(a, b));
  arr[a][b] = 1;
  while(next_pos.size() && !arr[Ea][Eb]) {
    a = next_pos.front().a;
    b = next_pos.front().b;
    if (a > 1 && arr[a-1][b] >= 0 && (!arr[a-1][b] || arr[a-1][b] > arr[a][b]+1)) {
      arr[a-1][b] = arr[a][b]+1;
      next_pos.push(pos(a-1, b));
    }
    if (a < n && arr[a+1][b] >= 0 && (!arr[a+1][b] || arr[a+1][b] > arr[a][b]+1)) {
      arr[a+1][b] = arr[a][b]+1;
      next_pos.push(pos(a+1, b));
    }
    if (b > 1 && arr[a][b-1] >= 0 && (!arr[a][b-1] || arr[a][b-1] > arr[a][b]+1)) {
      arr[a][b-1] = arr[a][b]+1;
      next_pos.push(pos(a, b-1));
    }
    if (b < n && arr[a][b+1] >= 0 && (!arr[a][b+1] || arr[a][b+1] > arr[a][b]+1)) {
      arr[a][b+1] = arr[a][b]+1;
      next_pos.push(pos(a, b+1));
    }
    next_pos.pop();
  }
  if (arr[Ea][Eb] <= 0) cout << -1 << endl;
  else cout << arr[Ea][Eb]-1 << endl;
  return 0;
}
