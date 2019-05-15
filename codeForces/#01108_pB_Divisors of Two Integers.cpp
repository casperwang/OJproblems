#include <bits/stdc++.h>
using namespace std;

int n;
int num[130];
map <int, int> appr;

int GCD(int a, int b) {
  return (b == 0) ? a : GCD(b, a % b);
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> num[i];
    appr[num[i]]++;
  }
  sort(num+1, num+n+1);
  cout << num[n] << " ";
  for (int i = 1; i <= num[n]; i++) {
    if (num[n] % i == 0) appr[i]--;
  }
  int m = 0;
  for (auto i : appr) {
    if (i.second >= 1) m = max(m, i.first);
  }
  cout << m << endl;
  return 0;
}
