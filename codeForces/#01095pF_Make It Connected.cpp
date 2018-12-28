#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#define N 200000
using namespace std;
struct road{
  long long int a, b, w;
  road(int a, int b, long long int w): a(a), b(b), w(w) {}
};
class cmp{
public:
  bool operator() (const road a, const road b) {
    return a.w > b.w;
  }
};
long long int n, m;
long long int minimum = 9999999999999, t;
long long int a, b, w;
long long int ans;
int ancestor[N+5];
long long int V[N+5];
priority_queue <road, vector<road>, cmp> path;
void finding(int a) {
  stack <int> family;
  family.push(a);
  while (family.top() != ancestor[family.top()]) {
    family.push(ancestor[family.top()]);
  }
  int tmp = family.top();
  while(family.size()) {
    ancestor[family.top()] = tmp;
    family.pop();
  }
  return;
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    ancestor[i] = i;
    cin >> V[i];
    if (V[i] < minimum) {
      minimum = V[i];
      t = i;
    }
  }
  for (int i = 1; i <= n; i++) {
    if (i != t) path.push(road(i, t, V[i]+V[t]));
  }
  for (int i = 0; i < m; i++) {
    cin >> a >> b >> w;
    path.push(road(a, b, w));
  }
  for (int i = 1; i < n; i++) {
    finding(path.top().a);
    finding(path.top().b);
    while (ancestor[path.top().a] == ancestor[path.top().b]) {
      path.pop();
      finding(path.top().a);
      finding(path.top().b);
    }
    ans += path.top().w;
    ancestor[ancestor[path.top().a]] = ancestor[path.top().b];
    path.pop();
  }
  cout << ans << endl;
}
