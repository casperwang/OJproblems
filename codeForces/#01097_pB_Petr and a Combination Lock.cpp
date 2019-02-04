#include <cstdio>
#include <iostream>
using namespace std;
int n;
int num[15];
bool DFS(int now, int degree) {
  if (now == n) return !(degree%360);
  return (DFS(now+1, degree+num[now]) || DFS(now+1, degree+360-num[now]));
}
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
  	cin >> num[i];
  }
  if (DFS(0, 0)) cout << "YES" << endl;
  else cout << "NO" << endl;
  return 0;
}
