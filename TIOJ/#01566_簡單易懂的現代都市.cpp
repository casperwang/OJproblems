#include <bits/stdc++.h>
#define MAXN 11000000+5
using namespace std;

struct seg{
  long long int l, r;
};

long long int n, m, k;
long long int s_max, s_min, f_max, f_min, p_max, p_min;
unsigned int val_max[MAXN], val_min[MAXN], a[MAXN];
vector <seg> ans;

int main() {
  scanf("%lld%lld%lld", &n, &m, &k);
  s_max = s_min = f_max = f_min = 1;
  int i;
  for (i = 1; i <= n; i++) {
    scanf("%lld", &a[i]);
    //max
    while (a[i] > val_max[f_max-1] && f_max > s_max) f_max--;
    val_max[f_max++] = a[i];
    if (i-m && val_max[s_max] == a[i-m]) s_max++;
    //min
    while (a[i] < val_min[f_min-1] && f_min > s_min) f_min--;
    val_min[f_min++] = a[i];
    if (i-m && val_min[s_min] == a[i-m]) s_min++;
    //cout << val_max[s_max] << " " << val_min[s_min] << endl;
    if (val_max[s_max] - val_min[s_min] == k && i > 1) {
      seg p;
      p.l = max(i-m+1, (long long int)1);
      p.r = i;
      ans.push_back(p);
    }
  }
  for (; i < n+m-1; i++) {
    if (i-m && val_max[s_max] == a[i-m]) s_max++;
    if (i-m && val_min[s_min] == a[i-m]) s_min++;
    //cout << val_max[s_max] << " " << val_min[s_min] << endl;
    if (val_max[s_max] - val_min[s_min] == k) {
      seg p;
      p.l = max(i-m+1, (long long int)1);
      p.r = min(i, (int)n);
      ans.push_back(p);
    }
  }
  cout << ans.size() << endl;
  for (int i = 0; i < ans.size(); i++) {
    printf("%lld %lld\n", ans[i].l, ans[i].r);
    assert(ans[i].r - ans[i].l > 0);
  }
}
