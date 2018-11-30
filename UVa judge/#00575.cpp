//Skew Binary: trivial
#include <iostream>
using namespace std;

string n;
int ans;

int main(){
	while (cin >> n) {
	    if (n == "0") return 0;
        ans = 0;
        for (int i = n.length()-1, j = 2; i >= 0; i--, j*=2) {
            ans += (j-1)*(n[i]-'0');
        }
        cout << ans << endl;
	}
}

