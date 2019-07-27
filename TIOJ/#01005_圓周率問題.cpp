#include <bits/stdc++.h>
#define MAXN 50
using namespace std;

int n, num[MAXN+5], k;

int GCD(int a, int b) {
  return (b) ? GCD(b, a % b) : a;
}

int main() {
  while (cin >> n) {
    if (!n) return 0;
    for (int i = 0; i < n; i++) {
      cin >> num[i];
    }
    k = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (i == j) continue;
        if (GCD(num[i], num[j]) == 1) k++;
      }
    }
    if (k == 0) {
      cout << "No estimate for this data set." << endl;
    } else {
      printf("%.6lf\n", (double)sqrt((double)n*(n-1)*6/k));
    }
  }
}
