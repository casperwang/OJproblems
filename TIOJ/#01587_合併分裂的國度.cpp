#include <iostream>
using namespace std;

string a;
int len;

int main() {
  cin >> a;
  len = a.length();
  for (int i = 2; i <= len; i++) {
    a += a[len-i];
  }
  cout << a << endl;
  return 0;
}
