#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#define N 200000
using namespace std;
long long int n, m, s, d;
long long int tmp;
long long int num[N+5];
queue <int> ans;
bool tf = 1;
int main() {
  scanf("%lld%lld%lld%lld",&n,&m,&s,&d);
  for (int i = 0; i < n; i++) {
    scanf("%lld",&num[i]);
  }
  sort(num,num+n);
  tmp = num[0];
  ans.push(tmp);
  if (num[0] <= s || d == 1) tf = 0;
  for (int i = 1; i < n; i++) {
    if (num[i]-num[i-1]-1 > s) {
      ans.push(num[i-1]-tmp+2);
      tmp = num[i];
      ans.push(tmp);
      continue;
    } else if (num[i]-tmp+2 > d) {
      tf = 0;
      break;
    }
  }
  ans.push(num[n-1]-tmp+2);
  if (!tf) {
    cout << "IMPOSSIBLE" << endl;
  } else {
    int now = 1;
    while (ans.size()) {
      if (now != ans.front()) {
        cout << "RUN " << ans.front()-now << endl;
        now += ans.front()-now;
      } else {
        ans.pop();
        cout << "JUMP " << ans.front() << endl;
        now += ans.front();
        ans.pop();
      }
    }
    if (m-now+1) cout << "RUN " << m-now+1 << endl;
  }
  return 0;
}
