#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
int n, ans, t;
double a, b, c ,d;
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
  	cin >> a >> b >> c >> d;
	if (((a<=56 && b<=45 && c<=25) || (a+b+c <= 125)) && d <= 7) t = 1;
	else t = 0;
	cout << t << endl;
	ans += t;
  }
  cout << ans << endl;
}
