#include <bits/stdc++.h>
using namespace std;

struct points{
  int i, x, y;
};

int n;
vector <points> pts;

bool cmp_x(const points a, const points b) {
  return a.x > b.x;
}
bool cmp_y1(const points a, const points b) {
  return a.y > b.y;
}
bool cmp_y2(const points a, const points b) {
  return a.y < b.y;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  pts.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> pts[i].x >> pts[i].y;
    pts[i].i = i+1;
  }
  sort(pts.begin(), pts.end(), cmp_x);
  for (int i = 0; i*(int)sqrt(n) <= n; i++) {
    if (i % 2)
      sort(pts.begin() + i*(int)sqrt(n), pts.begin() + min(n,(i+1)*(int)sqrt(n)), cmp_y1);
    else
      sort(pts.begin() + i*(int)sqrt(n), pts.begin() + min(n,(i+1)*(int)sqrt(n)), cmp_y2);
  }
  for (int i = 0; i < n; i++) {
    cout << pts[i].i << ' ';
  }
  cout << '\n';
}
