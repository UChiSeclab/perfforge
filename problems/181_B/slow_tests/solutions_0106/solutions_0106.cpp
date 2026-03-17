#include <bits/stdc++.h>
using namespace std;
int n, c;
vector<pair<int, int>> p;
set<pair<double, double>> s;
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    p.push_back({x, y});
    s.insert({x, y});
  }
  for (int i = 0; i < n; i++) {
    int x = p[i].first, y = p[i].second;
    for (int j = 0; j < n; j++) {
      if (j == i) continue;
      int x1 = p[j].first, y1 = p[j].second;
      double x2, y2;
      x2 = (double)(x + x1) / 2, y2 = (double)(y + y1) / 2;
      if (s.count({x2, y2})) c++;
    }
  }
  cout << c / 2;
}
