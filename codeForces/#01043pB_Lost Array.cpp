#include <bits/stdc++.h>
#define MAXN 1000+5
using namespace std;

long long int n, a[MAXN], num[MAXN];
bool tf;
vector <int> ans;

int main() {
  scanf("%d",&n);
  for (int i = 1; i <= n; i++) {
  	scanf("%d",&a[i]);
  	num[i] = a[i] - a[i-1];
  }
  for (int i = 1; i <= n; i++) {
  	tf = 1;
  	for (int j = i+1; j <= n; j++) {
  	  if (num[(j-1)%i+1] != num[j]) tf = 0;
    }
    if (tf) ans.push_back(i);
  }
  cout << ans.size() << endl; 
  for (int i = 0; i < ans.size(); i++) {
  	if (i) cout << " ";
  	cout << ans[i];
  }
  return 0;
}
