#include <bits/stdc++.h>
using namespace std;
int n, m;
pair<int, int> A[20005];
vector<int> v[5005];
int atleast[5005], r[5005], vis[5005], mindist[5005];
int main() {
  scanf("%d %d", &n, &m);
  for (int i = (0); i < (m); i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    v[x].push_back(y);
  }
  for (int i = (1); i <= (n); i++) {
    for (int j = (1); j <= (n); j++) mindist[j] = r[j] = vis[j] = 0;
    for (int cur = (1); cur <= (n); cur++) {
      int j = i + cur - 1;
      if (j > n) j -= n;
      vis[j] = 1;
      r[j] = v[j].size();
      for (int k : v[j]) {
        int dist;
        if (vis[k] == 0) {
          if (k > j)
            dist = k - j;
          else
            dist = k + n - j;
        } else {
          if (k > j)
            dist = k - j;
          else
            dist = k + n - j;
        }
        if (mindist[j] == 0)
          mindist[j] = dist;
        else
          mindist[j] = min(mindist[j], dist);
      }
    }
    long long res = 0;
    int t = 0;
    for (int cur = (1); cur <= (n); cur++) {
      int j = i + cur - 1;
      if (j > n) j -= n;
      long long tmp = r[j];
      if (tmp == 0) {
        t++;
        continue;
      }
      tmp = 1ll * (tmp - 1) * n + t + mindist[j];
      res = max(res, tmp);
      t++;
    }
    printf("%lld ", res);
  }
  puts("");
  return 0;
}
