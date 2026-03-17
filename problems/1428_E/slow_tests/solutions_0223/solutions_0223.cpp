#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
template <typename T, typename TT>
inline ostream &operator<<(ostream &os, const pair<T, TT> &t) {
  return os << t.first << " " << t.second;
}
template <typename T>
inline ostream &operator<<(ostream &os, const vector<T> &t) {
  for (auto i : t) os << i << " ";
  return os;
}
template <typename T>
inline ostream &operator<<(ostream &os, const set<T> &t) {
  for (auto i : t) os << i << " ";
  return os;
}
template <typename T1, typename T2>
inline ostream &operator<<(ostream &os, const map<T1, T2> &t) {
  for (auto i : t) os << i.first << " : " << i.second << '\n';
  return os;
}
template <typename T>
inline istream &operator>>(istream &is, vector<T> &v) {
  for (T &t : v) is >> t;
  return is;
}
template <typename T1, typename T2>
inline istream &operator>>(istream &is, vector<pair<T1, T2>> &v) {
  for (pair<T1, T2> &t : v) is >> t.first >> t.second;
  return is;
}
const long long mod = 1e9 + 7;
inline long long calc(long long l, long long p) {
  long long b = l / p, t = l % p;
  return b * b * (p - t) + (b + 1) * (b + 1) * t;
}
struct cmp {
  bool operator()(const pair<long long, long long> &a,
                  const pair<long long, long long> &b) {
    return calc(a.first, a.second) - calc(a.first, a.second + 1) <
           calc(b.first, b.second) - calc(b.first, b.second + 1);
  }
};
void solve() {
  long long n, k;
  cin >> n >> k;
  vector<long long> v(n);
  cin >> v;
  priority_queue<pair<long long, long long>, vector<pair<long long, long long>>,
                 cmp>
      pq;
  for (auto x : v) pq.push({x, 1});
  for (int i = 0; i < k - n; i++) {
    auto tp = pq.top();
    pq.pop();
    ;
    pq.push({tp.first, tp.second + 1});
  }
  long long ans = 0;
  while (!pq.empty()) {
    auto tp = pq.top();
    pq.pop();
    ans += calc(tp.first, tp.second);
  }
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ;
  long long T = 1;
  while (T--) {
    solve();
  }
  return 0;
}
