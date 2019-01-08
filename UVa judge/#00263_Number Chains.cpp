#include <iostream>
#include <string>
#include <algorithm>
#include <map>
using namespace std;
string a, b, c;
int len;
string ItoS(int x) {
  string m = "";
  while (x > 0) {
  	m = (char)(x%10+'0') + m;
  	x /= 10;
  }
  return m;
}
int StoI(string x) {
  int m = 0;
  for (int i = 0; i < x.length(); i++) {
  	m = m * 10 + (x[i]-'0');
  }
  return m;
}
int main() {
  while (cin >> a) {
  	if (a == "0") return 0;
  	map <string, bool> appr;
  	cout << "Original number was " << a << endl; 
  	len = 0;
  	c = a;
  	while (!appr[c]) {
	  appr[c] = 1;
  	  a = c;
	  sort(&a[0],&a[0]+a.length());
	  b = "";
	  int i = 0;
	  while (a[i] == '0') i++;
	  for (;i < a.length(); i++) b += a[i];
	  reverse(a.begin(), a.end());
	  c = ItoS(StoI(a)-StoI(b));
	  if (a == "") a = "0";
	  if (b == "") b = "0"; 
	  if (c == "") c = "0";
	  cout << a << " - " << b << " = "<< c << endl;
	  len++;
	}
	cout << "Chain length " << len << endl << endl;
  }
}
