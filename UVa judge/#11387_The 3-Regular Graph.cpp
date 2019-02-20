#include <bits/stdc++.h>
#define MAXN 200000+5
using namespace std;
long long int n;
int main(){
  while (cin >> n) {
    if (!n) return 0;
    if (n % 2 || n < 4) {
      cout << "Impossible" << endl;
      continue;
    } else {
      cout << n*3/2 << endl;
      for (int i = 1; i < n; i++) {
        cout << i << " " << i+1 << endl;
        if (i <= n/2) cout << i << " " << i + n/2 << endl;
        if (i == 1) cout << i << " " << n << endl; 
      }
    }
  }
	return 0;
}
