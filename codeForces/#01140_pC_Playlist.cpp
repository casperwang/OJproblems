#include <bits/stdc++.h>
using namespace std;

struct num{
  int a, b;
  num() {}
  num(int a, int b) : a(a), b(b) {}
};

bool cmp(const num x, const num y) {
  if (x.b != y.b) return x.b > y.b;
  else return x.a < y.a;
}

long long int n, m, a, b;
long long int sum, ans;
multiset <int> pri;
vector <num> arr;

int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    arr.push_back(num(a, b));
  }
  sort(arr.begin(), arr.end(), cmp);
  for (int i = 0; i < n; i++) {
    if (pri.size() < m || arr[i].a > *pri.begin()) {
      pri.insert(arr[i].a);
      sum += arr[i].a;
    }
    if (pri.size() > m) {
      sum -= *pri.begin();
      pri.erase(pri.begin());
    } 
    ans = max(ans, sum * (long long int)arr[i].b);
  }
  cout << ans << endl;
  return 0;
}
