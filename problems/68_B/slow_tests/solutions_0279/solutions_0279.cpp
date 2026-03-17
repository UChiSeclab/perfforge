#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3fll;
bool teste(vector<double> v, double meio, int k) {
  int source = 1;
  for (int i = 0; i < v.size(); i++) {
    double qt = ((meio - v[i]) * 100) / k;
    while (qt > 0) {
      if (source == v.size()) return false;
      if (v[source] > meio) {
        double aux = min({qt, v[source] - meio});
        qt -= aux;
        v[source] -= aux;
      }
      if (qt > 0) source++;
    }
  }
  return true;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  k = 100 - k;
  vector<double> v(n);
  for (int i = 0; i < n; i++) cin >> v[i];
  sort(v.begin(), v.end());
  double l = 0, r = 1e8, meio, res;
  for (int i = 0; i < 1000; i++) {
    meio = (l + r) / 2;
    if (teste(v, meio, k)) {
      res = meio;
      l = meio;
    } else
      r = meio;
  }
  cout << fixed << setprecision(9) << res << '\n';
  return 0;
}
