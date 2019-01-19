#include <iostream>
#include <algorithm>
#define N 100000
using namespace std;
long long int n, num[N+5], ans;
int main() {
  while (cin >> n) {
  	ans = 0;
    for (int i = 0; i < n; i++) {
      cin >> num[i];
	}
	sort(num, num+n);
	for (int i = 0; i < n; i++) {
      if (num[i] > num[n/2]) ans += num[i] - num[n/2];
      else ans += num[n/2] - num[i];
	}
	cout << ans << endl;
  }
  return 0;
}
