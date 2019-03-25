#include <bits/stdc++.h>
#define MAXN 200000+5
using namespace std;

struct num{
  int a, b;
  num() {}
  num(int a, int b) : a(a), b(b) {}
};

class cmp{
  public:
    bool operator () (const num a, const num b) {
      if (a.a != b.a) return a.a > b.a;
      return a.b > b.b;
    }
};

int gcd(int a, int b) {
  return (b == 0) ? a : gcd(b, a % b);
}

int n, ans;
int a[MAXN], b[MAXN];
map <num, int, cmp> appr;

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  for (int i = 0; i < n; i++) {
    if (a[i] < 0) {
      a[i] *= -1;
      b[i] *= -1;
    }
    bool tf = 0;
    if (b[i] < 0) {
      b[i] *= -1;
      tf = 1;
    }
    if (a[i] == 0 && b[i] == 0) {
      ans++;
      continue;
    }
    if (a[i] == 0 && b[i]) continue;
    if (b[i] == 0 && a[i]) {
      appr[num(0, 0)]++;
      continue;
    }
    int t = gcd(a[i], b[i]);
    if (tf) b[i] *= -1;
    appr[num(a[i]/t, b[i]/t)]++;
  }
  int m = 0;
  for (auto i : appr) {
    m = max(m, i.second);
  }
  cout << m + ans << endl;
} 
