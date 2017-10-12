#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
int main() {
  int num;
  cout << "confirm you num" << endl;
  cin >> num;
  vector<int> prime;
  prime.clear();
  int num_of_prime = 0;
  int *all = new int[num + 1];
  for (int i = 1; i <= num; ++i) {
    all[i] = i;
  }
  for (int i = 2; i <= num; ++i) {
    int bound = (int)sqrt(i) + 1;
    if (num_of_prime == 0) {
      prime.push_back(i);
      for (int m = 1; m * i <= num; ++m) {
        all[m * i] = -1;
      }
      ++num_of_prime;
    } else if (all[i] == -1)
      continue;
    else {
      for (int j = 0; j < num_of_prime; ++j) {
        if (i % prime[j] == 0) {
          break;
        } else if (prime[j] >= bound) {
          prime.push_back(i);
          for (int m = 1; m * i <= num; ++m) {
            all[m * i] = -1;
          }
          ++num_of_prime;
          break;
        }
      }
    }
  }
  vector<int>::iterator itr;
  for (itr = prime.begin(); itr != prime.end(); ++itr) {
    cout << *itr << " ";
  }
}
