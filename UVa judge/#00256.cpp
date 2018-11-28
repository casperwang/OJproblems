//Quirksome Squares: trivial
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int n;
vector <int> num[5];

int main(){
    for (int i = 0; i < 100; i++) {
        if ((i/10+i%10)*(i/10+i%10) == i) num[1].push_back(i);
    }
    for (int i = 0; i < 10000; i++) {
        if ((i/100+i%100)*(i/100+i%100) == i) num[2].push_back(i);
    }
    for (int i = 0; i < 1000000; i++) {
        if ((i/1000+i%1000)*(i/1000+i%1000) == i) num[3].push_back(i);
    }
    for (int i = 0; i < 100000000; i++) {
        if ((i/10000+i%10000)*(i/10000+i%10000) == i) num[4].push_back(i);
    }
    while (cin >> n) {
        for (int i = 0; i < n; i++) cout << 0;
        cout << endl;
        for (int i = 1; i < num[n/2].size(); i++) {
            for (int j = 1; j < n-log10(num[n/2][i]); j++) {
                cout << 0;
            }
            cout << num[n/2][i] << endl;
        }
    }
}
