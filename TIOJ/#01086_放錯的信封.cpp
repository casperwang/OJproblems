#include <iostream>
using namespace std;
long long int n, ans;
int main() {
  while (cin >> n) {
    if (!n) return 0;
    ans = 1;
    for (long long int i = 1; i <= n; i++) {
      ans = i * ans + !(i%2) - (i%2);
	}
	cout << ans << endl;
  }
  return 0;
}
