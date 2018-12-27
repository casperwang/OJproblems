#include <cstdio>
#include <iostream>
#define N 100
using namespace std;
// by C
string s;
int f[N+5], len;
int main() {
  while (cin >> s) {
    len = s.length();
    for (int i = 0; i < len; i++) {
      f[i] = -1;
    }
    for (int i = 1; i < len; i++) {
      int p = f[i-1];
      while (p >= 0 && s[p+1] != s[i]) p = f[p];
      if (s[p+1] == s[i]) p++;
      f[i] = p;
    }
    for (int i = 0; i < len; i++) f[i]++;
    if (len % (len-f[len-1]) == 0) printf("%d\n",len/(len-f[len-1]));
    else printf("1\n");
  }
}
