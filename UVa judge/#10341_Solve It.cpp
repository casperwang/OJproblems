#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
double L, R, mid;
double p, q, r, s, t, u;
double caculate(double x) {
  return p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u;
}
int main() {
  while (cin >> p >> q >> r >> s >> t >> u) {
  	L = 0;
  	R = 1;
  	mid = (L+R)/2;
  	while (R > L && abs(caculate(mid)) > 0.000001 && mid < 1 && mid > 0) {
  	  if (caculate(mid) > 0) L = mid;
  	  else R = mid;
  	  mid = (L+R)/2;
  	}
  	if (!caculate(0)) printf("0.0000\n");
  	else if (!caculate(1)) printf("1.0000\n");
  	else if (abs(caculate(mid)) < 0.00001 && mid >= 0 && mid <= 1) printf("%.4lf\n",mid);
  	else cout << "No solution" << endl;
  }
}
