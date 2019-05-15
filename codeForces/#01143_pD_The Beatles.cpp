#include <bits/stdc++.h>
using namespace std;

long long int n, k, a, b;
long long int dis;
long long int max_ans, min_ans = 2147483641221;

long long int gcd(long long int a, long long int b) {
  return (b == 0) ? a : gcd(b, a % b);
}

long long int Abs(long long int n) {
  if (n < 0) return -n;
  else return n;
}

int main() {
  cin >> n >> k;
  cin >> a >> b;
  for (int i = 0; i < n; i++) {
    dis = Abs((i * k + 1 + b) - (1 - a)) % (n * k);
    max_ans = max(max_ans, n * k / gcd(n * k, dis));
    min_ans = min(min_ans, n * k / gcd(n * k, dis));
    dis = Abs((i * k + 1 - b) - (1 - a)) % (n * k);
    max_ans = max(max_ans, n * k / gcd(n * k, dis));
    min_ans = min(min_ans, n * k / gcd(n * k, dis));
    dis = Abs((i * k + 1 + b) - (1 + a)) % (n * k);
    max_ans = max(max_ans, n * k / gcd(n * k, dis));
    min_ans = min(min_ans, n * k / gcd(n * k, dis));
    dis = Abs((i * k + 1 - b) - (1 + a)) % (n * k);
    max_ans = max(max_ans, n * k / gcd(n * k, dis));
    min_ans = min(min_ans, n * k / gcd(n * k, dis));
  }
  cout << min_ans << " " << max_ans << endl;
}
