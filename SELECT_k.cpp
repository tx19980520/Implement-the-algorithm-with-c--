#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int midsort(vector<int> a, int low, int high) {
  int min = 300000;
  int min_pos;
  for (int i = low; i <= high; ++i) {
    for (int j = i; j <= high; ++j) {
      if (a[j] < min) {
        min_pos = j;
        min = a[j];
      }
    }
    int tmp = a[min_pos];
    a[min_pos] = a[i];
    a[i] = tmp;
  }
  return a[(low + high) / 2];
}

int select(vector<int> a, int k) {
  vector<int> mids;
  for (int i = 0; i + 4 < a.size(); i += 5) // 5 elements for a quad
  {
    int m = midsort(a, i, i + 4);
    mids.push_back(m);
    cout << m;
  }
  int m_size = (mids.size() % 2 == 1) ? (mids.size() + 1) / 2 : mids.size() / 2;
  int mm = select(mids, m_size);
  vector<int> vecs[3];
  for (int i = 0; i < a.size(); ++i) {
    if (a[i] < mm)
      vecs[0].push_back(a[i]);
    else if (a[i] == mm)
      vecs[1].push_back(a[i]);
    else if (a[i] > mm)
      vecs[2].push_back(a[i]);
  }
  if (vecs[0].size() >= k)
    return select(vecs[0], k);
  else if (vecs[1].size() + vecs[0].size() >= k)
    return mm;
  else if (vecs[0].size() + vecs[1].size() < k)
    return select(vecs[2], k - vecs[0].size() - vecs[1].size());
}
int main() {
  vector<int> a;
  int n;
  cout << "num:" << endl;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    int tmp;
    cin >> tmp;
    a.push_back(tmp);
  }
  int k;
  cout << "choose k:" << endl;
  cin >> k;
  cout << select(a, k);
}
