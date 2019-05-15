#include <bits/stdc++.h>
using namespace std;

long long int N, ans;

int main() {
  cin >> N;
  for (int i = 0; i <= sqrt(N); i++) {
    if (N % (i+1) == 0) {
      if (i && (i+1) * (N / i) == N) ans += i;
      if (i && i == N / i) continue;
      if (N/(i+1)-1 && (N/(i+1)) * (N / (N/(i+1)-1)) == N) ans += N/(i+1)-1;
    }
  }
  cout << ans << endl;
}
