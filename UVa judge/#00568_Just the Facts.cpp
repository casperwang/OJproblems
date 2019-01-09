#include <iostream>
#include <cmath>
#define N 10000
#define INF 1000000000
using namespace std;
int n;
long long int table[N+5];
int main() {
 table[0] = 1;
  for (long long int i = 1; i <= N; i++) {
  	table[i] = table[i-1]*i;
  	while (table[i] % 10 == 0) table[i] /= 10;
  	table[i] %= INF;
  }
  while (cin >> n) {
  	for (int i = 1; i < 5-log10(n); i++) {
  	  cout << " ";
	}
	cout << n << " -> " << table[n]%10 << endl; 
  }
}
