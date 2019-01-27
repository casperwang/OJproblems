#include <iostream>
#define N 500
using namespace std;
string ans[N+5], a, b;
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
  ans[0] = "0"; ans[1] = "1";
  for (int i = 2; i <= N; i++) {
  	ans[i] = add(ans[i-2], ans[i-1]);
  }
  while (cin >> a >> b) {
  	if (a == "0" && b == "0") return 0;
  	n = 0;
  	for (int i = 2; i <= N; i++) {
  	  if ((ans[i].length() > a.length() || (ans[i].length() == a.length() && ans[i] >= a))
	   && (ans[i].length() < b.length() || (ans[i].length() == b.length() && ans[i] <= b))) {
		n++;
	  }
	}
	cout << n << endl;
  }
  return 0;
}
