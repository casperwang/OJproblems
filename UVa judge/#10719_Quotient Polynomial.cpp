#include <bits/stdc++.h>
#include <sstream>
#define MAXN 10000
using namespace std;
long long int k, tmp, n;
long long int ans[MAXN], num[MAXN];
string a;
char c;
int main() {
  while(cin >> k) {
    cin.get();
    getline(cin, a);
    stringstream ss;
    ss << a;
    ss >> num[0];
    tmp = n = 0;
    while (ss) {
      ss >> num[++n];
    }
    for (int i = 0; i < n; i++) {
      ans[i] = num[i]+tmp;
      tmp = (num[i]+tmp) * k;
    }
    cout << "q(x):";
    for (int i = 0; i < n-1; i++) {
      cout << " " << ans[i];
    }
    cout << endl;
    cout << "r = " << ans[n-1] << endl << endl;
  }
}
