//Modular Multiplicative Inverse: math
#include <iostream>
using namespace std;

long long int a, n, x, y;

long long int exgcd(long long int a, long long int b, long long int &x, long long int &y) {
    if(b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long long int r = exgcd(b, a%b, x, y);
    long long int t = x;
    x = y;
    y = t - a/b*y;
    return r;
}

int main(){
    while (cin >> a >> n) {
        if (exgcd(a, n, x, y) != 1 || !(x%n)) {
            cout << "No Inverse" << endl;
        } else {
            while (x < 0) x += n;
            cout << x << endl;
        }
    }
}
