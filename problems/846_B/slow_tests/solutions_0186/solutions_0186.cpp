#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 1000;
const long long INF64 = 1e18 + 1000;
const int N = 5000;
const int M = 1000;
const int MOD = 998244353;
const double EPS = 1e-9;
long long gcd(long long a, long long b) { return a == 0 ? b : gcd(b % a, a); }
int line[N];
int k1[N], k2[N];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, k, m;
  cin >> n >> k >> m;
  vector<int> t(k);
  long long sum = 0;
  for (int i = 0; i < int(k); ++i) {
    cin >> t[i];
    sum += t[i];
  }
  int mx = 0;
  for (int i = 0; i < int(n + 1); ++i) {
    long long tm = sum * i;
    if (tm > m) break;
    int r = m - tm;
    int k0 = k * i + i;
    vector<pair<int, int> > task;
    for (int j = int(i); j < int(n); ++j) {
      for (int p = 0; p < int(k); ++p) {
        task.push_back({t[p], p});
      }
    }
    sort(task.begin(), task.end());
    vector<int> pl(k);
    for (int j = 0; j < task.size() && r - task[j].first >= 0; j++) {
      pl[task[j].second]++;
      r -= task[j].first;
      k0++;
    }
    int z = pl[0];
    for (int j = 0; j < int(k); ++j) {
      z = min(z, pl[j]);
    }
    k0 += z;
    mx = max(mx, k0);
  }
  cout << mx << '\n';
}
