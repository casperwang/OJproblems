#include <bits/stdc++.h>
#define MAXN 200000
using namespace std;
long long int n;
long long int D, R, XD, XR;
string a;
int main(){ 
  cin >> n >> a;
  for (int i = 0; i < n; i++) {
    if (a[i] == 'D') {
      D++;
    }
    if (a[i] == 'R') {
      R++;
    }
  }
  for (int i = 0; D && R; i++) {
    if (a[i%n] == 'D' && XD == 0) {
      XR++;
      R--;
    }
    if (a[i%n] == 'D' && XD) {
      XD--;
      a[i%n] = 'X';
    }
    if (a[i%n] == 'R' && XR == 0) {
      XD++;
      D--;
    }
    if (a[i%n] == 'R' && XR) {
      XR--;
      a[i%n] = 'X';
    }
  }
  if (D) cout << "D" << endl;
  else cout << "R" << endl; 
	return 0;
}
