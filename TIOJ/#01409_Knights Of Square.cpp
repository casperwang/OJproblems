#include <iostream>
#define N 1000000
using namespace std;

long long int n, num[N+5], maximum, sum;

int main() {
  while (cin >> n) {
    maximum = 0;
    sum = 0;
    for (int i = 0; i < n; i++) {
      cin >> num[i];
      sum += num[i];
      maximum = max(maximum, num[i]);
    }
    if (sum-maximum > maximum) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
  return 0;
}
