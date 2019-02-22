#include <bits/stdc++.h>
using namespace std;

long long int n, q, a, s;
long long int pow_2[30+5];
bool tf;

int main(){
  cin >> n >> q;
  for (int i = 0; i < n; i++) {
    cin >> a;
    pow_2[(long long)log2(a)]++;
  }
  for (int i = 0; i < q; i++) {
    cin >> a;
    s = 0;
    tf = 1;
    for (int j = 30, k = 1073741824; k > 0; j--, k /= 2) {
      if (a >= k) {
        s += min((a/k), pow_2[j]);
        a -= min((a/k), pow_2[j]) * k;
      }
    }
    if (a) cout << -1 << endl;
    else cout << s << endl;
  }
	return 0;
}
