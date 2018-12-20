#include <iostream>
using namespace std;
long long int n, k, ans;
int main() {
  while (cin >> n) {
    k = 1;
    ans = 1;
    while (k != 0) {
      k = (k*10+1)%n;
      ans++;
    }
    cout << ans << endl;
  }
  return 0;
}
