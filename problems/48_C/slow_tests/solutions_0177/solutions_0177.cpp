#include <bits/stdc++.h>
using namespace std;
const int maxN = 1000 + 5;
const int mod = 1000 * 1000 * 1000 + 7;
int dp[maxN][2 * maxN];
int w[maxN], q[maxN], v[maxN];
int a[maxN];
int n;
int check(double t) {
  for (int i = 0; i < n; i++) {
    int ps = double(i + 1) * t / 10.0;
    if (ps < a[i]) return -1;
    if (ps > a[i]) return 1;
  }
  return 0;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  double lo1 = 0, hi1 = 1000 * 1000 * 10;
  for (int z = 0; z < 400; z++) {
    double mid = (lo1 + hi1) / 2;
    if (check(mid) == -1)
      lo1 = mid;
    else
      hi1 = mid;
  }
  double lo2 = 0, hi2 = 1000 * 1000 * 10;
  for (int z = 0; z < 400; z++) {
    double mid = (lo2 + hi2) / 2;
    if (check(mid) < 1)
      lo2 = mid;
    else
      hi2 = mid;
  }
  lo1 += 1e-6;
  int ps1 = lo1 * double(n + 1) / 10.0;
  int ps2 = lo2 * double(n + 1) / 10.0;
  if (ps1 == ps2) {
    cout << "unique" << endl << ps1 << endl;
  } else
    cout << "not unique" << endl;
  return 0;
}
