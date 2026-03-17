#include <bits/stdc++.h>
using namespace std;
const int MX = 3e5 + 69;
const int inf = 1e9 + 5;
const long long mod = 1e9 + 7;
const long double eps = 1e-7;
int n, c;
long long f[MX];
struct fuck {
  long long w, c, dif;
} a[MX];
int p[11], l[11];
vector<long long> v[11];
vector<pair<long long, long long> > pp;
long long dp[4111][1111];
long long ok = 1;
long long fu(int id, int k) {
  if (id >= pp.size() || id > 3001) {
    return 0;
  }
  if (k == 0) {
    return 0;
  }
  long long &ans = dp[id][k];
  if (ans != -1) {
    return ans;
  }
  ans = 0;
  ans = max(ans, fu(id + 1, k));
  if (k - 3 >= 0 && pp[id].second == 3)
    ans = max(ans, pp[id].first + fu(id + 1, k - 3));
  if (k - 2 >= 0 && pp[id].second == 2)
    ans = max(ans, pp[id].first + fu(id + 1, k - 2));
  if (k - 1 >= 0 && pp[id].second == 1)
    ans = max(ans, pp[id].first + fu(id + 1, k - 1));
  return ans;
}
long long solve(int p1, int p2, int p3, int k) {
  if (k == 0) {
    return 0;
  }
  if (k > 1003) {
    if (p3 < l[3] && 2 * v[3][p3] >= 3 * v[2][p2] && v[3][p3] >= 3 * v[1][p1]) {
      return v[3][p3] + solve(p1, p2, p3 + 1, k - 3);
    } else if (p2 < l[2] && 3 * v[2][p2] >= 2 * v[3][p3] &&
               v[2][p2] >= 2 * v[1][p1]) {
      return v[2][p2] + solve(p1, p2 + 1, p3, k - 2);
    } else if (p1 < l[1] && 3 * v[1][p1] >= v[3][p3] &&
               2 * v[1][p1] >= v[2][p2]) {
      return v[1][p1] + solve(p1 + 1, p2, p3, k - 1);
    }
  } else {
    for (int i = p1; i < min(l[1], p1 + 1533); i++) {
      pp.push_back({v[1][i], 1});
    }
    for (int i = p2; i < min(l[2], p2 + 633); i++) {
      pp.push_back({v[2][i], 2});
    }
    for (int i = p3; i < min(l[3], p3 + 433); i++) {
      pp.push_back({v[3][i], 3});
    }
    return fu(0, k);
  }
}
bool cmp(fuck a, fuck b) { return (a.dif > b.dif); }
int main() {
  cin >> n >> c;
  for (int i = 0; i < n; i++) {
    long long w, c;
    scanf("%I64d %I64d", &w, &c);
    a[i] = {w, c, 6 * c / w};
  }
  sort(a, a + n, cmp);
  long long k = 0;
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    k += a[i].w;
    k = min(k, c * 1ll);
    for (int j = k; j >= max(a[i].w, k - 20); j--) {
      f[j] = max(f[j], f[j - a[i].w] + a[i].c);
      ans = max(ans, f[j]);
    }
  }
  cout << ans;
  return 0;
}
