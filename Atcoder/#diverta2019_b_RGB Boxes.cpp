#include <iostream>
#define MAXN 3000
using namespace std;

int R, G, B, N;
long long int num[MAXN+5];

int main() {
  cin >> R >> G >> B >> N;
  num[0] = 1;
  for (int i = R; i <= N; i++) {
    num[i] += num[i-R];
  }
  for (int i = G; i <= N; i++) {
    num[i] += num[i-G];
  }
  for (int i = B; i <= N; i++) {
    num[i] += num[i-B];
  }
  cout << num[N] << endl;
}
