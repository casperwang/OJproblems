#include <bits/stdc++.h>
using namespace std;
int q;
long long int n, a, b;
int main(){
  cin >> q;
  for (int i = 0; i < q; i++) {
    cin >> n >> a >> b;
    long long int ans = min(n * a, n/2*b+(n%2)*a);
    cout << ans << endl;
  }
	return 0;
}
