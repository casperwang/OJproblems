#include <iostream>
using namespace std;

int n, s = 1;
string a, tmp;

int main() {
  cin >> n >> a;
  for (int i = 1; i < n; i++) {
    tmp = a;
    cin >> a;
    if (a != tmp) s++;
  }
  cout << s << endl;
  return 0;
}
