#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e9 + 7;
const long long sz = 1e5 + 20;
const long long N = 7;
vector<pair<long long, long long> > edges;
long long c[N];
vector<long long> g[N];
long long rec() {
  set<pair<long long, long long> > s;
  for (long long i = 1; i < N; i++) {
    for (long long node : g[i]) {
      long long cu = c[i - 1], cv = c[node - 1];
      if (cu > cv) swap(cu, cv);
      s.insert(make_pair(cu, cv));
    }
  }
  return s.size();
}
void solve() {
  long long n, m;
  cin >> n >> m;
  long long u, v;
  for (long long i = 0; i < m; i++) {
    cin >> u >> v;
    if (u > v) swap(u, v);
    g[v].push_back(u), g[u].push_back(v);
  }
  if (n <= 6)
    cout << m << endl;
  else {
    long long ans = 0;
    for (long long extra = 0; extra < N - 1; extra++) {
      for (long long i = 0; i < N - 1; i++) c[i] = i;
      c[6] = extra;
      sort(c, c + N);
      do {
        ans = max(rec(), ans);
      } while (next_permutation(c, c + N));
    }
    cout << ans << endl;
  }
  return;
}
int32_t main() {
  clock_t st = clock();
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long t = 1;
  while (t--) {
    solve();
  }
  clog << (long double)((clock() - st) / CLOCKS_PER_SEC) << endl;
  return 0;
}
