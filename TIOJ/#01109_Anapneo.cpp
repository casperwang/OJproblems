#include <bits/stdc++.h>
#define MAXN 30000
using namespace std;

int n, k;
string arr[MAXN+5];

signed main() {
  while(cin >> n >> k) {
    for (int i = 1; i <= n; i++) {
      cin >> arr[i];
    }
    cout << arr[n-k+1] << endl;
  }
}