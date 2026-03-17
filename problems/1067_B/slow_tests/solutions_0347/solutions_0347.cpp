#include <bits/stdc++.h>
using namespace std;
inline long long input() {
  long long n;
  cin >> n;
  return n;
}
long long pw(long long a, long long b, long long md) {
  return (!b ? 1
             : (b & 1 ? a * pw(a * a % md, b / 2, md) % md
                      : pw(a * a % md, b / 2, md) % md));
}
const long long MAXN = 2e5 + 10;
const long long INF = 8e18;
const long long MOD = 1e9 + 7;
vector<long long> adj[MAXN];
long long n, k, v, u, mark[MAXN], cnt[MAXN];
void solve(vector<long long> vec) {
  if (vec.size() == 0) return;
  if (k == 0 && vec.size() != 1) {
    cout << "No" << '\n';
    exit(0);
  }
  set<long long> st;
  k--;
  for (long long i : vec) mark[i] = 1;
  for (long long v : vec) {
    for (long long u : adj[v]) {
      if (!mark[u]) {
        cnt[u]++;
        st.insert(u);
      }
    }
  }
  solve(vector<long long>(st.begin(), st.end()));
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
  ;
  cin >> n >> k;
  for (long long i = 1; i < n; i++) {
    cin >> v >> u;
    adj[v].push_back(u);
    adj[u].push_back(v);
  }
  vector<long long> vec;
  for (long long i = 1; i <= n; i++) {
    if (adj[i].size() == 1) {
      vec.push_back(i);
    }
  }
  solve(vec);
  for (long long i = 1; i <= n; i++) {
    if (cnt[i] < 3 && cnt[i] != 0) return cout << "No" << '\n', 0;
  }
  if (accumulate(cnt, cnt + MAXN, 0) != n - 1) return cout << "No" << '\n', 0;
  if (k != -1) return cout << "No" << '\n', 0;
  cout << "Yes" << '\n';
  return 0;
}
