#include <bits/stdc++.h>
using namespace std;
const int inf = 1e6;
int n, a, b;
int dfs(int a1, int b1, vector<int> &rem) {
  if (a1 == 0 && b1 == 0) {
    return 0;
  }
  int cnt = inf;
  if (a1 != 0) {
    rem[n - a]++;
    cnt = min(cnt, 1 + dfs(a1 - 1, b1, rem));
    rem[n - a]--;
    for (int i = a; i <= 1000; i++) {
      if (rem[i] > 0) {
        rem[i]--;
        rem[i - a]++;
        cnt = min(cnt, dfs(a1 - 1, b1, rem));
        rem[i]++;
        rem[i - a]--;
      }
    }
  }
  if (b1 != 0) {
    rem[n - b]++;
    cnt = min(cnt, 1 + dfs(a1, b1 - 1, rem));
    rem[n - b]--;
    for (int i = b; i <= 1000; i++) {
      if (rem[i] > 0) {
        rem[i]--;
        rem[i - b]++;
        cnt = min(cnt, dfs(a1, b1 - 1, rem));
        rem[i]++;
        rem[i - b]--;
      }
    }
  }
  return cnt;
}
int main() {
  scanf("%d %d %d", &n, &a, &b);
  vector<int> rem(1001);
  cout << dfs(4, 2, rem) << endl;
}
