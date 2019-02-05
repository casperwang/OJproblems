#include <bits/stdc++.h>
#define MAXN 500
using namespace std;

struct pos {
  int x, y;
};

struct road {
  int a, b;
  double dis;
  road() {}
  road(int _a, int _b, double _dis) : a(_a), b(_b), dis(_dis) {}
};

class cmp {
  public:
  bool operator() (const road A, const road B) {
  	return A.dis > B.dis;
  }
};

int T, M, N;
double ans;
int ancestor[MAXN];
pos outpost[MAXN];
priority_queue <road, vector<road>, cmp> path;

double dis(pos a, pos b) {
  return sqrt( (a.x-b.x) * (a.x-b.x) + (a.y-b.y) * (a.y-b.y) );
}

void finding(int a) {
  stack <int> family;
  family.push(a);
  while (ancestor[ family.top() ] != family.top()) {
  	family.push( ancestor[family.top()] );
  }
  int tmp = family.top();
  while ( family.size() ) {
  	ancestor[ family.top() ] = tmp;
  	family.pop();
  }
  return;
}

int main() {
  scanf("%d", &T);
  for (int i = 0; i < T; i++) {
  	scanf("%d%d", &M, &N);
  	ans = 0;
  	for (int j = 0; j < N; j++) ancestor[j] = j;
  	while ( path.size() ) path.pop();
  	for (int j = 0; j < N; j++) {
  	  scanf("%d%d", &outpost[j].x, &outpost[j].y);
  	  for (int k = 0; k < j; k++) {
  	  	path.push( road( k, j, dis( outpost[k], outpost[j] ) ) );
	  }
	}
	for (int j = 0; j < N-M; j++) {
	  while (ancestor[ path.top().a ] == ancestor[ path.top().b ]) {
	  	path.pop();
	  	finding( path.top().a );
	  	finding( path.top().b );
	  }
	  ans = max(ans, path.top().dis);
	  ancestor[ ancestor[ path.top().a ] ] = ancestor[ path.top().b ];
	  path.pop();
	  finding(path.top().a);
	  finding(path.top().b);
	}
	printf("%.2lf\n", ans);
  } 
  return 0;
}
