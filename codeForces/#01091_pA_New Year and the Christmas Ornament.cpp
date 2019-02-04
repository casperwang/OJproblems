#include <iostream>
using namespace std;
int a, b, c;
int main() {
  cin >> a >> b >> c;
  cout << 3 * min(min(a+1, b),c-1) << endl;
  return 0;
}
