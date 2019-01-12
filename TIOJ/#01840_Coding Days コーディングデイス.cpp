#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#define N 50000
using namespace std;
int val[N+5];
int rem[N+5], pre[N+5], bit[N+5];
int T, n, q;
int o, l, r, p, v;
struct op {
  int o, p, l, r, v, ans;
  // o : operation: 1(query), 2(add), -2(delete), -1(7122)
  // p : position
  // l, r : left, right
  // v : value
  op(int o) : o(o) {}; // -1
  op(int o, int p, int v) : o(o),p(p),v(v) {}; // 2, -2
  op(int o, int l, int r, int v) : o(o),l(l),r(r),v(v) {}; // 2
};
vector <op> ops; // operations
vector <int> DSC; // discretization
// BIT
int lowbit(int n) {
  return n&-n;
}
int query(int n) {
  return n ? bit[n] + query(n-lowbit(n)) : 0;
}
void modify(int n, int a) {
  bit[n] += a;
  if (n+lowbit(n) <= N) modify(n+lowbit(n),a);
}
// binary search
void BS(int L, int R, vector <int> &VS) {
  if (!VS.size()) return;
  if (L == R) {
  	for (auto i : VS) {
  	  if (ops[i].o == 1) ops[i].ans = DSC[L-1];
	}
	return;
  }
  vector <int> LS, RS;
  int mid = (L+R)/2;
  for (auto i : VS) {
  	if (ops[i].o == 2) {
  	  if (ops[i].v <= mid) {
  	  	modify(ops[i].p,1);
  	  	LS.push_back(i);
	  } else {
	  	RS.push_back(i);
	  }
	} else if (ops[i].o == -2) {
	  if (ops[i].v <= mid) {
  	  	modify(ops[i].p,-1);
  	  	LS.push_back(i);
	  } else {
	  	RS.push_back(i);
	  }
	} else if (ops[i].o == 1) {
	  ops[i].ans = query(ops[i].r) - query(ops[i].l-1);
	  if (ops[i].ans >= ops[i].v) {
	  	LS.push_back(i);
	  } else {
	  	ops[i].v -= ops[i].ans;
	  	RS.push_back(i);
	  }
	}
  }
  for (auto i : LS) {
  	if (ops[i].o == 2) {
  	  modify(ops[i].p,-1);
	} else if (ops[i].o == -2) {
	  modify(ops[i].p, 1);
	}
  }
  vector <int> ().swap(VS);
  BS(  L  ,mid,LS);
  BS(mid+1, R ,RS);
}
int main() {
  scanf("%d",&T);
  for (int i = 0; i < T; i++) {
    scanf("%d%d",&n,&q);
    DSC.clear();
	ops.clear();
    for (int j = 1; j <= n; j++) {
      scanf("%d",&val[j]);
      ops.push_back(op(2,j,val[j]));
      DSC.push_back(val[j]);
	}
	vector <int> VS;
	for (int j = 0; j < q; j++) {
	  scanf("%d",&o);
	  if (o == 1) {
	  	scanf("%d%d%d",&l,&r,&v);
	  	ops.push_back(op(1,l,r,v));
	  } else if (o == 2) {
	  	scanf("%d%d",&p,&v);
	  	ops.push_back(op(-2,p,val[p]));
	  	ops.push_back(op( 2,p,  v   ));
	  	val[p] = v;
	  	DSC.push_back(v);
	  } else if (o == 3) {
	  	scanf("%d%d",&p,&v);
	  	ops.push_back(op(-1));
	  }
	}
	sort(DSC.begin(), DSC.end());
	for (int j = 1; j < DSC.size(); j++) {
	  while (j < DSC.size() && DSC[j] == DSC[j-1]) DSC.erase(DSC.begin()+j);
	}
	for (int j = 0; j < DSC.size(); j++) rem[j] = 0; // initialize
	for (int j = 0; j < ops.size(); j++) {
	  if (ops[j].o == 2 || ops[j].o == -2) {
	  	ops[j].v = lower_bound(DSC.begin(),DSC.end(),ops[j].v) - DSC.begin() + 1;
	  }
	}
	for (int j = 0; j < ops.size(); j++) VS.push_back(j);
	BS(1,(int)DSC.size(),VS);
	for (int j = 0; j < ops.size(); j++) {
	  if (ops[j].o == -1) printf("7122\n");
	  else if (ops[j].o == 1) printf("%d\n",ops[j].ans);
	}
  }
}
