#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100;
priority_queue<int, vector<int>, greater<int> > pq;
int n, k, m, t[MAXN], s, c, ans;
int main() {
  scanf("%d%d%d", &n, &k, &m);
  for (int i = 1; i <= k; i++) {
    scanf("%d", &t[i]);
    s += t[i];
  }
  for (int i = 0; i <= n && i * s <= m; i++) {
    pq = priority_queue<int, vector<int>, greater<int> >();
    int res = (k + 1) * i;
    for (int j = 1; j <= k; j++)
      for (int l = 1; l <= n - i; l++) pq.push(t[j]);
    c = s * i;
    while (!pq.empty() && c + pq.top() <= m) {
      c += pq.top();
      res++;
      pq.pop();
    }
    ans = max(ans, res);
  }
  printf("%d\n", ans);
}
