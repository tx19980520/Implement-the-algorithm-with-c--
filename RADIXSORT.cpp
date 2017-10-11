#include <iostream>
#include <vector>
using namespace std;
int main() {
  int max = 0;
  int num = 0;
  cout << "for your length" << endl;
  cin >> max;
  int *b = new int[max + 1];
  int f = 1;
  for (int i = 1; i <= max; ++i) {
    b[i] = f; // the first is 1
    f *= 10;
  }
  cout << "for your num" << endl;
  cin >> num;
  int *a = new int[num + 1];
  for (int i = 1; i <= num; ++i) {
    cout << i << endl;
    cin >> a[i];
  }
  vector<int> list[10];
  for (int i = 0; i < 10; ++i) {
    list[i].empty();
  }
  for (int i = 1; i <= max; ++i) // shuwei
  {
    for (int j = 1; j <= num; ++j) // shu
    {
      int m = a[j];
      m /= b[i];
      m %= 10;
      list[m].push_back(a[j]);
    }
    int g = 1;
    for (int m = 0; m <= 9; ++m) // for merge all
    {
      for (int n = 0; n < list[m].size(); ++n) {
        a[g] = list[m][n];
        ++g;
      }
      list[m].clear();
    }
  }

  for (int i = 1; i <= num; ++i) {
    cout << a[i] << " ";
  }
}
