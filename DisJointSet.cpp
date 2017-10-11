#include "DisJointSet.h"
using namespace std;
int DisJointSet::find(int n) {
  if (parent[n] > 0) {
    return find(parent[n]);
  } else
    return n;
}
void DisJointSet::Union(int root1, int root2) {
  if (root1 < root2) {
    parent[root2] = root1;
  }
}
void DisJointSet::insert(int x) {
  if (parent[x] != 0) {
    cout << "it has been used!" << endl;
    return;
  } else {
    parent[x] = -1;
    return;
  }
}
void DisJointSet::insert(int root, int x) {
  if (parent[x] != 0) {
    cout << "is has been used!" << endl;
    return;
  } else {
    if (parent[root] == 0) {
      cout << "We don't have the root" << endl;
    } else {
      parent[x] = -1;
    }
  }
}
