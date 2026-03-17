#include <bits/stdc++.h>
using namespace std;
int n, w, h;
unordered_map<int, vector<pair<int, int>>> starts;
unordered_map<int, vector<pair<int, pair<int, int>>>> endss;
pair<int, int> results[100001];
int main() {
  cin >> n >> w >> h;
  for (int i = 0; i < n; i++) {
    int g, p, t;
    cin >> g >> p >> t;
    if (g == 1) {
      starts[p - t].push_back(make_pair(p + t, i));
      endss[p - t].push_back(make_pair(p - h, make_pair(p, h)));
    } else {
      starts[p - t].push_back(make_pair(-t - p, i));
      endss[p - t].push_back(make_pair(w - p, make_pair(w, p)));
    }
  }
  for (auto &a : starts) {
    sort(a.second.begin(), a.second.end());
  }
  for (auto &a : endss) {
    sort(a.second.begin(), a.second.end());
  }
  for (auto a : starts) {
    auto b = endss[a.first];
    for (int i = 0; i < a.second.size(); i++) {
      results[a.second[i].second] = b[i].second;
    }
  }
  for (int i = 0; i < n; i++) {
    printf("%d %d\n", results[i].first, results[i].second);
  }
  return 0;
}
