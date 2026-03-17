#include <bits/stdc++.h>
#pragma GCC optimize("O2")
using namespace std;
const int MAX = 1e6 + 5;
const long long MAX2 = 11;
const long long MOD = 1000000007;
const long long MOD2 = 1000005329;
const long long INF = 2e18;
const int dr[] = {1, 0, -1, 0, 1, 1, -1, -1, 0};
const int dc[] = {0, 1, 0, -1, 1, -1, 1, -1, 0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 200;
int n, x[MAX], ans, nw, a, b;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (long long i = 1; i <= n; ++i) cin >> x[i], x[i] = abs(x[i]);
  for (long long i = 1; i <= n; ++i)
    for (long long j = i + 1; j <= n; ++j)
      if (x[i] < x[j]) ++ans;
  for (long long i = 1; i <= n; ++i)
    for (long long j = i + 1; j <= n; ++j)
      if (x[i] > x[j]) ++nw;
  ans = min(ans, nw);
  for (long long i = 1; i <= n; ++i) {
    a = b = 0;
    for (long long j = i - 1; j >= 1; --j)
      if (x[i] < x[j]) ++a;
    for (long long j = i + 1; j <= n; ++j)
      if (x[i] > x[j]) ++a;
    for (long long j = i - 1; j >= 1; --j)
      if (-x[i] < x[j]) ++b;
    for (long long j = i + 1; j <= n; ++j)
      if (-x[i] > x[j]) ++b;
    if (a > b) x[i] = -x[i], nw += -a + b;
    ans = min(ans, nw);
  }
  nw = 0;
  for (long long i = 1; i <= n; ++i) x[i] = abs(x[i]);
  for (long long i = 1; i <= n; ++i)
    for (long long j = i + 1; j <= n; ++j)
      if (x[i] > x[j]) ++nw;
  for (long long i = 1; i <= n; ++i) {
    a = b = 0;
    for (long long j = i - 1; j >= 1; --j)
      if (x[i] < x[j] && abs(x[j]) != x[i]) ++a;
    for (long long j = i + 1; j <= n; ++j)
      if (x[i] > x[j] && abs(x[j]) != x[i]) ++a;
    for (long long j = i - 1; j >= 1; --j)
      if (-x[i] < x[j] && abs(x[j]) != x[i]) ++b;
    for (long long j = i + 1; j <= n; ++j)
      if (-x[i] > x[j] && abs(x[j]) != x[i]) ++b;
    if (a > b) {
      a = b = 0;
      for (long long j = i - 1; j >= 1; --j)
        if (x[i] < x[j]) ++a;
      for (long long j = i + 1; j <= n; ++j)
        if (x[i] > x[j]) ++a;
      for (long long j = i - 1; j >= 1; --j)
        if (-x[i] < x[j]) ++b;
      for (long long j = i + 1; j <= n; ++j)
        if (-x[i] > x[j]) ++b;
      x[i] = -x[i], nw += -a + b;
    }
    ans = min(ans, nw);
  }
  nw = 0;
  for (long long i = 1; i <= n; ++i) x[i] = abs(x[i]);
  for (long long i = 1; i <= n; ++i)
    for (long long j = i + 1; j <= n; ++j)
      if (x[i] > x[j]) ++nw;
  for (long long i = 1; i <= n; ++i) {
    a = b = 0;
    for (long long j = i - 1; j >= 1; --j)
      if (x[i] < x[j]) ++a;
    for (long long j = i + 1; j <= n; ++j)
      if (x[i] > x[j]) ++a;
    for (long long j = i - 1; j >= 1; --j)
      if (-x[i] < x[j]) ++b;
    for (long long j = i + 1; j <= n; ++j)
      if (-x[i] > x[j]) ++b;
    x[i] = -x[i], nw += -a + b;
    ans = min(ans, nw);
  }
  cout << ans << '\n';
  return 0;
}
