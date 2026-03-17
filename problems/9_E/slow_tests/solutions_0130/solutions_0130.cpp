#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:268435456")
using namespace std;
template <typename T>
inline T abs(T a) {
  return ((a < 0) ? -a : a);
}
template <typename T>
inline T sqr(T a) {
  return a * a;
}
template <class T>
T gcd(T a, T b) {
  return a ? gcd(b % a, a) : b;
}
template <class T>
T lcm(T a, T b) {
  return a / gcd(a, b) * b;
}
template <class T>
T sign(T a) {
  return a > 0 ? 1 : (a < 0 ? -1 : 0);
}
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
const int dxK[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dyK[] = {0, 1, 1, 1, 0, -1, -1, -1};
const int dxKn[] = {-2, -1, 1, 2, 2, 1, -1, -2};
const int dyKn[] = {1, 2, 2, 1, -1, -2, -2, -1};
const int N = int(5e1) + 9;
const int M = int(3e3) + 9;
const int LOGN = 22;
const int SQN = 350;
const int MOD = int(1e9) + 7;
const int INF = 1e9 + 100;
const long long INF64 = 2e18;
const long double PI = 3.1415926535897932384626433832795;
const long double EPS = 1e-9;
int n, m;
bool mat[N][N];
int cnt[N];
int col[N];
void dfs(int v, int c) {
  col[v] = c;
  for (int i = 0; i < (int)(n); ++i)
    if (mat[v][i] && col[i] == -1) dfs(i, c);
}
void solve() {
  cin >> n >> m;
  if (n == 1) {
    if (m == 1) {
      cout << "YES\n0";
    } else if (m == 0) {
      cout << "YES\n1\n1 1";
    } else
      cout << "NO";
    return;
  }
  for (int i = 0; i < (int)(m); ++i) {
    int x, y;
    cin >> x >> y;
    --x, --y;
    mat[x][y] = mat[y][x] = true;
    ++cnt[x], ++cnt[y];
  }
  if (m > n) {
    cout << "NO";
    return;
  }
  vector<pair<int, int> > res;
  while (m < n) {
    ++m;
    memset(col, -1, sizeof col);
    for (int i = 0; i < (int)(n); ++i)
      if (col[i] == -1) dfs(i, i);
    bool fnd = false;
    for (int i = 0; i < (int)(n); ++i)
      for (int j = i + 1; j < n; ++j)
        if (cnt[i] < 2 && cnt[j] < 2 && (col[i] != col[j] || m == n)) {
          mat[i][j] = mat[j][i] = true;
          res.push_back(make_pair(i + 1, j + 1));
          ++cnt[i], ++cnt[j];
          j = i = n + 1;
          fnd = true;
        }
    if (!fnd) {
      cout << "NO";
      return;
    }
  }
  memset(col, -1, sizeof col);
  dfs(0, 0);
  for (int i = 0; i < (int)(n); ++i)
    if (col[i] == -1 || cnt[i] != 2) {
      cout << "NO";
      return;
    }
  cout << "YES\n";
  cout << (int)(res.size()) << endl;
  for (int i = 0; i < (int)((int)(res.size())); ++i)
    cout << res[i].first << ' ' << res[i].second << endl;
}
int main() {
  srand(time(NULL));
  cout << setprecision(10) << fixed;
  cerr << setprecision(10) << fixed;
  solve();
  return 0;
}
