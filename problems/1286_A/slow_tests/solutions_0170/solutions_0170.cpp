#include <bits/stdc++.h>
using namespace std;
template <class C>
void min_self(C &a, C b) {
  a = min(a, b);
}
template <class C>
void max_self(C &a, C b) {
  a = max(a, b);
}
long long mod(long long n, long long m = 1000000007) {
  n %= m, n += m, n %= m;
  return n;
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
struct custom_hash {
  static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }
  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM =
        chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};
unordered_map<long long, int, custom_hash> safe_map;
const int MAXN = 105;
const int LOGN = 21;
const long long INF = 1e14;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int dp[MAXN][MAXN][MAXN][2];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector<int> p(n + 1);
  set<int> st;
  for (int i = 1; i <= n; i++) st.insert(i);
  for (int i = 1; i <= n; i++) {
    cin >> p[i];
    st.erase(p[i]);
  }
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= n; j++)
      for (int k = 0; k <= n; k++) dp[i][j][k][0] = dp[i][j][k][1] = 1000000007;
  int even = 0, odd = 0;
  for (auto x : st) {
    if (x % 2 == 0)
      even++;
    else
      odd++;
  }
  dp[0][even][odd][0] = 0;
  dp[0][even][odd][1] = 0;
  for (int i = 1; i <= n; i++) {
    if (p[i] != 0) {
      int now = p[i] % 2;
      for (int ev = 0; ev <= n; ev++) {
        for (int od = 0; od <= n; od++) {
          for (int j = 0; j <= 1; j++) {
            dp[i][ev][od][now] = min(dp[i][ev][od][now],
                                     dp[i - 1][ev][od][j] + (j == now ? 0 : 1));
          }
        }
      }
    } else {
      for (int ev = 0; ev <= n; ev++) {
        for (int od = 0; od <= n; od++) {
          if (ev > 0) {
            dp[i][ev - 1][od][0] =
                min(dp[i][ev - 1][od][0], dp[i - 1][ev][od][0]);
            dp[i][ev - 1][od][0] =
                min(dp[i][ev - 1][od][0], dp[i - 1][ev][od][1] + 1);
          }
          if (od > 0) {
            dp[i][ev][od - 1][1] =
                min(dp[i][ev][od - 1][1], dp[i - 1][ev][od][0] + 1);
            dp[i][ev][od - 1][1] =
                min(dp[i][ev][od - 1][1], dp[i - 1][ev][od][1]);
          }
        }
      }
    }
  }
  cout << min(dp[n][0][0][0], dp[n][0][0][1]);
  cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
  return 0;
}
