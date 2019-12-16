#include <cstdio>
#include <algorithm>
#define MAXN 10000
#define pb push_back
using namespace std;

int n, ans;
int arr[MAXN+5];

signed main() {
	scanf("%d",&n);
	for (int i = 1; i <= n; i++)
		scanf("%d",&arr[i]);
	sort(arr+1, arr+1+n);
	for (int i = 1; i <= n; i++)
		ans += (arr[i]-arr[i-1])*(arr[i]-arr[i-1]);
	printf("%d\n", ans);
}