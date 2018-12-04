//¹L¥b§ë²¼: map
#include <iostream>
#include <cstdio>
#include <map>
using namespace std;

int n, a, ans;

int main(){
    map <int, int> p;
	scanf("%d", &n);
	for (int i = 0; i < n; i++ ) {
        scanf("%d", &a);
        p[a]++;
        if (p[a] >= (n+1)/2) {
            ans = a;
            break;
        }
	}
	printf("%d\n", ans);
}

