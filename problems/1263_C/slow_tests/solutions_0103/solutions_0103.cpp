#include <bits/stdc++.h>
using namespace std;
int t;
int cnt, ans[100010];
bool book[100010];
map<int, bool> ma;
int main() {
  int i, j, k;
  scanf("%d", &t);
  while (t--) {
    int n;
    ma.clear();
    cnt = 0;
    scanf("%d", &n);
    ans[++cnt] = 0;
    for (i = 1; i * i <= n; i++) {
      if (ma[n / i])
        ans[cnt] = i;
      else {
        ans[++cnt] = i;
        ma[n / i] = 1;
      }
    }
    ma.clear();
    for (i = 1; i <= cnt; i++) ma[ans[i]] = 1;
    int tmp = cnt;
    for (i = 2; i <= tmp; i++) {
      if (!ma[n / ans[i]]) {
        ans[++cnt] = n / ans[i];
        ma[n / ans[i]] = 1;
      }
    }
    sort(ans + 1, ans + cnt + 1);
    cout << cnt << endl;
    for (i = 1; i <= cnt; i++) {
      cout << ans[i] << " ";
    }
    cout << endl;
  }
  return 0;
}
