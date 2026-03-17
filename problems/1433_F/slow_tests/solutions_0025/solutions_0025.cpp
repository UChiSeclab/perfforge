#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const long long INF = 5e18;
const double pi = acos(-1.0);
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
int gcd(int a, int b) { return (b == 0 ? a : gcd(b, a % b)); }
int lcm(int a, int b) { return (a * b) / gcd(a, b); }
inline long long mod(long long n, long long m) {
  long long ret = n % m;
  if (ret < 0) ret += m;
  return ret;
}
double rad(double x) { return x * pi / 180.0; }
bool isleft(pair<int, int> a, pair<int, int> b, pair<int, int> c) {
  int det = (b.first - a.first) * (c.second - a.second) -
            (c.first - a.first) * (b.second - a.second);
  if (det >= 0) return true;
  if (det < 0) return false;
  return false;
}
int exp(int a, int b) {
  int result = 1;
  while (b > 0) {
    if (b & 1) result = result * a % MOD;
    b >>= 1;
    a = a * a % MOD;
  }
  return result;
}
vector<int> calc(vector<int> &vet, int n) {
  int v[200000];
  for (int i = 0; i < 200000; i++) {
    v[i] = INF;
  }
  v[0] = 0;
  for (int &i : vet) {
    for (int j = 199999; j - i >= 0; j--) {
      if (v[j - i] != INF) {
        v[j] = min(v[j - i] + 1, v[j]);
      }
    }
  }
  vector<int> ans;
  for (int i = 0; i < 200000; i++) {
    if (v[i] <= n) {
      ans.push_back(i);
    }
  }
  return ans;
}
int memo[75][200200];
int n, m, k;
vector<vector<int>> adj;
int dp(int pos, int sum) {
  if (pos == n) {
    if (sum % k == 0)
      return sum;
    else
      return -INF;
  }
  int &x = memo[pos][sum];
  if (x != -1) return x;
  if (sum % k == 0) {
    x = sum;
  } else {
    x = -INF;
  }
  for (int &i : adj[pos]) {
    x = max(x, dp(pos + 1, sum + i));
  }
  return x;
}
void solve() {
  memset(memo, -1, sizeof(memo));
  cin >> n >> m >> k;
  vector<int> vet(m);
  vector<int> ans;
  adj.clear();
  for (int i = 0; i < n; i++) {
    for (int &j : vet) {
      cin >> j;
    }
    ans = calc(vet, m / 2);
    vector<int> newans;
    map<int, int> mapa;
    for (int &i : ans) {
      mapa[i % k] = max(i, mapa[i % k]);
    }
    for (auto &i : mapa) {
      newans.push_back(i.second);
    }
    ans = newans;
    adj.push_back(ans);
  }
  cout << dp(0, 0) << endl;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int t = 1;
  while (t--) {
    solve();
  }
}
