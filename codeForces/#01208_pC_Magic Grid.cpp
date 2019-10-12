#include <bits/stdc++.h>
#define MAXN 1000
using namespace std;

int n, k;
int arr[MAXN+5][MAXN+5];

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  k = n/2;
  for (int i = 0; i < k*k; i++) {
    arr[i / k][i % k] = (i+1)*4;
    arr[i / k + k][i % k] = i*4+1;
    arr[i / k][i % k + k] = (i+1\*4+2;
    arr[i / k + k][i % k + k] = (i+1)*4+3;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << arr[i][j] << " ";
    }
    cout << endl;
  }
} 

