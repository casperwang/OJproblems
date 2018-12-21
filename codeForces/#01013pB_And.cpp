#include <iostream>
#include <map>
#define N 1000000
using namespace std;
long long int n, x, a[N+5];
int ans;
map <int, int> appr;
int main() {
  cin >> n >> x;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    appr[a[i]]++;
    if (appr[a[i]] >= 2) {
      cout << 0 << endl;
      return 0;
    }
  }
  for (int i = 0; i < n; i++) {
    if ((a[i] & x) != a[i] && appr[a[i]&x]) {
      cout << 1 << endl;
      return 0;
    }
    if ((a[i] & x) != a[i]) a[i] &= x;
    else a[i] = -1;
  }
  for (int i = 0; i < n; i++) {
    if (a[i] >= 0) appr[a[i]]++;
    if (appr[a[i]] >= 2) {
      cout << 2 << endl;
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}
