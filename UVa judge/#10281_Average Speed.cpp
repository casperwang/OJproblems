#include <iostream>
#include <cstdio>
using namespace std;
string t, last_t;
int s;
double dis, sec, last_sec;
int StoI(string x) {
  int n = 0;
  for (int i = 0; i < x.length(); i++) {
  	n = n * 10 + x[i]-'0';
  }
  return n;
}
int main() {
  while (cin >> t) {
    sec = 60*(60*(10*(t[0]-'0')+(t[1]-'0'))+10*(t[3]-'0')+(t[4]-'0'))+10*(t[6]-'0')+(t[7]-'0');
    dis += (sec-last_sec)/3600*s;
    last_t = t;
    last_sec = sec;
	if (cin.peek() == ' ') {
	  cin >> s;
	} else {
	  cout << t;
	  printf(" %.2lf km\n", dis);
	}
  }
}
