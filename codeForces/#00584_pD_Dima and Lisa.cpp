#include <bits/stdc++.h>
#define MAXN 1000000000
using namespace std;

long long int n;
bool tf;
bool not_prime[MAXN/100];
vector <int> primes;

int main() {
  cin >> n;
  for (int i = 2; i*100 < MAXN; i++) {
    if (!not_prime[i]) {
      primes.push_back(i);
    }
    for (int j = 0; j < primes.size() && i * primes[j] < MAXN/100; j++) {
      not_prime[i * primes[j]] = 1;
      if (i % primes[j] == 0) break;
    }
  }
  tf = 1;
  int c = n;
  for (int i = 0; primes[i] * primes[i] <= c; i++) {
    if (c % primes[i] == 0) {
      tf = 0;
      break;
    }
  }
  if (tf) {
    cout << 1 << endl;
    cout << c << endl;
    return 0;
  }
  
  tf = 1;
  c = n - 2;
  for (int i = 0; primes[i] * primes[i] <= c; i++) {
    if (c % primes[i] == 0) {
      tf = 0;
      break;
    }
  }
  if (tf) {
    cout << 2 << endl;
    cout << c << " " << 2 << endl;
    return 0;
  }
  
  int a, b = 3, a_now;
  a_now = 1;
  a = primes[1];
  bool tf = 1;
  while (tf) {
    tf = 0;
    c = n - a - 3;
    for (int i = 0; primes[i] * primes[i] <= c; i++) {
      if (c % primes[i] == 0) {
        a = primes[++a_now];
        tf = 1;
        break;
      }
    }
  }
  cout << 3 << endl;
  cout << a << " " << b << " " << c << endl;
  return 0;
}
