//Edit Distance In Numbers: bitmask
#include <iostream>
#include <cmath>

using namespace std;

unsigned long long int A, B, a, b;
int pA, pB, ans;

int main() {
    cin >> A >> B;
    for (a=A;a;a>>=1){ pA++,ans++; }
    for (b=B;b;b>>=1){ pB++,ans++; }
    pA=max(pA-1,0);
    pB=max(pB-1,0);
    for (; !((((1<<pA)&A)>>pA)^(((1<<pB)&B)>>pB)) && pA*pB; pA--, pB--) { ans-=2; }
    cout << ans << endl;
}
