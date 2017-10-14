#include <iostream> //10-13 For showing the result of the program choosed,I has added some codes
using namespace std;
void print(int i, int j, int **p) {
  if (i == j)
    return;
  cout << p[i][j] << " ";
  print(i, p[i][j], p);
  print(p[i][j] + 1, j, p);
}
int main() {
  int n;
  cin >> n;
  int **result;
  result = new int *[n + 2];
  for (int i = 0; i < n + 2; ++i) // use 1 to n
  {
    result[i] = new int[n + 2];
  }
  for (int i = 1; i <= n; ++i)
    result[i][i] = 0;
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
      result[j][k] = -1;
      for (int p = j; p < k; ++p) {
        if (m[j][k] > m[j][p] + m[p + 1][k] + r[j] * r[p + 1] * r[k + 1]) {
          m[j][k] = m[j][p] + m[p + 1][k] + r[j] * r[p + 1] * r[k + 1];
          result[j][k] = p;
        }
        cout << "j:" << j << "  "
             << "k:" << k << "  " << result[j][k] << endl;
      }
    }
  }
  cout << m[1][n] << endl;
  print(1, n, result);
}
