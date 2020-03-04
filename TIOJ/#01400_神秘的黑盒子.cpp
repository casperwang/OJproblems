#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define int long long
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> rbtree;

const int C = 200000000;
string op;
int n, x, k, cnt;
rbtree ordered_set;

signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  srand(time(NULL));
  while (cin >> op) {
    if (op == "END")
      return 0;
    if (op == "EXIT")
      ordered_set.clear(), k = cnt = 0;
    if (op == "GET" && ordered_set.size() > k)
      cout << *ordered_set.find_by_order(k++)/C << "\n";
    if (op == "PUSH")
      cin >> x, ordered_set.insert(x*C+(++cnt)%C*(x<0?-1:1));
  }
  return 0;
}