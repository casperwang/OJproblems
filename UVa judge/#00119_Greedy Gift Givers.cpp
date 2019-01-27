#include <iostream>
#include <cstdio>
#include <map> 
#define N 10
using namespace std;
int t, n, p;
map <string, int> wallet;
string a, b, people[N+5];
bool tf;
int main() {
  while (cin >> t) {
  	if (tf) cout << endl;
  	tf = 1;
  	wallet.clear();
  	for (int i = 0; i < t; i++) {
  	  cin >> a;
  	  people[i] = a;
	}
	for (int i = 0; i < t; i++) {
  	  cin >> a >> n >> p;
  	  if (p) wallet[a] -= n / p * p;
  	  for (int j = 0; j < p; j++) {
  	    cin >> b;
  	    wallet[b] += n / p;
	  }
	}
	for (int i = 0; i < t; i++) {
	  cout << people[i] << " " << wallet[people[i]] << endl;
	}
  }
}
