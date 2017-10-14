// MEMOIZATION OF MATCHAIN
#include <iostream>
using namespace std;
void print(int i, int j, int **p) {
  if (i == j)
    return;
  cout << p[i][j] << " ";
  print(i, p[i][j], p);
  print(p[i][j] + 1, j, p);
}
int min(int i, int j, int **me, int **re, int *r) {
  if (i == j) {
    me[i][j] = 0;
    return 0;
  } else if (me[i][j] != 30000)
    return me[i][j];
  else if (me[i][j] == 30000) {
    int tmp = 30000;
    for (int p = i; p < j; ++p) {
      int f = min(i, p, me, re, r) + min(p + 1, j, me, re, r) +
              r[i] * r[p + 1] * r[j + 1];
      if (f < tmp) {
        tmp = f;
        re[i][j] = p;
      }
    }
    me[i][j] = tmp;
    return me[i][j];
  }
}
int main() {
  int n;
  cin >> n;
  int **memo; // as the memoization
  memo = new int *[n + 2];
  for (int i = 0; i < n + 2; ++i) // use 1 to n
  {
    memo[i] = new int[n + 2];
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      memo[i][j] = 30000;
    }
    memo[i][i] = 0;
  }
  int *r = new int[n + 2];         // save the memory of the matrix
  for (int i = 1; i <= n + 1; ++i) // 1 to n is the num of row
  {
    cin >> r[i];
  }
  int **result;
  result = new int *[n + 2];      // as write down the result
  for (int i = 0; i < n + 2; ++i) // use 1 to n
  {
    result[i] = new int[n + 2];
  }
  cout << min(1, n, memo, result, r);
  print(1, n, result);
}
