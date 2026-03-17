#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  void solve(std::istream& in, std::ostream& out) {
    long long n, k, m;
    in >> n >> k >> m;
    std::vector<long long> t(k);
    for (long long i = 0; i < k; ++i) in >> t[i];
    long long max_points = n * (k + 1);
    std::vector<long long> dp(max_points + 1,
                              std::numeric_limits<long long>::max());
    auto next_dp = dp;
    std::sort(t.begin(), t.end());
    std::partial_sum(t.begin(), t.end(), t.begin());
    dp[0] = 0;
    for (long long i = 0; i < n; ++i) {
      std::fill(next_dp.begin(), next_dp.end(),
                std::numeric_limits<long long>::max());
      for (long long j = 0; j <= max_points; ++j) {
        if (dp[j] < std::numeric_limits<long long>::max()) {
          for (long long l = 0; l < k; ++l) {
            if (dp[j] + t[l] <= m) {
              auto points = j + ((l == k - 1) ? (k + 1) : (l + 1));
              next_dp[points] = std::min(next_dp[points], dp[j] + t[l]);
            }
          }
          next_dp[j] = std::min(dp[j], next_dp[j]);
        }
      }
      std::swap(dp, next_dp);
    }
    out << prev(std::find_if(dp.rbegin(), dp.rend(),
                             [](long long x) {
                               return x < std::numeric_limits<long long>::max();
                             })
                    .base()) -
               dp.begin()
        << '\n';
  }
};
void solve(std::istream& in, std::ostream& out) {
  out << std::setprecision(12);
  Solution solution;
  solution.solve(in, out);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  istream& in = cin;
  ostream& out = cout;
  solve(in, out);
  return 0;
}
