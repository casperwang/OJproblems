#include <bits/stdc++.h>
using namespace std;

int n;
int a[100], b[100];
bool tf;

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
    for (int j = 0; j < i; j++) {
      if (a[i] + b[i] == a[j] && a[i] == a[j] + b[j]) tf = 1;
    }
  }
  if (tf) cout << "YES" << endl;
  else cout << "NO" << endl; 
  return 0;
}
