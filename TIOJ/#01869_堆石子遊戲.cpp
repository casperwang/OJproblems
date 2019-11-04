#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#define MAXN 1024
using namespace std;

int arr[MAXN+2][MAXN+2];
inline int lowbit(int a) {
	return a&-a;
}
void mdy(int x, int y, int k) {
	int j;
	for (; x <= MAXN; x += lowbit(x))
		for (j = y; j <= MAXN; j += lowbit(j))
			arr[x][j] += k;
}
int qry(int x, int y) {
	int sum = 0, j;
	for (; x; x -= lowbit(x))
		for (j = y; j; j -= lowbit(j))
			sum += arr[x][j];
	return sum;
}

int n, op;
int x, y, z;
int x_1, y_1, x_2, y_2;

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	while (cin >> op) {
		if (op & 1) {
			cin >> x >> y >> z;
			x++, y++;
			mdy(x, y, z);
		} else {
			cin >> x_1 >> y_1 >> x_2 >> y_2;
			x_2++, y_2++;
			cout << qry(x_2,y_2)-qry(x_1,y_2)-qry(x_2,y_1)+qry(x_1,y_1) << '\n';
		}
	}
}