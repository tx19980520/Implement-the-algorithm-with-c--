#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
int main() {
  int num;
  cout << "num:" << endl;
  cin >> num;
  vector<int> prime;
  prime.clear();
  int num_of_prime = 0;
  int *all = new int[num + 1];
  for (int i = 1; i <= num; ++i) {
    all[i] = 0;
  }
  for (int i = 2; i <= num; ++i) {
    if (all[i] == 0) {
      prime.push_back(i);
      ++num_of_prime;
    }
    for (int j = 0; j < num_of_prime && prime[j] * i <= num; ++j) {
      all[prime[j] * i] = 1;
      if (i % prime[j] == 0)
        break;
    }
  }
  vector<int>::iterator itr;
  for (itr = prime.begin(); itr != prime.end(); ++itr) {
    cout << *itr << " ";
  }
}
