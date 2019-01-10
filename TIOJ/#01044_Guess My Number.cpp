#include <iostream>
#include "lib1044.h"
using namespace std;
int main() {
  Initialize();
  int L, R, mid;
  L = 1;
  R = 2000000000;
  while (L+1 < R) {
  	mid = (L+R)/2;
	if (Guess(mid)) R = mid;
	else L = mid;
  }
  mid -= 2;
  while (!Guess(mid)) mid++;
  Report(mid);
}
