#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<ii>;
const int mod = 1e9 + 7;
int add(int a, int b, int m = mod) { return a + b < mod ? a + b : a + b - mod; }
int mul(ll a, ll b, int m = mod) { return a * b % mod; }
int ex(int a, int b, int m = mod) {
  int r = 1;
  while (b > 0) {
    if (b & 1) r = mul(r, a);
    a = mul(a, a);
    b >>= 1;
  }
  return r;
}
const ll inf = 1e15;
const int maxn = 110;
bool vis[2][maxn][maxn][maxn];
ll memo[2][maxn][maxn][maxn];
bool vis2[maxn][maxn];
ll memo2[maxn][maxn];
int a[maxn];
string s;
ll calc_2(int, int);
ll calc(bool c, int l, int r, int cnt) {
  if (cnt == 0) return calc_2(l, r);
  if (vis[c][l][r][cnt]) return memo[c][l][r][cnt];
  ll& ans = memo[c][l][r][cnt] = -inf;
  for (int i = l; i <= r; ++i) {
    if (s[i] == '0' + c) {
      ans = max(ans, calc_2(l, i - 1) + calc(c, i + 1, r, cnt - 1));
    }
  }
  vis[c][l][r][cnt] = 1;
  return ans;
}
ll calc_2(int l, int r) {
  if (l > r) return 0;
  if (vis2[l][r]) return memo2[l][r];
  ll& ans = memo2[l][r] = -inf;
  for (int i = 1; i <= r - l + 1; ++i) {
    for (int d = 0; d < 2; ++d) {
      ans = max(ans, a[i] + calc(d, l, r, i));
    }
  }
  vis2[l][r] = 1;
  return ans;
}
class Solver {
 public:
  void solveOne(istream& in, ostream& out) {
    int n;
    in >> n;
    in >> s;
    for (int i = 1; i <= n; ++i) in >> a[i];
    out << calc_2(0, n - 1) << '\n';
  }
  void solve(istream& in, ostream& out) {
    out.precision(10);
    out << fixed;
    int testNumber = 1;
    for (int tc = 0; tc < testNumber; ++tc) {
      solveOne(in, out);
    }
  }
};
int main() {
  Solver solver;
  string file = "";
  if (!file.empty()) {
    ifstream in(file + ".in");
    ofstream out(file + ".out");
    in.tie(nullptr);
    in.exceptions(in.failbit);
    solver.solve(in, out);
  } else {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solver.solve(cin, cout);
  }
  return 0;
}
