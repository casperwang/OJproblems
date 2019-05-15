#include <bits/stdc++.h>
#define MAXN 500
using namespace std;

int n, m, k;
bool A[MAXN+5][MAXN+5];
bool B[MAXN+5][MAXN+5];
int dif[MAXN+5][MAXN+5];
bool tf = 1;

int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> A[i][j]; 
    }
  } 
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> B[i][j];
      if (A[i][j] != B[i][j]) dif[i][j]++;
    }
  }
  for (int i = 0; i < n; i++) {
    k = 0;
    for (int j = 0; j < m; j++) {
      k += dif[i][j];
    }
    if (k % 2) tf = 0;
  }
  for (int j = 0; j < m; j++) {
    k = 0;
    for (int i = 0; i < n; i++) {
      k += dif[i][j];
    }
    if (k % 2) tf = 0;
  }
  if (tf) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
} 
