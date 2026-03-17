#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  while (scanf("%d%d", &n, &k) == 2) {
    int T[100], min = 2e9;
    priority_queue<int> Q;
    for (int i = 0; i < n; i++) {
      int tmp;
      scanf("%d", &tmp);
      if (min > tmp) min = tmp;
      Q.push(tmp);
    }
    int ans = 0;
    while (min < k) {
      int prev = -1;
      min = 2e9;
      for (int i = 0; i < n; i++) {
        int cur = Q.top();
        Q.pop();
        if (cur == prev)
          T[i] = cur;
        else
          prev = cur, T[i] = cur + 1;
      }
      ans++;
      for (int i = 0; i < n; i++) {
        if (min > T[i]) min = T[i];
        Q.push(T[i]);
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
