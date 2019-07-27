#include <bits/stdc++.h>
#define MAXN 100000
using namespace std;

int n, num[MAXN+5];
bool tf = 0, p;

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> num[i];
    if (num[i] % 2) tf = 1;
    if (num[i] % 2 == 0) p = 1;
  }
  if (!tf || !p) {
    for (int i = 0; i < n; i++) {
      cout << num[i] << " "; 
    }
    cout << endl;
  } else {
    sort(num, num+n);
    for (int i = 0; i < n; i++) {
      cout << num[i] << " "; 
    }
    cout << endl;
  }
}
