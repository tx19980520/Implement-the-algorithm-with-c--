#include <iostream>
using namespace std;
int main() {
  cout << "complete backpack" << endl;
  cout << "your goods:" << endl;
  int num;
  cin >> num;
  int *value = new int[num + 1];
  int *price = new int[num + 1];
  for (int i = 1; i <= num; ++i) {
    cout << i << endl;
    cout << "value" << endl;
    cin >> value[i];
    cout << "price" << endl;
    cin >> price[i];
  }
  int cush;
  cout << "your cush" << endl;
  cin >> cush;
  int *p = new int[cush + 1];
  for (int i = 0; i < cush + 1; ++i) {
    p[i] = 0;
  }
  for (int i = 1; i <= num; ++i) {
    for (int j = 1; j <= cush; ++j) {
      if (j < price[i])
        continue;
      else {
        if (p[j] < p[j - price[i]] + value[i]) {
          p[j] = p[j - price[i]] + value[i];
        }
      }
    }
  }
  cout << p[cush];
}
