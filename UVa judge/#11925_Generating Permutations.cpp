#include <iostream>
#include <cstdio>
#include <stack>
#include <queue>
#include <vector>
using namespace std;
int n, t, num[300+5];
bool tf;
vector <int> now;
queue <int> ans;
void goBack() {
  now.push_back(now[0]);
  now.erase(now.begin(), now.begin()+1);
  ans.push(2);
}
void exchange() {
  swap(now[0], now[1]);
  ans.push(1);
}
int main() {
  while (cin >> n) {
  	if (!n) return 0;
  	now.clear();
  	for (int i = 0; i < n; i++) {
  	  cin >> num[i];
  	  now.push_back(i+1);
    }
    for (int i = n-2; i >= 0; i--) {
      while (now[0] != num[i]) goBack();
      while (now[1] != num[i+1]) {
      	exchange();
      	goBack();
	  } 
	}
	while (ans.size()) {
	  printf("%d",ans.front());
	  ans.pop();
	}
	printf("\n");
  }
}
