#include <bits/stdc++.h>
using namespace std;
template <typename t1, typename t2>
inline bool upmax(t1 &a, t2 b) {
  if (a < (t1)b) {
    a = (t1)b;
    return true;
  } else
    return false;
}
template <typename t1, typename t2>
inline bool upmin(t1 &a, t2 b) {
  if (a > (t1)b) {
    a = (t1)b;
    return true;
  } else
    return false;
}
template <typename T>
inline bool pal(T &x) {
  int n = (int((x.size())));
  for (int i = 0; i < n / 2; i++) {
    if (x[i] != x[n - i - 1]) return 0;
  }
  return 1;
}
template <typename T>
inline T gcd(T a, T b) {
  return b ? gcd(b, a % b) : a;
}
template <typename T>
inline T lcm(T a, T b) {
  return a * (b / gcd(a, b));
}
template <typename T>
inline T sqr(T a) {
  return a * a;
}
int month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int dx[] = {1, 0, -1, 0, 1, 1, -1, -1};
int dy[] = {0, 1, 0, -1, 1, -1, 1, -1};
inline long long mp(long long a, long long b) { return (a << 31) + b; }
class PQ_compare {
 public:
  bool operator()(const int a, const int b) const { return 1; }
};
const int INF = 1000000404;
const long long LINF = 4000000000000000404ll;
const long long MOD = 1000000007ll;
const long double PI = acos(-1.0);
const long double EPS = 1e-9;
int SQ = 404;
vector<string> rotate(vector<string> a) {
  int n = (int((a.size())));
  int m = (int((a[0].size())));
  vector<string> b(m);
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      b[i] += "@";
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      b[j][n - i - 1] = a[i][j];
    }
  }
  return b;
}
vector<string> flipV(vector<string> a) {
  int n = (int((a.size())));
  int m = (int((a[0].size())));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m / 2; j++) {
      swap(a[i][j], a[i][m - j - 1]);
    }
  }
  return a;
}
vector<string> flipH(vector<string> a) {
  int n = (int((a.size())));
  int m = (int((a[0].size())));
  for (int i = 0; i < n / 2; i++) {
    for (int j = 0; j < m; j++) {
      swap(a[i][j], a[n - i - 1][j]);
    }
  }
  return a;
}
bool same(vector<string> &a, vector<string> &b) {
  for (int i = 0; i < (int((a.size()))); i++) {
    for (int j = 0; j < (int((a.size()))); j++) {
      if (a[i][j] != b[i][j]) return false;
    }
  }
  return true;
}
void solve() {
  int n, m;
  cin >> n;
  vector<string> a;
  vector<string> c;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    a.push_back(s);
  }
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    c.push_back(s);
  }
  int cm[] = {0, 1, 2, 3, 4};
  do {
    vector<string> b = a;
    for (int i = 0; i < 5; i++) {
      if (cm[i] == 0) {
        b = flipH(b);
      } else if (cm[i] == 4) {
        b = flipV(b);
      } else {
        for (int j = 0; j < cm[i]; j++) b = rotate(b);
      }
      if (same(b, c)) {
        cout << "Yes";
        return;
      }
    }
  } while (next_permutation(cm, cm + 5));
  cout << "No";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  while (t--) solve();
  return 0;
}
