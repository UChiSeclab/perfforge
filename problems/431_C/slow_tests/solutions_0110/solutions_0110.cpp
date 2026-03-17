#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;
template <typename T>
using pair2 = pair<T, T>;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
using mii = map<int, int>;
using mll = map<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
struct Comp {
  bool operator()(const std::pair<int, int> &a, const std::pair<int, int> &b) {
    if (a.first != b.first) {
      return a.first > b.first;
    }
    return a.second < b.second;
  }
};
bool sortbysec(const pair<int, int> &a, const pair<int, int> &b) {
  return (a.second < b.second);
}
int dp[1001][1001];
int getval(int n, int k, int d, int m) {
  if (n < 0) {
    return 0;
  }
  if (dp[n][m] != -1) {
    return dp[n][m];
  }
  if (n == 0) {
    if (m >= d) {
      return 1;
    }
    return 0;
  }
  int ans = 0;
  for (int i = 1; i <= k; i++) {
    ans += getval(n - i, k, d, max(m, i));
    ans %= 1000000007;
  }
  ans %= 1000000007;
  return dp[n][m] = ans;
}
void solve() {
  memset((dp), (-1), sizeof(dp));
  int n, k, d;
  cin >> n >> k >> d;
  cout << getval(n, k, d, 0);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  solve();
}
