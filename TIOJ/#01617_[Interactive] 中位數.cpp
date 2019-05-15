#include <bits/stdc++.h>
#include "lib1617.h"
using namespace std;
int n, ans;
int a, c;
int Y[1500];

int main(){
  n = Get_Box();
  a = 1, c = 2;
  for (int i = 1; i <= n; i++) {
    Y[i] = i;
  }
  for (int i = 3; i <= n; i++) {
    if (Med3(a, i, c) == a) a = i;
    else if (Med3(a, i, c) == c) c = i;
  }
  nth_element(Y+1, Y+(n+1)/2, Y+n+1, [](int x, int y) {
    if (a == x) return 1;
    if (a == y) return 0;
    if (Med3(a, x, y) == x) return 1;
    return 0;
  });
  Report(Y[(n+1)/2]);
}
