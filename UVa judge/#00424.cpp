//Integer Inquiry: big integer
#include <iostream>
#define N 100
using namespace std;

string n[N+5];
int ans[N+5];
int k, len;
bool tf;

int main(){
	while (cin >> n[k++]) {
        if (n[k-1] == "0") break;
        len = max(len, (int)n[k-1].length());
	}
	for (int i = len-1; i >= 0; i-- ) {
        for (int j = 0; j < k && i >= 0; j++) {
            if (i < n[j].length()) ans[len-1-i] += n[j][i]-'0';
        }
	}
	for (int i = 0; i < 105 ; i++) {
        ans[i+1] += ans[i]/10;
        ans[i] = ans[i] % 10 + '0';
	}
	tf = 0;
	for (int i = 104; i >= 0 ; i--) {
        if (ans[i] > '0' || tf) {
            cout << (char)ans[i];
            tf = 1;
        }
	}
	cout << endl;
}

