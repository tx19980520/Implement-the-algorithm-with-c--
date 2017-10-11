#include <iostream>
#include <vector>
using namespace std;
struct Node {
  int you;
  int pre;
  int len;
};
struct path {
  int first;
  int second;
  int len;
};
int main() {
  cout << "confirm yuour num of nodes" << endl;
  int num;
  cin >> num;
  Node *all = new Node[num + 1];
  bool *get_in = new bool[num + 1];
  for (int i = i; i <= num; ++i) {
    get_in[i] = false;
  }
  vector<path> Paths;
  for (int i = 1; i <= num; ++i) {
    all[i].you = i;
    all[i].pre = -1;
    all[i].len = 30000;
  }
  int s = 0;
  while (s != -1) {
    path tmp;
    cout << "first:" << endl;
    cin >> tmp.first;
    cout << "second:" << endl;
    cin >> tmp.second;
    cout << "len:" << endl;
    cin >> tmp.len;
    cout << "continue or not ?(-1)" << endl;
    Paths.push_back(tmp);
    cin >> s;
  }
  Node tmp = all[1];
  int rest_itr = 1;
  all[tmp.you].len = 30000;
  for (int i = 0; i < Paths.size(); ++i) {
    if (Paths[i].first == 1) { // you are the start point!
      all[Paths[i].second].pre = 1;
      all[Paths[i].second].len = Paths[i].len;
    } else if (Paths[i].second == 1) {
      all[Paths[i].first].pre = tmp.you;
      all[Paths[i].first].len = Paths[i].len;
    }
  }
  int total = 0;
  while (rest_itr != num) {
    int mi = 30000;
    int min_pos;
    for (int i = 2; i <= num; ++i) {
      if (all[i].len < mi && all[i].pre != -1) {
        mi = all[i].len;
        min_pos = i;
      } // find the min length pos;
    }
    cout << rest_itr << ":" << min_pos << "length:" << mi << endl;
    get_in[min_pos] = true;
    rest_itr++;
    total += mi;
    all[min_pos].len = 30000;
    for (int i = 0; i < Paths.size(); ++i) {
      if (Paths[i].first == min_pos) {
        if (all[Paths[i].second].len > Paths[i].len &&
            get_in[Paths[i].second] != true) {
          all[Paths[i].second].pre = min_pos;
          all[Paths[i].second].len = Paths[i].len;
        }
      }
      if (Paths[i].second == min_pos) {
        if (all[Paths[i].first].len > Paths[i].len &&
            get_in[Paths[i].first] != true) {
          all[Paths[i].first].pre = min_pos;
          all[Paths[i].first].len = Paths[i].len;
        }
      }
    }
  }
  cout << "total:" << total << endl;
  return 0;
}
