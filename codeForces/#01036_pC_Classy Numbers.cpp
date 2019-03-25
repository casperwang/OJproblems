#include <bits/stdc++.h>
using namespace std;

long long int t, l, r;
vector <long long int> num;

void DFS(long long int a, int now, int len) {
  if (len > 19) return;
  num.push_back(a);
  DFS(a*10, now, len+1);
  if (now < 3) for (long long int i = 1; i < 10; i++) DFS(a*10+i, now+1, len+1);
  return;
}

int main() {
  for (int i = 1; i < 10; i++) DFS(i, 1, 1);
  sort(num.begin(), num.end());
  cin >> t;
  for (int i = 0; i < t; i++) {
    cin >> l >> r;
    cout << upper_bound(num.begin(), num.end(), r) - lower_bound(num.begin(), num.end(), l) << endl;
  }
  return 0;
}
