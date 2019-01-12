#include <iostream>
#include <cmath>
using namespace std;
long long int t, n, a, l, k;
int main() {
  cin >> t;
  for (int i = 0; i < t; i++) {
    cin >> n;
    k = n;
    l = (int)log10(n+0.1)+1;
    a = 0;
    while (k > 0) {
      a += round(pow(k%10, l));
      k /= 10;
    }
    if (a == n) cout << "Armstrong" << endl;
    else cout << "Not Armstrong" << endl;
  }
}
