#include <iostream>
#include <cmath>
#include <cstdio>
#define PI 3.14159265
using namespace std;
int n, k;
double ans;
int main() {
  cin >> n >> k;
  ans = (sin((2*PI)/(double)(2*n)) * k) / (1 - sin((2*PI)/(double)(2*n)));
  printf("%.8f\n",ans);
  return 0;
}
