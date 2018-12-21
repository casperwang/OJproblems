#include <iostream>
using namespace std;
long long int n,tmp, s1,s2;
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> tmp;
    s1 += tmp;
  }
  for (int i = 0; i < n; i++) {
    cin >> tmp;
    s2 += tmp;
  }
  if (s1 >= s2) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}
