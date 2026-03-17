#include <bits/stdc++.h>
using namespace std;
int n;
int l[5], r[5], val = 0;
double len[5], tot = 0;
int main(void) {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> l[i] >> r[i];
    len[i] = (double)(r[i] - l[i] + 1);
    val = min(val, l[i]);
  }
  for (int i = val; i <= 10000; i++) {
    for (int j = 0; j < n; j++) {
      if (r[j] >= i) {
        double p1 = 1, p2 = 1;
        for (int k = 0; k < n; k++) {
          if (k != j) {
            p1 *= max(0.0, (min(i, r[k]) - l[k] + 1) / len[k]);
            p2 *= max(0.0, (min(i, r[k] + 1) - l[k]) / len[k]);
          }
        }
        p1 -= p2;
        tot += i * p1 * ((r[j] - max(l[j] - 1, i)) / len[j]);
        if (l[j] <= i && p1 > 0) {
          bool can[5];
          vector<int> v;
          for (int k = 0; k < n; k++) can[k] = false;
          for (int k = 0; k < n; k++)
            if (k != j) can[k] = (l[k] <= i && i <= r[k]);
          for (int k = 0; k < n; k++)
            if (can[k]) v.push_back(k);
          for (int k = 1; k < (1 << v.size()); k++) {
            double e = 1, div = 0;
            for (int l1 = 0; l1 < v.size(); l1++) {
              if (k & (1 << l1)) {
                e *= 1 / len[v[l1]];
                div++;
              } else {
                e *= max(0.0, (min(i, r[v[l1]] + 1) - l[v[l1]]) / len[v[l1]]);
              }
            }
            tot += 1 / (div + 1) * e * i * 1 / len[j];
          }
        }
      }
    }
  }
  printf("%.11f\n", tot);
  return 0;
}
