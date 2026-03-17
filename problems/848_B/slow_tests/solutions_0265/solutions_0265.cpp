#include <bits/stdc++.h>
using namespace std;
struct dancer {
  int g;
  int p;
  int t;
  int id;
};
int n, xs, ys;
map<int, vector<dancer>> groups;
map<int, pair<int, int>> finalPos;
bool s1(dancer a, dancer b) {
  if (a.g != b.g) return a.g > b.g;
  if (a.g == 1)
    return a.p < b.p;
  else
    return a.p > b.p;
}
bool s2(dancer a, dancer b) {
  if (a.g != b.g) return a.g < b.g;
  if (a.g == 1)
    return a.p < b.p;
  else
    return a.p > b.p;
}
int main() {
  cin >> n >> xs >> ys;
  for (int i = 1; i <= n; i++) {
    int g, p, t;
    cin >> g >> p >> t;
    dancer d;
    d.p = p;
    d.g = g;
    d.t = t;
    d.id = i;
    groups[t - p].push_back(d);
  }
  for (pair<int, vector<dancer>> i : groups) {
    vector<dancer> sort1 = i.second;
    vector<dancer> sort2 = i.second;
    sort(sort1.begin(), sort1.end(), s1);
    sort(sort2.begin(), sort2.end(), s2);
    for (int j = 0; j < (int)sort1.size(); j++) {
      if (sort2[j].g == 1)
        finalPos[sort1[j].id] = make_pair(sort2[j].p, ys);
      else
        finalPos[sort1[j].id] = make_pair(xs, sort2[j].p);
    }
  }
  for (int i = 1; i <= n; i++) {
    cout << finalPos[i].first << " " << finalPos[i].second << endl;
  }
}
