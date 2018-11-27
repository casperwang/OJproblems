//Squares: DP
#include <iostream>
#define N 10000
using namespace std;

int T, n;
int num[N+5];

int main(){
    for (int i = 0; i <= N; i++) num[i] = i;
    for (int i = 2; i <= 100; i++) {
        for (int j = 0; j <= N-i*i; j++) {
            num[j+i*i] = min(num[j+i*i], num[j]+1);
        }
    }
	cin >> T;
	for (int Q = 0; Q < T; Q++) {
        cin >> n;
        cout << num[n] << endl;
	}
}

