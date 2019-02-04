#include <iostream>
#include <vector>
#define N 200000
using namespace std;
int n, t1, t2;
vector <int> path[N+5];
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> t1 >> t2;
    path[i].push_back(t1);
    path[i].push_back(t2);
  }
  for (int i = 1; i <= n; i++) {
    if (path[path[i][0]][0] == path[i][1] || path[path[i][0]][1] == path[i][1]) {
      path[i][1] = -1;
    } else {
      path[i][0] = -1;
    }
  }
  int now = 1;
  for (int i = 0; i < n; i++) {
    if (i) cout << " ";
    cout << now;
    now = max(path[now][0],path[now][1]);
  }
  cout << endl;
}
