#include <bits/stdc++.h>
#define MAXN 100+5 
#define MOD 1000000
using namespace std;
int n, k, num[MAXN][MAXN];
int main() {
  for (int i = 0; i <= 100; i++) {
  	num[i][1] = 1;
  	for (int j = 2; j <= 100; j++) {
  	  for (int k = 0; k <= i; k++) {
  	  	num[i][j] += num[k][j-1];
  	  	num[i][j] %= MOD;
	  }
	}
  }
  while (cin >> n >> k) {
  	if (!n && !k) return 0;
  	cout << num[n][k] << endl;
  }
  return 0;
}
