#include <bits/stdc++.h>
using namespace std;
int IT_MAX = 1 << 17;
int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const long long LL_INF = 0x0f3f3f3f3f3f3f3f;
const double PI = acos(-1);
const double ERR = 1e-10;
long long mod(long long a, long long m) {
  return (a + (abs(a) / m) * m + m) % m;
}
int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(0);
  cin.tie(0);
  long long n, m;
  cin >> n >> m;
  vector<unordered_set<long long>> gr(n);
  for (int i = 0; i < m; ++i) {
    long long a, b;
    cin >> a >> b;
    --a;
    --b;
    gr[a].insert(b);
    gr[b].insert(a);
  }
  vector<long long> to(n);
  unordered_set<long long> ver;
  ver.reserve(1024);
  ver.max_load_factor(0.25);
  long long ans = 0;
  unordered_set<long long> q;
  q.reserve(1024);
  q.max_load_factor(0.25);
  q.insert(0);
  unordered_set<long long> not_used;
  not_used.reserve(1024);
  not_used.max_load_factor(0.25);
  for (int i = 0; i < n; ++i) {
    not_used.insert(i);
  }
  not_used.erase(0);
  while (ver.size() != n) {
    long long cur_ver = *q.begin();
    q.erase(cur_ver);
    ver.insert(cur_ver);
    vector<long long> to_er;
    for (auto i : not_used) {
      if (ver.count(i) == 0) {
        if (gr[cur_ver].count(i)) {
          to[i]++;
        }
        if (to[i] != ver.size()) {
          to_er.push_back(i);
          q.insert(i);
        }
      }
    }
    for (auto i : to_er) {
      not_used.erase(i);
    }
    if (q.size() == 0 && ver.size() != n) {
      long long a = *not_used.begin();
      q.insert(a);
      not_used.erase(a);
      ++ans;
    }
  }
  cout << ans;
  return 0;
}
