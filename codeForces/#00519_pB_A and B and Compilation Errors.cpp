#include <bits/stdc++.h>
using namespace std;

int n, num, A, B;

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> num;
    A ^= num;
  }
  for (int i = 1; i < n; i++) {
    cin >> num;
    A ^= num;
    B ^= num;
  }
  cout << A << endl;
  for (int i = 2; i < n; i++) {
    cin >> num;
    B ^= num;
  }
  cout << B << endl;
  return 0;
}
