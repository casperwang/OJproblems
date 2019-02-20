#include <bits/stdc++.h>
#define MAXN 200000+5
using namespace std;
long long int n, m;
long long int max_sum, sum, d, now, k;
long long int num[MAXN];
int main(){
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> num[i];
    max_sum += num[i];
  }
  sort(num, num+n);
  now = n;
  if (max_sum < m) {
    cout << -1 << endl;
  } else {
    long long int l = 1, r = n+1, i;
    while (l < r) {
      i = (l+r)/2;
      sum = 0;
      k = 0;
      for (int j = 0; k < n; j++) {
        for (int p = 0; p < i && k < n; p++) {
          sum += max(num[n-k]-j, (long long)0);
          k++;
        }
      }
      if (sum == m) {
        l = i;
        break;
      } else if (sum < m) {
        l = i+1;
      } else {
        r = i;
      }
    }
    cout << l << endl;
  }
	return 0;
}
