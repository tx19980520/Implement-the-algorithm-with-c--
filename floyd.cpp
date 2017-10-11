#include <iostream>
using namespace std;
int main() {
  cout << "your node" << endl;
  int n;
  cin >> n;
  int **marix;
  int **path;
  path = new int *[n + 1];
  for (int i = 1; i <= n + 1; ++i) {
    path[i] = new int[n + 1];
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      path[i][j] = -1;
    }
  }
  marix = new int *[n + 1];
  for (int i = 1; i <= n + 1; ++i) {
    marix[i] = new int[n + 1];
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      cout << i << " " << j << endl;
      cin >> marix[i][j];
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (j == i)
        continue;
      for (int k = 1; k <= n; ++k) {
        if (k == i)
          continue;
        else if (k == j)
          continue;
        else {
          if (marix[j][k] > marix[j][i] + marix[i][k]) {
            marix[j][k] = marix[j][i] + marix[i][k];
            path[j][k] = i;
          }
        }
      }
    }
  }
  cout << "length:" << endl;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      cout << marix[i][j] << "  ";
    }
    cout << endl;
  }
  cout << "path:" << endl;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      cout << path[i][j] << "  ";
    }
    cout << endl;
  }
}
