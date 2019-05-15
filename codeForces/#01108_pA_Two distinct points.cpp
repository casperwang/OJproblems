#include <bits/stdc++.h>
using namespace std;

int n;
long long int L1, L2, R1, R2;

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> L1 >> R1 >> L2 >> R2;
    if (R2 != L1) cout << L1 << " " << R2 << endl; 
    else cout << L1 << " " << L2 << endl; 
  }
  return 0;
}
