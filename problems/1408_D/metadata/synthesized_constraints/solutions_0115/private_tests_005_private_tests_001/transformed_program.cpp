#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9 + 7;
const long long longinf = 1LL << 60;
const long long mod = 1e9 + 7;
const long double eps = 1e-10;

template <typename T1, typename T2>
inline void chmin(T1 &a, T2 b) {
  if (a > b) a = b;
}

template <typename T1, typename T2>
inline void chmax(T1 &a, T2 b) {
  if (a < b) a = b;
}

// Check for large iterative range
void check_large_iterative_range(int x_max, int y_max) {
    if (x_max > 1000000 || y_max > 1000000) {
        cerr << "Warning: Large iterative range - excessive potential moves!" << endl;
        abort();
    }
}

// Check for large set operations
void check_large_set_operations(const set<pair<int, int>>& st) {
    if (st.size() > 1000000) {
        cerr << "Warning: Large set operations - excessive elements in the set!" << endl;
        abort();
    }
}

// Check for high coordinate values
void check_high_coordinates(pair<int, int> robber, const vector<pair<int, int>>& searchlights) {
    for (const auto& light : searchlights) {
        if (light.first - robber.first > 1000000 || light.second - robber.second > 1000000) {
            cerr << "Warning: High coordinate values requiring excessive moves!" << endl;
            abort();
        }
    }
}

void solve() {
  int n, m;
  cin >> n >> m;
  
  vector<pair<int, int>> P(n);
  vector<pair<int, int>> Q(m);

  for (int i = 0; i < n; i++) cin >> P[i].first >> P[i].second;
  for (int i = 0; i < m; i++) cin >> Q[i].first >> Q[i].second;

  set<pair<int, int>> st;

  for (int i = 0; i < n; i++) {
    check_high_coordinates(P[i], Q); // Check for high coordinate values

    for (int j = 0; j < m; j++) {
      int x = Q[j].first - P[i].first;
      int y = Q[j].second - P[i].second;
      if (x < 0 || y < 0) continue;
      st.insert({x, y});
    }
  }

  check_large_set_operations(st); // Check for large set operations

  multiset<long long> mostR;
  for (auto ele : st) mostR.insert(ele.second);

  int ans = inf;
  for (int i = 0; i <= 1000005; i++) {
    check_large_iterative_range(i, *mostR.rbegin()); // Check for large iterative range

    if (mostR.empty()) {
      chmin(ans, i);
      break;
    } else {
      chmin(ans, i + *mostR.rbegin() + 1);
    }
    for (auto itr = st.lower_bound({i, 0}); itr != st.upper_bound({i, inf}); itr++) {
      mostR.erase(mostR.find(itr->second));
    }
  }
  cout << ans << '\n';
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  while (T--) solve();
  return 0;
}