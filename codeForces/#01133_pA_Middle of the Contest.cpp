#include <bits/stdc++.h>
#define MAXN 10000+5
using namespace std;

string a, b;
int A, B;

int main() {
  cin >> a >> b;
  A = 60 * ((a[0]-'0')*10 + (a[1]-'0')) + (a[3]-'0')*10 + (a[4]-'0');
  B = 60 * ((b[0]-'0')*10 + (b[1]-'0')) + (b[3]-'0')*10 + (b[4]-'0');
  A = (A+B)/2;
  B = 0; 
  if ((A+B)/60 < 10) cout << "0";
  cout << (A+B)/60 << ":";
   if ((A+B)%60 < 10) cout << "0";
   cout << (A+B)%60 << endl;
} 
