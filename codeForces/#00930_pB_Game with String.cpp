#include <bits/stdc++.h>
#define MAXN 5000
using namespace std;

int len, sum;
string s;
string ss[MAXN+5];
int appr[26], abc, t;
int m, tmp;

int main() {
  cin >> s;
  len = s.length();
  for (int i = 0; i < len; i++) {
    appr[s[i]-'a']++;
    ss[i] = s.substr(i, len-i) + s.substr(0, i);
  }
  sort(ss, ss+len);
  for (int i = 0, k = 0; i < len; ++k) {
    m = 0;
    for (register int p = 1; p < len; ++p) {
      tmp = abc = t = 0;
      for (register int j = i; j < i + appr[k]; ++j) {
        if ((abc & (1 << (ss[j][p]-'a'))) && !(t & (1 << (ss[j][p]-'a')))) {
          tmp--;
          t |= (1 << (ss[j][p]-'a'));
        } else if (!(abc & (1 << (ss[j][p]-'a')))){
          tmp++;
        }
        abc |= (1 << (ss[j][p]-'a'));
      }
      m = max(m, tmp);
    }
    sum += m;
    i += appr[k];
  }
  printf("%.7lf\n", (double)sum/len);
  return 0;
}
