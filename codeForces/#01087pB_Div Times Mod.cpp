#include <iostream>
using namespace std;
long long int n, k, ans;
int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    if (n % i == 0) {
      if (n / i < k) {
        ans = i * k + n / i;
        break;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
