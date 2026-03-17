#include <bits/stdc++.h>
using namespace std;
const int INF = 1e8;
void foo() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n), b(n), c(m), d(m);
  int mx = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
    mx = max(mx, max(a[i], b[i]));
  }
  for (int i = 0; i < m; i++) {
    cin >> c[i] >> d[i];
    mx = max(mx, max(c[i], d[i]));
  }
  vector<pair<int, int> > p;
  vector<int> v(mx + 3);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int up = max(0, d[j] - b[i] + 1);
      int right = max(0, c[j] - a[i] + 1);
      v[up] = max(v[up], right);
    }
  }
  vector<int> suff_max(mx + 4);
  for (int i = mx + 2; i >= 0; i--) {
    suff_max[i] = max(suff_max[i + 1], v[i]);
  }
  int best = INF;
  for (int i = 0; i < mx + 2; i++) {
    best = min(i + suff_max[i + 1], best);
  }
  cout << best << endl;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  foo();
}
