#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 4;
const long long mod = 1e9 + 7;
const int INF = 1e9 + 4;
const double eps = 1e-7;
int a[N], b[N];
string s;
int n, m, t, k;
vector<int> seg[N];
int sum[N];
int las[N];
int Mval;
int get(vector<int> t) {
  int mx = -INF;
  int tmp = 0;
  for (int i = 0; i < t.size(); ++i) {
    tmp = max(0, tmp + t[i]);
    mx = max(mx, tmp);
  }
  return mx;
}
int solve() {
  for (int i = 1; i <= n; ++i) {
    seg[a[i]].push_back(sum[las[a[i]]] - sum[i]);
    las[a[i]] = i;
    seg[a[i]].push_back(1);
  }
  for (int i = 0; i <= Mval; ++i) {
    seg[i].push_back(sum[las[i]] - sum[n]);
  }
  int res = 0;
  for (int i = 0; i <= Mval; ++i) {
    if (i == k) continue;
    res = max(res, get(seg[i]));
  }
  return res;
}
int main() {
  cin >> n >> k;
  int num = 0;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", a + i);
    Mval = max(Mval, a[i]);
    sum[i] = sum[i - 1] + (a[i] == k);
    num += (a[i] == k);
  }
  sum[n + 1] = sum[n];
  Mval++;
  int d = solve();
  cout << num + d << endl;
  return 0;
}
