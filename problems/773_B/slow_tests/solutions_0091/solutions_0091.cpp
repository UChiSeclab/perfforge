#include <bits/stdc++.h>
using namespace std;
const int inf = 2e9;
const int M = 5;
const int N = 125;
const double eps = 0.00001;
int ans = inf, n, a[N][M], h[M];
int p[6] = {500, 1000, 1500, 2000, 2500, 3000};
double r[6] = {1, 1. / 2, 1. / 4, 1. / 8, 1. / 16, 1. / 32};
double l[6] = {1. / 2, 1. / 4, 1. / 8, 1. / 16, 1. / 32, 0};
int getval(vector<int> c) {
  int first = 0, second = 0;
  for (int i = 0; i < M; i++) {
    if (a[0][i] != -1) {
      first += p[c[i]] - (p[c[i]] * a[0][i] / 250);
    }
    if (a[1][i] != -1) {
      second += p[c[i]] - (p[c[i]] * a[1][i] / 250);
    }
  }
  if (first <= second) {
    return inf;
  }
  int nn = ans;
  if (ans > 10000) {
    nn = 10000;
  }
  for (int res = 0; res < nn; res++) {
    double all = n + res;
    bool pp = 1;
    for (int i = 0; i < M && pp; i++) {
      if (a[0][i] == -1) {
        double p = h[i] / all;
        for (int j = 0; j < 6; j++) {
          if (l[j] < p && p <= r[j]) {
            if (j != c[i]) {
              pp = 0;
              break;
            }
          }
        }
      }
    }
    if (!pp) {
      continue;
    }
    bool p = 1;
    for (int i = 0; i < M; i++) {
      double l1 = l[c[i]];
      double r1 = r[c[i]];
      double xl = l1 * all - h[i];
      double xr = r1 * all - h[i];
      int dxl = int(ceil(xl + eps));
      int dxr = int(xr);
      if (xr >= 0 && res > xl && dxl <= dxr) {
        continue;
      } else {
        p = 0;
        break;
      }
    }
    if (p) {
      return res;
    }
  }
  return inf;
}
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < M; j++) {
      cin >> a[i][j];
      h[j] += (a[i][j] != -1);
    }
  }
  vector<int> c(5);
  for (int p1 = 0; p1 < 6; p1++) {
    c[0] = p1;
    for (int p2 = 0; p2 < 6; p2++) {
      c[1] = p2;
      for (int p3 = 0; p3 < 6; p3++) {
        c[2] = p3;
        for (int p4 = 0; p4 < 6; p4++) {
          c[3] = p4;
          for (int p5 = 0; p5 < 6; p5++) {
            c[4] = p5;
            ans = min(ans, getval(c));
          }
        }
      }
    }
  }
  if (ans == inf) {
    ans = -1;
  }
  cout << ans << "\n";
}
