#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define N 100
using namespace std;
string s;
int n, len;
int sorting[N+5], num[N+5];
vector <int> ans;
void flap(int index) {
  int tmp[N+5];
  for (int i = 0; i <= len-index; i++) {
  	tmp[i] = sorting[i];
  }
  cout << endl;
  for (int i = 0; i <= len-index; i++) {
  	sorting[i] = tmp[len-index-i];
  }
  return;
}
int main() {
  while (getline(cin, s)) {
  	cout << s << endl;
  	len = n = 0;
  	ans.clear();
    for (int i = 0; i < s.length(); i++) {
      if (s[i] == ' ') {
      	num[len++] = n;
      	n = 0;
	  } else {
	  	n = n * 10 + s[i]-'0';
	  }
	}
	num[len++] = n;
	for (int i = 0; i < len; i++) sorting[i] = num[i];
	sort(num, num+len);
	for (int i = len-1; i > 0; i--) {
	  if (sorting[i] == num[i]) {
	  } else if (sorting[0] == num[i]) {
	    flap(len-i); ans.push_back(len-i);
	  } else {
	  	int index = 0;
	  	while (sorting[index] != num[i]) index++;
	  	flap(len-index); ans.push_back(len-index);
	  	flap(len-i); ans.push_back(len-i);
	  }
	}
	for (int i = 0; i < ans.size(); i++) {
	  cout << ans[i] << " "; 
	}
	cout << 0 << endl;
  }
}
