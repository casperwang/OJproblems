#include <iostream>
#include <cstdio> 
using namespace std;
int a, b;
int main() {
  scanf("%d%d",&a,&b);
  cout << ((!(a%b) || !(b%a)) ? "Y" : "N") << endl;
  return 0;
}
