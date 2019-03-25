#include <bits/stdc++.h>
using namespace std;

int n, m;

int main() {
  cin >> n >> m;
  if (max(n, m) == 1) cout << "1/1" << endl;
  if (max(n, m) == 2) cout << "5/6" << endl;
  if (max(n, m) == 3) cout << "2/3" << endl;
  if (max(n, m) == 4) cout << "1/2" << endl;
  if (max(n, m) == 5) cout << "1/3" << endl;
  if (max(n, m) == 6) cout << "1/6" << endl;
  return 0;
}
