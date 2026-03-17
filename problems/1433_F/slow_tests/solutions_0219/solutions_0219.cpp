#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
const long long infinity = 1000000000000000000;
bool do_debug = false;
template <typename T>
ostream& operator<<(ostream& os, vector<T>& v) {
  for (auto element : v) {
    os << element << " ";
  }
  return os;
}
template <typename T, typename S>
ostream& operator<<(ostream& os, pair<T, S>& p) {
  os << "(" << p.first << ", " << p.second << ")";
  return os;
}
template <typename T>
ostream& operator<<(ostream& os, set<T>& v) {
  auto endit = v.end();
  endit--;
  os << "[";
  for (auto it = v.begin(); it != v.end(); it++) {
    os << *it;
    if (it != endit) {
      os << ", ";
    }
  }
  os << "]";
  return os;
}
template <typename T, typename S>
ostream& operator<<(ostream& os, map<T, S>& v) {
  auto endit = v.end();
  endit--;
  os << "{";
  for (auto it = v.begin(); it != v.end(); it++) {
    os << "(" << (*it).first << " : " << (*it).second << ")";
    if (it != endit) {
      os << ", ";
    }
  }
  os << "}";
  return os;
}
void solve() {
  int nr, nc, div;
  cin >> nr >> nc >> div;
  int lim = nc / 2;
  vector<vector<int>> v(nr, vector<int>(nc));
  vector<vector<bool>> subset_sums(nr, vector<bool>(4901, false));
  vector<vector<int>> mod_values(nr, vector<int>(div, -1));
  vector<int> counts(4901, 1000);
  vector<vector<int>> dp(nr, vector<int>(div, -1));
  for (long long i = 0; i < nr; i++) {
    for (long long j = 0; j < nc; j++) {
      cin >> v[i][j];
    }
  }
  for (long long i = 0; i < nr; i++) {
    subset_sums[i][0] = true;
    counts = vector<int>(4901, 1000);
    counts[0] = 0;
    for (long long j = 0; j < nc; j++) {
      vector<bool> updated_subset_sums(4901, false);
      vector<int> updated_counts(4901, 1000);
      for (long long k = 0; k < 4901; k++) {
        if (subset_sums[i][k] && (counts[k] + 1 <= lim)) {
          updated_subset_sums[k + v[i][j]] = true;
          updated_counts[k + v[i][j]] = counts[k] + 1;
        }
      }
      for (long long k = 0; k < 4901; k++) {
        if (updated_subset_sums[k]) {
          subset_sums[i][k] = true;
        }
        counts[k] = min(counts[k], updated_counts[k]);
      }
    }
    for (long long k = 0; k < 4901; k++) {
      if (subset_sums[i][k]) {
        mod_values[i][k % div] = max(mod_values[i][k % div], (int)k);
      }
    }
  }
  for (long long i = 0; i < div; i++) {
    dp[0][i] = mod_values[0][i];
  }
  for (long long i = 1; i < nr; i++) {
    for (long long j = 0; j < div; j++) {
      for (long long k = 0; k < div; k++) {
        if (dp[i - 1][k] != -1 && mod_values[i][j] != -1) {
          int x = (j + k) % div;
          dp[i][x] = max(dp[i][x], mod_values[i][j] + dp[i - 1][k]);
        } else if (dp[i - 1][k] != -1) {
          int x = k;
          dp[i][x] = max(dp[i][x], dp[i - 1][k]);
        } else if (mod_values[i][j] != -1) {
          int x = j;
          dp[i][x] = max(dp[i][x], mod_values[i][j]);
        }
      }
    }
  }
  cout << dp[nr - 1][0] << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int q = 1;
  while (q-- > 0) {
    solve();
  }
  return 0;
}
