#include <iostream>
#define N 2000
using namespace std;
string ans[N+5];
int n;
string add(string a, string b) {
  int lenA = a.length(), lenB = b.length();
  for (int i = lenA-1; i >= 0; i--) {
  	b[lenB-(lenA-i)] += a[i]-'0';
  	if (b[lenB-(lenA-i)] > '9') {
  	  if (lenB-(lenA-i) > 0) {
  	  	b[lenB-(lenA-i)-1]++;
  	  	b[lenB-(lenA-i)] -= 10;
	  } else {
	  	b = "1" + b;
	  	b[1] -= 10;
	  }
    }
  }
  return b;
}
int main() {
  ans[0] = "1"; ans[1] = "2";
  for (int i = 2; i <= N; i++) {
  	ans[i] = add(ans[i-2], ans[i-1]);
  }
  while (cin >> n) {
  	cout << ans[n] << endl; 
  }
  return 0;
}
