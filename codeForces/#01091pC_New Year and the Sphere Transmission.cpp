#include <iostream>
#include <queue>
#include <vector>
#include <map>
using namespace std;
long long int n;
class cmp{
  public:
    bool operator() (const long long int a, const long long int b) {
      return a > b;
    }
};
priority_queue <long long int, vector<long long int>, cmp> ans;
map <int, bool> appr;
int main() {
  cin >> n;
  for (int i = 1; i*i <= n; i++) {
    if (n % i == 0) {
      ans.push((n/i)*(n-i+2)/2);
      ans.push((i)*(n-n/i+2)/2);
    }
  }
  bool tf = 0;
  while (ans.size()) {
    if (!appr[ans.top()]) {
      if (tf) cout << " ";
      cout << ans.top();
      tf = 1;
      appr[ans.top()] = 1;
    }
    ans.pop();
  }
  cout << endl;
  return 0;
}
