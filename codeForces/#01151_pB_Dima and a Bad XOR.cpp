#include <bits/stdc++.h>
#define MAXN 500
using namespace std;

int n, m;
int num[MAXN+5][MAXN+5];
int ans[MAXN+5], val;

void output() {
  cout << "TAK" << endl;
  for (int i = 1; i <= n; i++) {
    cout << ans[i] << " ";
    cout << endl;
  }
  return;
}

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> num[i][j];
    }
    ans[i] = 1;
    val ^= num[i][1];
  }
  if (!val) {
    for (int i = 1; i <= n; i++) {
      for (int j = 2; j <= m; j++) {
        if (num[i][j] != num[i][1]) {
          ans[i] = j;
          output();
          return 0;
        }
      }
    }
  } else {
    output();
    return 0;
  }
  cout << "NIE" << endl;
  return 0;
}
