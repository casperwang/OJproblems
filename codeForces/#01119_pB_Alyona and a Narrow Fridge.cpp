#include <bits/stdc++.h>
#define MAXN 1000
using namespace std;

long long int n, h;
long long int num[MAXN+5];
long long int tmp[MAXN+5];
long long int k;

int main() {
  cin >> n >> h;
  for (int i = 1; i <= n; i++) {
    cin >> num[i];
  }
  for (int j = n; j >= 1; j--) {
    for (int i = 1; i <= j; i++) {
      tmp[i] = num[i];
    }
    sort(tmp+1, tmp+j+1);
    k = 0;
    for (int i = j; i >= 1; i-=2) {
      k += max(tmp[i], tmp[i-1]);
    }
    if (k <= h) {
      cout << j << endl;
      return 0;
    }
  }
  return 0;
} 
