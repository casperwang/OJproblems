#include <iostream>
using namespace std;
long long int n, x, y, s_x, s_y;
int main() {
  cin >> n;
  for (int i = 0; i < 2*n; i++) {
    cin >> x >> y;
    s_x += x;
    s_y += y;
  }
  cout << s_x/n << " " << s_y/n << endl;
  return 0;
}
