#include <iostream>
#define N 100
using namespace std;
string song[16] = {"Happy","birthday","to","you","Happy","birthday","to","you",
"Happy","birthday","to","Rujia","Happy","birthday","to","you"};
string people[N+5];
int n;
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
  	cin >> people[i];
  }
  int j = 0;
  for (int i = 0; i <= n/16; i++) {
  	for (int k = 0; k < 16; k++) {
  	  cout << people[(j++)%n] << ": " << song[k] << endl;
	}
  }
}
