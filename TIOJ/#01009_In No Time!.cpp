#include <bits/stdc++.h>
#define MAXN 200000
#define pb push_back
#define int long long
using namespace std;

string a1, a2;

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> a1 >> a2;
  if (a1 > a2) a2[0] += 2, a2[1] += 4;
  if (a2[7] >= a1[7]) a2[7] = a2[7]-a1[7]+'0';
  else a2[7] = a2[7]+10-a1[7]+'0', a2[6]--;
  if (a2[6] >= a1[6]) a2[6] = a2[6]-a1[6]+'0';
  else a2[6] = a2[6]+ 6-a1[6]+'0', a2[4]--;
  if (a2[4] >= a1[4]) a2[4] = a2[4]-a1[4]+'0';
  else a2[4] = a2[4]+10-a1[4]+'0', a2[3]--;
  if (a2[3] >= a1[3]) a2[3] = a2[3]-a1[3]+'0';
  else a2[3] = a2[3]+ 6-a1[3]+'0', a2[1]--;
  if (a2[1] >= a1[1]) a2[1] = a2[1]-a1[1]+'0';
  else a2[1] = a2[1]+10-a1[1]+'0', a2[0]--;
  a2[0] = a2[0]-a1[0]+'0';
  cout << a2 << endl;
  return 0;
}