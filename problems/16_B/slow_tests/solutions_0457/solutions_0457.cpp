#include <bits/stdc++.h>
using namespace std;
bool sortbysec(const pair<int, int> &a, const pair<int, int> &b) {
  return (a.second < b.second);
}
int main() {
  int i, j, k;
  int n, m, a = 0, b, c, d;
  int count = 0;
  int x, y, z;
  vector<pair<int, int> > data;
  cin >> n >> m;
  for (i = 0; i < m; i++) {
    cin >> x >> y;
    data.push_back(make_pair(x, y));
  }
  sort(data.begin(), data.end(), sortbysec);
  reverse(data.begin(), data.end());
  for (j = 0; j < m; j++) {
    while (data[j].first--) {
      if (count < n) {
        a += data[j].second;
        count++;
      } else
        break;
    }
  }
  cout << a;
  data.clear();
  return 0;
}
