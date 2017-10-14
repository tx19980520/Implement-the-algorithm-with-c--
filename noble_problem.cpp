#include <iostream>
#include <stack>
using namespace std;
int main() {
  stack<int> people;
  int num;
  cout << "confirm the num of people" << endl;
  cin >> num;
  for (int i = 1; i <= num; ++i) {
    people.push(i);
  }
  cout << "start to describe the circle:" << endl;
  int **relation = new int *[num + 1];
  for (int i = 1; i <= num; ++i) {
    relation[i] = new int[num + 1];
  }
  int n = 0;
  while (n != -1) {
    int tmp1, tmp2;
    cout << "first" << endl;
    cin >> tmp1;
    cout << "second" << endl;
    cin >> tmp2;
    relation[tmp1][tmp2] = 1;
    cout << "wanna continue?(input -1 to quit)";
    cin >> n;
  }
  int a = people.top();
  people.pop();
  while (!people.empty()) {
    int tmp = people.top();
    people.pop();
    if (relation[tmp][a] == 0) // a can not be the noble.
    {
      a = tmp;
    } else if (relation[tmp][a] == 1) // tmp can't be the noble.
    {
      continue; // just for logic
    }
  }
  for (int i = 1; i <= num; ++i) {
    if (relation[a][i] != 0 || relation[i][a] != 1) {
      cout << "We don't have a noble";
      return 0;
    }
  }
  cout << a << "is the noble" << endl;
  return 0;
}
