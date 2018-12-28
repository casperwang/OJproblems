#include <iostream>
#include <algorithm>
#define N 100000
using namespace std;
int n, num[N+5];
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> num[i];
  }
  sort(num, num+n);
  cout << min(num[n-2]-num[0], num[n-1]-num[1]) << endl;
}
