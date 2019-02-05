#include <bits/stdc++.h>
#define MAXN 100000+5
using namespace std;

long long int n, k, a, b;
long long int num[MAXN];
long long int pow2[35];

long long int minimize(int L, int R) {
  if (lower_bound(num, num+k, L) == upper_bound(num, num+k, R)) return a;
  if (L == R) {
  	return b * (upper_bound(num, num+k, R) - lower_bound(num, num+k, L));
  }
  return min((upper_bound(num, num+k, R) - lower_bound(num, num+k, L)) * b * (R-L+1), 
  minimize(L, (L+R)/2) + minimize((L+R)/2+1, R));
}

int main() {
  pow2[0] = 1;
  for (int i = 1; i <= 30; i++) {
  	pow2[i] = pow2[i-1] * 2;
  }
  cin >> n >> k >> a >> b;
  for (int i = 0; i < k ; i++) {
  	cin >> num[i];
  }
  sort(num, num+k);
  num[k] = 2147483648;
  cout << minimize(1, pow2[n]) << endl;
  return 0;
}

