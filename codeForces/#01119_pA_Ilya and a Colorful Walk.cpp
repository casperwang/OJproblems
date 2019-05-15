#include <bits/stdc++.h>
#define MAXN 300000
using namespace std;

int n, num[MAXN+5], a, b;

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> num[i];
  }
  a = 1;
  while (num[a] == num[n]) a++;
  b = n;
  while (num[b] == num[1]) b--;
  cout << max(n - a, b - 1) << endl;
  return 0;
} 
