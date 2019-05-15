#include <bits/stdc++.h>
#define MAXN 100
using namespace std;

int n;
int prime[25] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
int num[MAXN+5][25];

void print(int a) {
  if (a < 10) cout << "  " << a;
  else if (a < 100) cout << " " << a;
  else cout << a;
  return;
}

int main(){
  for (int i = 2; i <= MAXN; i++) {
    for (int j = 0; j < 25; j++) {
      int k = i;
      while (k % prime[j] == 0) {
        num[i][j]++;
        k /= prime[j];
      }
      num[i][j] += num[i-1][j];
    }
  }
  while (cin >> n) {
    if (!n) return 0;
    print(n);
    cout << "! =";
    for (int i = 0; i < 25 && prime[i] <= n; i++) {
      if (i % 15 == 0 && i) cout << endl << "      ";
      print(num[n][i]);
    }
    cout << endl;
  }
}
