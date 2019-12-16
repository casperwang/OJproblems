#include <iostream>
#define MAXN 3000
using namespace std;

int N, ans, a, b, k, m;
string s;

int main() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> s;
    for (int j = 1; j < s.length(); j++) {
      if (s[j] == 'B' && s[j-1] == 'A') ans++;
    }
    if (s[0] == 'B') a--, k++;
    if (s[s.length()-1] == 'A') a++;
    if (s[0] == 'B' && s[s.length()-1] == 'A') m++;
  }
  if (a < 0) k += a;
  if (k == N || (m == k && !a)) k--;
  ans += max(0, k);
  cout << ans << endl;
}
