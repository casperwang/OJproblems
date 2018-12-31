#include <iostream>
#define N 998244353
using namespace std;
long long int n, ans = 1, t = 1;
int main() {
  cin >> n;
  for (int i = 1; i <= n ;i++) {
    t = t * i % N;
    ans = (ans * i - i + t)%N;
  }
  cout << ans << endl;
  return 0;
}
