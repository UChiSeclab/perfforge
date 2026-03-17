#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  while (scanf("%d", &n) >= 1) {
    vector<int> ss(n);
    for (int i = 0; i < n; i++) scanf("%d", &ss[i]);
    sort(ss.begin(), ss.end());
    try {
      vector<int> as;
      int pval = ss[0];
      as.push_back(0);
      for (int i = 0; i < n; i++)
        if (pval != ss[i]) {
          if (pval + 1 != ss[i]) throw pval + 1;
          pval = ss[i];
          as.push_back(1);
        } else
          as[((int)(as).size()) - 1]++;
      int n = ((int)(as).size());
      if (n < 2) throw -1;
      int px = as[0];
      for (int i = 1; i < n; i++) {
        int nx = as[i] - px;
        if (nx < 0) throw 0;
        if (!nx && i + 1 < n) throw 0;
        px = nx;
      }
      if (px) throw 0;
      printf("YES\n");
    } catch (...) {
      printf("NO\n");
    }
    break;
  }
  return 0;
}
