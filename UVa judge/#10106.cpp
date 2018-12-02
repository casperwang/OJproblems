//Product: big integer
#include <iostream>
#define N 500
using namespace std;

string x, y;
int ans[N+5];

int main() {
    while (cin >> x >> y) {
        for (int i = 0; i < N+5; i++) ans[i] = 0;
        for (int i = x.length()-1; i >= 0; i--) {
            for (int j = y.length()-1; j >= 0; j--) {
                ans[i+j+1] += (x[i]-'0') * (y[j]-'0');\
            }
        }
        for (int i = x.length()+y.length()-1; i >= 0; i--) {
            if (ans[i] >= 10) ans[i-1] += ans[i]/10;
            ans[i] %= 10;
        }
        bool tf = 0;
        for (int i = 0; i < x.length()+y.length(); i++) {
            if (ans[i]) tf = 1;
            if (tf) cout << ans[i];
        }
        if (!tf) cout << 0;
        cout << endl;
    }
	return 0;
}

