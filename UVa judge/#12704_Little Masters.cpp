#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
int n, a, b, c;
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
  	cin >> a >> b >> c;
	printf("%.2lf %.2lf\n",c-sqrt(a*a+b*b),c+sqrt(a*a+b*b));
  }
}
