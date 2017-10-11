#include "DisJointSet.h"
#include <iostream>
#include <queue>
using namespace std;
struct Node {
  int start;
  int end;
  int len;
  friend bool operator<(const Node &n1, const Node &n2) {
    if (n1.len > n2.len)
      return true;
    else
      return false;
  }
} int main() {
  vector<node> path;
  priority_queue << Node >, vector<Node>> min;
  cout << "confirm the num of your nodes:" << endl;
  int num;
  cin >> num;
  DisJointSet *set = new DisJointSet(num);
  for (int i = 1; i <= num; ++i) {
    set.insert(i);
    cout << i << endl;
    node tmp;
    cout << "start" << endl;
    cin >> tmp.start;
    cout << "end" << endl;
    cin >> tmp.end;
    cout << "len" << endl;
    cin >> tmp.len;
    min.push(tmp);
    cout << endl;
  }
  while (!min.empty()) {
    Node tmp = min.top();
    min.pop();
    int u = set.find(tmp.start);
    int v = set.find(tmp.end);
    if (u != v) {
      set.union(tmp.start, tmp.end);
      path.push_back(tmp);
    }
  }
}
