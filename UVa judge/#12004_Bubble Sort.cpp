#include <iostream>
using namespace std;
long long int n, t;
int main() {
  cin >> t;
  for (int i = 0; i < t; i++) {
    cin >> n;
    if (n == 1) cout << "Case " << i+1 << ": 0" << endl;
    else if ((n*(n-1))%4) cout << "Case " << i+1 << ": " << (n*(n-1))/2 << "/" << 2 << endl;
    else cout << "Case " << i+1 << ": " << (n*(n-1))/4 << endl;
  }
  return 0;
}
