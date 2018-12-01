//The Collatz Sequence: 3n+1 problem
#include <iostream>
using namespace std;

int A, L, t;

int main(){
	while (cin >> A >> L) {
        if(A == -1 && L == -1) return 0;
        int k = A;
        int i = 0;
        while (k > 1 && k <= L) {
            if (k%2) k = 3*k+1;
            else k /= 2;
            i++;
        }
        if (k == 1) i++;
        cout << "Case " << ++t << ": A = " << A << ", limit = " << L << ", number of terms = " << i << endl;
	}
}

