#include <iostream>
#include <map>
#include <string>
#define N 120000
using namespace std;
string str[N+5];
bool com[N+5];
int n = 0;
map <string, int> appr;
int main() {
  while (cin >> str[n]) {
  	if (str[n].length()) n++;
  	appr[str[n-1]] = n;
  }
  for (int i = 0; i < n; i++) {
  	string a = str[i].substr(0, 1), b = str[i].substr(1, str[i].length()-1);
  	while (b.length()) {
  	  if (appr[a] && appr[b]) com[i] = 1;
  	  a = a + b[0];
  	  b = b.substr(1, b.length()-1);
	}
  }
  for (int i = 0; i < n; i++) {
  	if (com[i]) cout << str[i] << endl;
  }
}
