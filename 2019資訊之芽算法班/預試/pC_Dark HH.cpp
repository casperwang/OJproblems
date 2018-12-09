//pC: if-else
#include <iostream>
using namespace std;

int t, n, m;

int main() {
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n >> m;
        if (n%2) {
            cout << (6-m%4)%4+(m+(6-m%4)%4)/2+(n+(m+(6-m%4)%4)/2)/2 << endl;
        } else {
            cout << (4-m%4)%4+(m+(4-m%4)%4)/2+(n+(m+(4-m%4)%4)/2)/2 << endl;
        }
    }
}
