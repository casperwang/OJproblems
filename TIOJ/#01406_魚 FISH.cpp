#include <bits/stdc++.h>
#define MAXN 100000+5
using namespace std;

struct num{
  long long int pos, val;
};

int n;
long long int L, R, mid;
num V[MAXN];
long long int now[MAXN];

int main() {
  while (cin >> n) {
    L = 0;
    R = 1000000000001;
    for (int i = 1; i <= n; i++) {
      cin >> V[i].pos >> V[i].val;
    }
    while(L+1 < R) {
      mid = (L + R) / 2;
      for (int i = 1; i <= n; i++) now[i] = V[i].val;
      for (int i = 1; i <= n; i++) {
        if (now[i-1] > mid) {
          now[i] += max(now[i-1]-mid - (V[i].pos-V[i-1].pos), (long long)0);
          now[i-1] -= now[i-1]-mid;
        }
        if (now[i] < mid && i < n) {
          now[i+1] -= mid-now[i] + (V[i+1].pos-V[i].pos);
          now[i] += mid-now[i];
        }
      }
      if (now[n] >= mid) L = mid;
      else R = mid;
    }
    printf("%lld\n", L);
  }
}
