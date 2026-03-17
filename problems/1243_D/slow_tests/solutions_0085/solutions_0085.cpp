#include <bits/stdc++.h>
using namespace std;
string to_string(bool x) { return x ? "true" : "false"; }
string to_string(char x) { return string(1, x); }
string to_string(string s) { return '"' + s + '"'; }
string to_string(const char *s) { return to_string((string)s); }
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int> >;
using vpii = vector<pii>;
using ld = long double;
using vs = vector<string>;
mt19937_64 rnd((unsigned long)chrono::high_resolution_clock::now()
                   .time_since_epoch()
                   .count());
const int MAXN = 1e5 + 9;
vvi gg;
int n, m;
set<int> st;
bool used[MAXN];
void bfs(int v) {
  queue<int> qq;
  used[v] = 1;
  qq.push(v);
  while (!qq.empty()) {
    int v = qq.front();
    qq.pop();
    int pos = 0;
    st.erase(v);
    sort((gg[v]).begin(), (gg[v]).end());
    set<int> tmp;
    for (int x : st) {
      while (pos < (int)(gg[v]).size() && gg[v][pos] < x) {
        pos++;
      }
      if (pos == (int)(gg[v]).size() || gg[v][pos] > x) {
        assert(used[x] == 0);
        used[x] = 1;
        qq.push(x);
        tmp.insert(x);
      }
    }
    for (auto x : tmp) {
      st.erase(x);
    }
  }
}
void solve() {
  cin >> n >> m;
  gg.resize(n);
  for (int i = 0; i < n; i++) st.insert(i);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    gg[a].push_back(b);
    gg[b].push_back(a);
  }
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (!used[i]) {
      bfs(i);
      cnt++;
    }
  }
  cout << cnt - 1 << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.setf(ios::fixed | ios::showpoint);
  cout.precision(12);
  cerr.setf(ios::fixed | ios::showpoint);
  cerr.precision(4);
  solve();
  return 0;
}
