#include <bits/stdc++.h>
#define MOD 1000000007
#define MAXM 100+5
using namespace std;

long long int n, m;
long long int matrix_A[MAXM][MAXM], matrix_B[MAXM][MAXM];
long long int dp_A[MAXM], dp_B[MAXM];

void arr_multi() {
  for (int i = 1; i <= m; i++) {
    dp_B[i] = 0;
    for (int k = 1; k <= m; k++) {
      dp_B[i] += dp_A[k] * matrix_A[k][i]; 
      dp_B[i] %= MOD;
    }
  }
  for (int i = 1; i <= m; i++) {
    dp_A[i] = dp_B[i];
  }
}

void matrix_multi() {
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= m; j++) {
      matrix_B[i][j] = 0;
      for (int k = 1; k <= m; k++) {
        matrix_B[i][j] += matrix_A[i][k] * matrix_A[k][j];
        matrix_B[i][j] %= MOD;
      }
    }
  }
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= m; j++) {
      matrix_A[i][j] = matrix_B[i][j];
    }
  }
}

int main() {
  cin >> n >> m;
  for (int i = 1; i <= m; i++) dp_A[i] = 1;
  matrix_A[1][1] = matrix_A[m][1] = 1;
  for (int i = 1; i < m; i++) matrix_A[i][i+1] = 1;
  for (long long int i = 1; i <= n; i *= 2) {
    if (n & i) arr_multi();
    matrix_multi();
  }
  cout << dp_A[m] << endl;
} 
