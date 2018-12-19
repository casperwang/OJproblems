#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#define N 10000
using namespace std;

int a, b;
bool not_prime[N+5];
bool make_prime[N+5];
vector <int> primes;

int main() {
  for (int i = 2; i <= 100; i++) {
    if (!not_prime[i]) {
      for (int j = i*i; j <= N; j+=i) {
        not_prime[j] = 1;
      }
    }
  }
  for (int i = 2; i <= N; i++) {
    if (!not_prime[i]) primes.push_back(i);
  }
  for (int i = 0; i <= N; i++) {
    int tmp = i*i+i+41;
    bool tf = 1;
    for (int j = 0; j < primes.size(); j++) {
      if (tmp % primes[j] == 0) tf = 0;
    }
    if ((i*i+i+41 <= N && !not_prime[i*i+i+41]) || (tf)) {
      make_prime[i] = 1;
    }
  }
  while (cin >> a >> b) {
    int n = 0;
    for (int i = a; i <= b; i++) {
      if (make_prime[i]) n++;
    }
    double ans = (double)((double)n * 10000 / (double)(b-a+1));
    ans = round(ans);
    ans /= 100;
    printf("%.2f\n", ans);
  }
  return 0;
}
