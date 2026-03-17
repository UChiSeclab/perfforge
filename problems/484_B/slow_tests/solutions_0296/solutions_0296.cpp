#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 10;
const int MAXX = 1e6;
int cnt[MAXX + 10];
int pcnt[MAXX + 10];
int main() {
  int n;
  scanf("%d", &n);
  vector<int> a;
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    if (x == 1) continue;
    a.push_back(x);
  }
  sort(a.begin(), a.end());
  a.erase(unique(a.begin(), a.end()), a.end());
  int asz = a.size();
  for (int i = 0; i < asz; i++) cnt[a[i]]++;
  for (int i = 1; i <= MAXX; i++) {
    pcnt[i] = pcnt[i - 1] + cnt[i];
  }
  int ans = 0;
  for (int i = asz - 1; i >= 0; i--) {
    for (int j = a[i]; j <= MAXX; j += a[i]) {
      int L = j, R = min(MAXX, j + a[i] - 1);
      while (L <= R) {
        int M = (R + L) / 2;
        int ccnt = pcnt[min(MAXX, j + a[i] - 1)] - pcnt[M - 1];
        if (ccnt > 0)
          L = M + 1;
        else
          R = M - 1;
      }
      if (R >= j) {
        ans = max(ans, R - j);
      }
    }
  }
  printf("%d", ans);
  return 0;
}
