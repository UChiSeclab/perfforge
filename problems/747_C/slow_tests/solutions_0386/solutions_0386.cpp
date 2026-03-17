#include <bits/stdc++.h>
using namespace std;
bool s[105][1001005];
int n, q;
int t, k, d;
int main() {
  scanf("%d%d", &n, &q);
  memset(s, true, sizeof s);
  for (int i = 0; i < q; i++) {
    scanf("%d%d%d", &t, &k, &d);
    vector<int> v;
    for (int j = 0; j < n; j++) {
      bool bisa = true;
      for (int l = t; l < t + d; l++) {
        bisa = (bisa && s[j][l]);
      }
      if (bisa) v.push_back(j);
    }
    if (v.size() >= k) {
      int sum = 0;
      for (int j = 0; j < k; j++) {
        sum += v[j] + 1;
        for (int l = t; l < t + d; l++) {
          s[v[j]][l] = false;
        }
      }
      printf("%d\n", sum);
    } else {
      printf("-1\n");
    }
  }
}
