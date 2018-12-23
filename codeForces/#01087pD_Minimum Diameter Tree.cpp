#include <iostream>
#include <cstdio>
#include <vector>
#define N 100000
using namespace std;
vector <int> path[N+5];
int n, a, b;
double sum, m;
int main() {
  cin >> n >> sum;
  for (int i = 1; i < n; i++) {
    cin >> a >> b;
    path[a].push_back(b);
    path[b].push_back(a);
  }
  sum *= 2;
  for (int i = 1; i <= n; i++) {
    if (path[i].size() == 1) m++;
  }
  printf("%.7lf\n", sum/m);
  return 0;
}
