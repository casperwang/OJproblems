#include <iostream>
#include <cstdio>
#define N 100000
using namespace std;
int n, k, num[N+5], SG, tf;
/*
  SG(x) = mex{ SG(x-1) },                    x % 2
          mex{ SG(x-1), SG(x/2) * (k % 2) }, !(x % 2) && x
          0,                                 !x
*/
int a[4] = {0, 1, 2, 0};
int b[5] = {0, 1, 0, 1, 2};
int main() {
  scanf("%d%d",&n,&k);
  for (int i = 0; i < n; i++) {
  	scanf("%d",&num[i]);
  	if (k % 2 == 0) {
  	  if (num[i] < 4) SG = a[num[i]];
  	  else SG = !(num[i]%2);
	} else {
	  if (num[i] < 5) SG = b[num[i]];
	  else if (num[i] % 2) SG = 0;
	  else {
	  	int p = num[i], s = 0;
	  	while (p > 4 && p % 2 == 0) {
	  	  s++;
	  	  p /= 2;
		}
		if (s % 2 == 0 && p != 3) SG = 2;
		else if (p == 3 && s % 2) SG = 2;
		else SG = 1;
	  }
	}
	tf ^= SG;
  }
  if (!tf) printf("Nicky\n");
  else printf("Kevin\n");
  return 0;
}
