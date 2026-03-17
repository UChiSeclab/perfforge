#include <bits/stdc++.h>
using namespace std;
void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
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
int _ = 1;
int f(set<int> &s, int j) {
  if (j < 0) return 0;
  if (s.size() == 0) return 0;
  set<int> s0;
  set<int> s1;
  long long mask = ((long long)1 << j);
  for (auto &x : s) {
    if ((x & mask) == 0)
      s0.insert(x);
    else
      s1.insert(x);
  }
  if (s0.size() <= 1) {
    return f(s1, j - 1);
  } else if (s1.size() <= 1) {
    return f(s0, j - 1);
  } else {
    return min(s0.size() - 1 + f(s1, j - 1), s1.size() - 1 + f(s0, j - 1));
  }
}
void solve() {
  int n;
  cin >> n;
  set<int> s;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    s.insert(x);
  }
  cout << f(s, 35) << '\n';
}
int32_t main(int32_t argc, char **argv) {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  while (_--) solve();
}
