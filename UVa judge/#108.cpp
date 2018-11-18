//Maximum Sum: 2Dprefix O(N^4)
#include <iostream>
#define N 100
using namespace std;

int n, a, ans;
int preC[N+5][N+5]; // prefix for column
int preR[N+5][N+5]; // prefix for row
int pre[N+5][N+5]; // prefix

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a;
			preC[i][j] = preC[i][j-1]+a;
			preR[i][j] = preR[i-1][j]+a;
			pre[i][j] = pre[i-1][j-1] + preC[i][j] + preR[i][j] - a;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int x = i; x <= n; x++) {
				for (int y = j; y <= n; y++) {
					ans = max(ans, pre[x][y]-pre[x][j]-pre[i][y]+pre[i][j]);
				}
			}
		} 
	}
	cout << ans << endl;
	return 0;
}
