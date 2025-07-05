#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using db = double;
const int N = 2e5L + 11;
int g[N], p[N], t[N];
map<int, vi> mp[3];
int x[N], y[N];
bool cmp(int i, int j) { return p[i] < p[j]; }
using pii = pair<int, int>;
bool cmp2(pii a, pii b) {
  if (a.second == b.second) return a.first < b.first;
  return a.second > b.second;
}

// Checkers
void check_large_iterative_range(int uniqueIntervalCount) {
    if (uniqueIntervalCount > 1000) {
        cerr << "Warning: Performance bottleneck condition triggered due to large iterative range!" << endl;
        abort();
    }
}

void check_vector_sorting(int vectorSize) {
    if (vectorSize > 100) {
        cerr << "Warning: Performance bottleneck condition triggered due to repeated vector sorting!" << endl;
        abort();
    }
}

void check_dense_collisions(int collidingDancers) {
    if (collidingDancers > 10) {
        cerr << "Warning: Performance bottleneck condition triggered due to dense collision points!" << endl;
        abort();
    }
}

int main() {
  ios ::sync_with_stdio(0);
  int n, w, h;
  cin >> n >> w >> h;
  for (int i = 1; i <= n; i++) {
    cin >> g[i] >> p[i] >> t[i];
    mp[g[i]][p[i] - t[i]].push_back(i);
    if (g[i] == 1) {
      x[i] = p[i];
      y[i] = h;
    } else {
      y[i] = p[i];
      x[i] = w;
    }
  }

  // Check the number of unique time intervals
  check_large_iterative_range(mp[1].size() + mp[2].size());

  for (int i = -100000; i <= 100000; i++)
    if (mp[1].count(i) && mp[2].count(i)) {

      // Check if vector sizes for sorting are large
      check_vector_sorting(mp[1][i].size());
      check_vector_sorting(mp[2][i].size());

      sort(mp[1][i].begin(), mp[1][i].end(), cmp);
      sort(mp[2][i].begin(), mp[2][i].end(), cmp);
      reverse(mp[2][i].begin(), mp[2][i].end());
      vector<pii> v;
      for (int j : mp[1][i]) v.push_back({x[j], y[j]});
      for (int j : mp[2][i]) v.push_back({x[j], y[j]});
      sort(v.begin(), v.end(), cmp2);

      // Check for dense collision points
      check_dense_collisions(v.size());

      int t = 0;
      for (int j : mp[2][i]) {
        x[j] = v[t].first;
        y[j] = v[t].second;
        t++;
      }
      for (int j : mp[1][i]) {
        x[j] = v[t].first;
        y[j] = v[t].second;
        t++;
      }
    }
  for (int i = 1; i <= n; i++) cout << x[i] << ' ' << y[i] << '\n';
  return 0;
}