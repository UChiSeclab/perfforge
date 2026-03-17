#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <class T, class U>
ostream& operator<<(ostream& o, const pair<T, U>& p) {
  o << "(" << p.first << "," << p.second << ")";
  return o;
}
template <class T>
ostream& operator<<(ostream& o, const vector<T>& v) {
  o << "[";
  for (T t : v) {
    o << t << ",";
  }
  o << "]";
  return o;
}
using pi = pair<int, int>;
int main() {
  int yyyy;
  int n;
  scanf(" %d %d", &n, &yyyy);
  vector<int> a(n);
  for (int(i) = 0; (i) < (int)(n); ++(i)) scanf(" %d", &a[i]);
  int m;
  scanf(" %d %d", &m, &yyyy);
  vector<int> b(m);
  for (int(i) = 0; (i) < (int)(m); ++(i)) scanf(" %d", &b[i]);
  vector<pi> v;
  for (int(i) = 0; (i) < (int)(n); ++(i)) v.push_back({a[i], i});
  for (int(i) = 0; (i) < (int)(m); ++(i)) v.push_back({b[i], n + i});
  sort((v).begin(), (v).end());
  int V = v.size();
  unordered_map<int, int> IDA, IDB;
  for (int(i) = 0; (i) < (int)(n); ++(i)) IDA[a[i]] = i;
  for (int(i) = 0; (i) < (int)(m); ++(i)) IDB[b[i]] = n + i;
  int ans = 2;
  for (int d = 1; d < (1 << 30); d *= 2) {
    int mod = 2 * d;
    unordered_map<int, int> mod2id;
    int ct = 0;
    for (int(i) = 0; (i) < (int)(n); ++(i))
      if (!mod2id.count(a[i] % mod)) {
        mod2id[a[i] % mod] = ct;
        ++ct;
      }
    for (int(i) = 0; (i) < (int)(m); ++(i))
      if (!mod2id.count(b[i] % mod)) {
        mod2id[b[i] % mod] = ct;
        ++ct;
      }
    vector<vector<int>> aa(ct), bb(ct);
    for (int(i) = 0; (i) < (int)(n); ++(i))
      aa[mod2id[a[i] % mod]].push_back(a[i]);
    for (int(i) = 0; (i) < (int)(m); ++(i))
      bb[mod2id[b[i] % mod]].push_back(b[i]);
    vector<int> dp(V, 1);
    for (int(i) = 0; (i) < (int)(V); ++(i)) {
      int idx = v[i].second;
      if (idx < n) {
        int key = a[idx] % mod;
        key = mod2id[key];
        auto itr = upper_bound((aa[key]).begin(), (aa[key]).end(), a[idx]);
        if (itr != aa[key].end()) {
          assert(IDA.count(*itr));
          int nidx = IDA[*itr];
          dp[nidx] = max(dp[nidx], dp[idx] + 1);
        }
        key = (a[idx] + d) % mod;
        if (!mod2id.count(key)) continue;
        key = mod2id[key];
        itr = lower_bound((bb[key]).begin(), (bb[key]).end(), a[idx] + d);
        if (itr != bb[key].end()) {
          assert(IDB.count(*itr));
          int nidx = IDB[*itr];
          dp[nidx] = max(dp[nidx], dp[idx] + 1);
        }
      } else {
        int key = b[idx - n] % mod;
        key = mod2id[key];
        auto itr = upper_bound((bb[key]).begin(), (bb[key]).end(), b[idx - n]);
        if (itr != bb[key].end()) {
          assert(IDB.count(*itr));
          int nidx = IDB[*itr];
          dp[nidx] = max(dp[nidx], dp[idx] + 1);
        }
        key = (b[idx - n] + d) % mod;
        if (!mod2id.count(key)) continue;
        key = mod2id[key];
        itr = lower_bound((aa[key]).begin(), (aa[key]).end(), b[idx - n] + d);
        if (itr != aa[key].end()) {
          assert(IDA.count(*itr));
          int nidx = IDA[*itr];
          dp[nidx] = max(dp[nidx], dp[idx] + 1);
        }
      }
    }
    for (int(i) = 0; (i) < (int)(V); ++(i)) ans = max(ans, dp[i]);
  }
  printf("%d\n", ans);
  return 0;
}
