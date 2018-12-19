#include <iostream>
using namespace std;

long long int ans[50+5];
int n;

int main() {
  ans[0] = 1;
  ans[1] = 2;
  for (int i = 2; i <= 50; i++) ans[i] = ans[i-1] + ans[i-2];
  while (cin >> n) cout << ans[n] << endl;
  return 0;
}
