#include <bits/stdc++.h>
#define MAXN 20+5
using namespace std;
long long int n, tmp, i, j;
long long int appr[1000+5];
long long int num[MAXN][MAXN];
bool tf = 1;
int main(){
  cin >> n;
  for (int i = 0; i < n*n; i++) {
    cin >> tmp;
    appr[tmp]++;
  }
  for (int k = 1; k <= 1000; k++) {
    while (appr[k] >= 4) {
      appr[k] -= 4;
      num[i][j] = num[i][n-1-j] = num[n-1-i][j] = num[n-1-i][n-1-j] = k;
      j++;
      if (j >= n/2) {
        i++;
        j = 0;
      }
      if (i >= n/2) break;
    }
    if (i >= n/2) break;
  }
  if (n % 2) {
    i = n/2;
    j = 0;
    for (int k = 1; k <= 1000; k++) {
      while (appr[k] >= 2) {
        appr[k] -= 2;
        num[i][j] = num[i][n-1-j] = k;
        j++;
        if (j >= n/2) break;
      }
      if (j >= n/2) break;
    }
    i = 0;
    j = n/2;
    for (int k = 1; k <= 1000; k++) {
      while (appr[k] >= 2) {
        appr[k] -= 2;
        num[i][j] = num[n-1-i][j] = k;
        i++;
        if (i >= n/2) break;
      }
      if (i >= n/2) break;
    }
    for (int k = 1; k <= 1000; k++) {
      while (appr[k]) {
        num[n/2][n/2] = k;
        appr[k]--;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (num[i][j] == 0) tf = 0;
    }
  }
  if (tf) {
    cout << "YES" << endl;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (j) cout << " ";
        cout << num[i][j];
      }
      cout << endl;
    }
  } else {
    cout << "NO" << endl;
  }
    
	return 0;
}
