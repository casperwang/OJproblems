#include <bits/stdc++.h>
using namespace std;
int t, a, b, c, d;
string s;
int main() {
  scanf("%d",&t);
  for (int i = 0; i < t; i++) {
  	cin >> a >> b >> c >> d;
	if (c^d^(c-a)^(d-b)) cout << "Gretel" << endl;
	else cout << "Hansel" << endl;
  }
  return 0;
}
