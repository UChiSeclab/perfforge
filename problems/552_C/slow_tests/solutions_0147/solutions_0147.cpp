#include <bits/stdc++.h>
using namespace std;
void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
template <typename T, typename V>
void __print(const pair<T, V> &x) {
  cerr << '{';
  __print(x.first);
  cerr << ',';
  __print(x.second);
  cerr << '}';
}
template <typename T>
void __print(const T &x) {
  int f = 0;
  cerr << '{';
  for (auto &i : x) cerr << (f++ ? "," : ""), __print(i);
  cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v)) cerr << ", ";
  _print(v...);
}
struct _ {
  ios_base::Init i;
  _() { ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL); }
} _;
int dx[] = {-1, 0, 1, 0, -1, -1, 1, 1};
int dy[] = {0, 1, 0, -1, -1, 1, 1, -1};
int main() {
  long long w, m;
  cin >> w >> m;
  if (w == 2) {
    cout << "YES";
    return 0;
  }
  vector<pair<long long, long long>> x;
  long long lim = 1;
  while ((lim <= m) and (lim <= (1e18 / w))) lim *= w;
  if (lim <= (1e18 / w)) lim *= w;
  for (long long mask = 0; mask <= (1ll << 30); mask++) {
    long long val = 0;
    bool flg = true;
    for (long long j = 0; j <= 30; j++) {
      if ((mask & (1ll << j)) != 0) {
        long long ex = pow(w, j);
        if (val > lim - ex) {
          flg = false;
          break;
        }
        val += ex;
      }
    }
    if (flg == false) break;
    x.push_back({val, mask});
  }
  sort(x.begin(), x.end());
  for (long long y = 0; y <= (1ll << 30); y++) {
    long long yval = 0;
    bool flg = true;
    for (long long j = 0; j <= 30; j++) {
      if ((y & (1ll << j)) != 0) {
        long long ex = pow(w, j);
        if (yval > m) {
          flg = false;
          break;
        }
        yval += ex;
      }
    }
    if (flg == false) break;
    auto it = lower_bound(x.begin(), x.end(), make_pair(m + yval, -1ll));
    if (it == x.end()) continue;
    if ((*it).first != m + yval) continue;
    if (((*it).second & y) != 0) continue;
    cout << "YES";
    return 0;
  }
  cout << "NO";
  return 0;
}
