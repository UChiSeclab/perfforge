#include <bits/stdc++.h>
#pragma optimise GCC(-O2)
using namespace std;
mt19937_64 rang(
    chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
  uniform_int_distribution<int> uid(0, lim - 1);
  return uid(rang);
}
long long INF = LLONG_MAX;
const long long M = 1000000007;
long long powm(long long, long long);
set<long long> s[105];
map<pair<int, int>, long long> mp;
map<long long, pair<int, int> > inv;
long long val[105];
long long d;
long long n;
long long a[105];
bool dfs(int ind) {
  for (int i = 0; i < 105; i++) val[i] = -INF;
  for (int i = 0; i < 105; i++) s[i].clear();
  val[1] = ind;
  s[1].insert(1);
  queue<long long> q;
  q.push(1);
  while (!q.empty()) {
    long long i = q.front();
    q.pop();
    for (int j = 1; j < n + 1; j++) {
      if (i == j) continue;
      long long dis =
          abs(inv[i].first - inv[j].first) + abs(inv[i].second - inv[j].second);
      dis *= d;
      if (val[i] >= dis) {
        long long stunned;
        if (s[i].find(j) == s[i].end()) {
          stunned = a[j] - dis;
        } else
          stunned = 0 - dis;
        if (val[j] <= val[i] + stunned) {
          q.push(j);
          val[j] = val[i] + stunned;
          s[j].clear();
          for (auto x : s[i]) s[j].insert(x);
          s[j].insert(j);
        }
      }
    }
  }
  if (val[n] < 0) return false;
  return true;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> d;
  for (int i = 2; i < n; i++) cin >> a[i];
  for (int i = 1; i < n + 1; i++) {
    long long x;
    cin >> x;
    long long y;
    cin >> y;
    mp[{x, y}] = i;
    inv[i] = {x, y};
  }
  a[1] = 0;
  a[n] = 0;
  for (int i = 0; i < 105; i++) val[i] = -INF;
  long long lo = 0, hi = 1e9;
  while (lo < hi) {
    long long mid = (lo + hi) >> 1;
    if (dfs(mid))
      hi = mid;
    else
      lo = mid + 1;
  }
  cout << lo;
}
long long powm(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b & 1) res = (res * a) % M;
    a = (a * a) % M;
    b >>= 1;
  }
  return res;
}
