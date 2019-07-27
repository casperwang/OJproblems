#include <bits/stdc++.h>
#define MAXN 10000
using namespace std;

int n, num[MAXN+5];

int main() {
  cin >> n;
  for (int i = 0; i < 2*n; i++) {
    cin >> num[i];
  }
  sort(num, num+2*n);
  if (num[0] == num[2*n-1]) cout << -1 << endl;
  else {
    for (int i = 0; i < 2*n; i++) {
      cout << num[i] << " ";
    }
    cout << endl;
  }
}
