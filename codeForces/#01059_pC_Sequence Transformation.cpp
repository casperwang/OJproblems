#include <bits/stdc++.h>
#define MAXN 10000+5
using namespace std;

int n, m, k = 1;
string a, b, c;

int main() {
  cin >> n;
  while (n > 3) {
    for (int i = 0; i < (n+1)/2; i++) {
      cout << k << " ";
    }
    n -= (n+1)/2;
    k *= 2;
  }
  if (n == 1) {
    cout << k << endl;
  } else if (n == 2) {
    cout << k << " " << k*2 << endl;
  } else if (n == 3) {
    cout << k << " " << k << " " << k*3 << endl;
  } 
} 
