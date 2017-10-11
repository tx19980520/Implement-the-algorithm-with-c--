#include <iostream>
using namespace std;
int main() {
  int n;
  cin >> n;
  int *r = new int[n + 2];         // save the memory of the matrix
  for (int i = 1; i <= n + 1; ++i) // 1 to n is the num of row
  {
    cin >> r[i];
  }
  int **m;
  m = new int *[n + 2];
  for (int i = 0; i < n + 2; ++i) // use 1 to n
  {
    m[i] = new int[n + 2];
  }
  for (int i = 0; i < n + 2; ++i) {
    for (int j = 0; j < n + 2; ++j) {
      m[i][j] = 30000;
    }
    m[i][i] = 0;
  }
  for (int i = 1; i < n; ++i) {
    for (int j = 1; j <= n - i; ++j) // the first
    {
      int k = j + i; // the second
      for (int p = j; p < k; ++p) {
        if (m[j][k] > m[j][p] + m[p + 1][k] + r[j] * r[p + 1] * r[k + 1])
          m[j][k] = m[j][p] + m[p + 1][k] + r[j] * r[p + 1] * r[k + 1];
      }
    }
  }
  cout << m[1][n];
}
