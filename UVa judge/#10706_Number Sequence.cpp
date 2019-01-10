#include <iostream>
#include <cmath>
#define N 1000000
using namespace std;
long long int L, R, mid, in;
long long int num[N+5];
long long int len[N+5];
int T, n;
string ItoS(long long int x) {
  string m = "";
  if (x == 0) m = "0";
  while (x) {
  	m = (char)(x%10+'0') + m;
  	x /= 10;
  }
  return m;
}
int main() {
  cin >> T;
  for (int i = 1; i <= N; i++) {
  	num[i] = num[i-1]+(int)ceil(log10(i+0.1));
  	len[i] = len[i-1] + num[i];
  }
  for (int i = 0; i < T; i++) {
  	cin >> n;
  	L = 1;
  	R = N+1;
  	while (L+1 < R) {
  	  mid = (L+R)/2;
  	  if (len[mid] >= n) {
  	  	R = mid;
	  } else {
	  	L = mid;
	  }
	}
	long long int m = L;
	L = 1;
	R = mid;
	while (L+1 < R) {
  	  mid = (L+R)/2;
  	  if (num[mid]+len[m] > n) {
  	  	R = mid;
	  } else {
	  	L = mid;
	  }
	}
	while (num[mid]+len[m] < n) mid++;
	while (num[mid]+len[m] >= n) mid--;
	string ans = ItoS(mid+1);
	if (n > 1) cout << ans[(n-(num[L] + len[m])+ans.length()-1)%ans.length()] << endl;
	else cout << 1 << endl;
  }
}
