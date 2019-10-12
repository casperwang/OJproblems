#include <bits/stdc++.h>
#define MAXN 200000
#define int long long
using namespace std;

int n, arr[MAXN+5];
int pow2[60];
int cal[60], m, k;

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  for (int i = 0, j = 1; j <= 1e18; i++, j*=2) {
  	pow2[i] = j;
  }
  cin >> n;
  for (int i = 0; i < n; i++) {
  	cin >> arr[i];
  	for (int j = 0; j < 60; j++) {
  	  if (arr[i] % pow2[j] == 0 && arr[i] / pow2[j] % 2) {
  	  	cal[j]++;
  	  }
  	}
  }
  for (int i = 0; i < 60; i++) {
  	if (cal[i] > m) {
  	  m = cal[i];
  	  k = i;
  	}
  }
  cout << n-m << endl;
  for (int i = 0; i < n; i++) {
  	if (arr[i] % pow2[k] || arr[i] / pow2[k] % 2 == 0) {
  	  cout << arr[i] << endl;
    }
  }
  return 0;
}