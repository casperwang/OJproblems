#include <iostream>
#include <vector>
#define N 50000
using namespace std;
int n, t, a, k;
vector <int> path[N+5];
int ans[N+5];
bool is_root[N+5];
void DFS(int now) {
  ans[now] = ++k;
  for (int i = 0; i < path[now].size(); i++) {
  	DFS(path[now][i]);
  }
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
  	cin >> t;
  	for (int j = 0; j < t; j++) {
  	  cin >> a;
  	  path[i].push_back(a);
  	  is_root[a] = 1;
	}
  }
  for (int i = 1; i <= n; i++) {
  	if (!is_root[i]) DFS(i);
  }
  for (int i = 1; i <= n; i++) {
  	cout << ans[i] << endl;
  }
  return 0;
}
