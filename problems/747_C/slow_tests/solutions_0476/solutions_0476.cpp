#include <bits/stdc++.h>
using namespace std;
struct sek {
  int t, k, d, i, s;
};
bool mn(sek a, sek b) {
  if (a.t == b.t) return a.i < b.i;
  return a.t < b.t;
}
bool mm(sek a, sek b) { return a.i < b.i; }
int main() {
  int n, q, maxi = 0;
  cin >> n >> q;
  vector<sek> s(q);
  for (unsigned i = 0, x, y, z; i < q; i++) {
    cin >> s[i].t >> s[i].k >> s[i].d;
    s[i].i = i;
    s[i].s = -1;
    maxi = max(s[i].t, maxi);
  }
  sort(s.begin(), s.end(), mn);
  vector<int> z(n + 1);
  for (int i = 1, j = 0; i <= maxi; i++) {
    for (int k = 1; k <= n; k++) {
      if (z[k] <= i) {
        z[k] = 0;
      }
    }
    while (j < q && s[j].t < i) j++;
    if (j == q) break;
    if (s[j].t == i) {
      int ser = s[j].k;
      vector<int> p;
      for (unsigned l = 1; l <= n && p.size() < ser; l++) {
        if (z[l] == 0) {
          p.push_back(l);
        }
      }
      if (p.size() == ser) {
        int ss = 0;
        for (int k = 0; k < p.size(); k++) {
          ss += p[k];
          z[p[k]] = i + s[j].d;
        }
        s[j].s = ss;
      }
    }
  }
  sort(s.begin(), s.end(), mm);
  for (int i = 0; i < q; i++) cout << s[i].s << endl;
}
