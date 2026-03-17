#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:200000000")
const double EPS = 1E-9;
const int INF = 1000000000;
const long long INF64 = (long long)1E18;
const double PI = 3.1415926535897932384626433832795;
int n, m;
bool u[1100][1100];
double z[1100][1100];
double rec(int pos, int taken) {
  if (taken == n || pos == m) return double(taken) / n;
  if (u[pos][taken]) return z[pos][taken];
  double p = (n - taken) / double(n * m - pos);
  double res = rec(pos + 1, taken + 1) * p + rec(pos + 1, taken) * (1 - p);
  u[pos][taken] = true;
  return z[pos][taken] = res;
}
int main() {
  cin >> n >> m;
  double res = rec(1, 1);
  printf("%.10lf\n", res);
  return 0;
}
