// The 3n + 1 problem : recursion to stack
#include <iostream>
#include <stack>
using namespace std;

long long int a , b;
int ans;

int main() {
    while(cin >> a >> b) {
        ans = 0;
        cout << a << " " << b << " ";
        if (a > b) swap(a, b);
        for (int i = a; i <= b; i++) {
			stack <long long int> cycle;
        	cycle.push(i);
        	while (cycle.top()>1) {
        		if (cycle.top()%2) cycle.push(3*cycle.top()+1);
    			else cycle.push(cycle.top()/2);
			} 
			int len = cycle.size();
            ans = max(ans, len);
        
        cout << ans << endl;
    }
    return 0;
}
