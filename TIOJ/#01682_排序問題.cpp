#include <iostream>
#include <cstdio> 
#include <algorithm>
#define N 100000
using namespace std;
int n, num[N+5];
bool tf;
int main() {
  while (scanf("%d",&n) != EOF) {
  	for (int i = 0; i < n; i++) {
  	  scanf("%d",&num[i]);
	}
	sort(num, num+n);
	for (int i = 0; i < n; i++) {
	  if (i) printf(" ");
  	  printf("%d",num[i]);
	}
	printf("\n");
  }
  return 0;
}
