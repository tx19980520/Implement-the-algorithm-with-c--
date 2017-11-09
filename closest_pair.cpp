#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
typedef pair<int, int> node double quick_sort(node *n, int p, int q) {
  int pre_low = p;
  int pre_high = q;
  node x = n[low];
  if (q - p == 1) {
    if (n[q].first >= n[p].first)
      return;
    else {
      node tmp = n[q];
      n[q] = n[p];
      n[p] = tmp;
      return;
    }
  }
  if (p >= q)
    return;
  while (q != p) {
    while (n[q].first >= x.first && q > p) {
      --q;
    }
    if (p < q) {
      a[p] = a[q];
      ++p;
    }
    while (n[p].first < x.first && q > p) {
      ++p;
    }
    if (p < q) {
      n[q] = n[p];
      --q;
    }
  }
  quick_sort(n, mid + 1, pre_high);
  quick_sort(n, pre_low, mid - 1);
}
void Ylist(node *a, int low, int high) {
  int pre_low = low;
  int pre_high = high;
  node x = a[low];
  if (high - low == 1) {
    if (a[high].second >= a[low].second)
      return;
    else {
      node tmp = a[high];
      a[high] = a[low];
      a[low] = tmp;
      return;
    }
  }
  if (low >= high)
    return;
  while (low != high) {
    while (a[high].second >= x.second && high > low) {
      --high;
    }
    if (low < high) {
      a[low] = a[high];
      ++low;
    }
    while (a[low].second < x.second && high > low) {
      ++low;
    }
    if (low < high) {
      a[high] = a[low];
      --high;
    }
  }
  int mid = low;
  a[mid] = x;
  quick_sort(a, mid + 1, pre_high);
  quick_sort(a, pre_low, mid - 1);
}
double closest_pair(node *n, node *y, int p, int q) {
  if (q - p == 1) {
    double tmp = sqrt((n[p].first - n[q].first) * (n[p].first - n[q].first) +
                      (n[p].second - n[q].second) *
                          (n[p].second - n[q].second)) return tmp;
  }
  if (q - p == 3) {
    double tmp, t1, t2, t3;
    t1 = (n[p].first - n[q].first) * (n[p].first - n[q].first) +
         (n[p].second - n[q].second) * (n[p].second - n[q].second) // p,q
             t2 =
             (n[p].first - n[q - 1].first) * (n[p].first - n[q - 1].first) +
             (n[p].second - n[q - 1].second) *
                 (n[p].second - n[q - 1].second) // p,q-1
                 t3 =
                 (n[q - 1].first - n[q].first) * (n[q - 1].first - n[q].first) +
                 (n[q - 1].second - n[q].second) *
                     (n[q - 1].second - n[q].second) // q,q-1
                     tmp = (t1 > t2) ? t1 : t2;
    tmp = (tmp > t3) ? tmp : t3 return sqrt(tmp);
  } else {
    int m = (p + q) / 2 noide origin = n[m];
    double alpha = closest_pair(n, y, p, m) double beta =
        closest_pair(n, y, m + 1, q) double delta =
            [=]() {
              if (alpha > beta)
                return alpha;
              else
                return beta;
            } vector<node>
                T;
    T.clear();
    for (int i = 1; i <= num; ++i) {
      if (abs(y[i].first - origin.first) <= delta)
        T.push_back(y[i]);
    }
    int fdelta = 2 * delta;
    int T_size = T.size();
    for (int i = 0; i < T_size; ++i) {
      int tmp = (i + 7 > T_size) ? T_size : i + 7;
      for (int j = i + 1; j <= tmp; ++j) {
        double d = (T[i].first - T[j].first) * (T[i].first - T[j].first) +
                   (T[i].second - T[j].second) * (T[i].second - T[j].second);
        if (d < fdelta * fdelta) {
          fdelta = sqrt(d);
        }
      }
    }
    delta = (delta < fdelta) ? delta : fdelta;
    return delta;
  }
}
int main() {
  int num;
  cout << "confirm your num";
  cin >> num;
  node *p = new node[num + 1];
  node *y = new node[num + 1];
  for (int i = 1; i <= num; ++i) {
    cout << 'node' << i << ':' << endl;
    cin >> p[i].first >> p[i].second;
    y[i] = p[i];
  }
  quick_sort(p, 1, num);
  Ylist(y, 1, num);
  double delta = closest_pair(p, y, 1, num) cout << delta;
}
