#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int N = 1e5 + 5;
int v[N];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", &v[i]);
  sort(v, v + n);
  int minn = v[0], maxx = v[n - 1];
  for (int i = 1; i < n; ++i) v[i - 1] = v[i] - v[i - 1];
  sort(v, v + n - 1);
  int ans = maxx - minn + 1 - n;
  for (long long now = 1; now * now <= v[0]; ++now) {
    if (v[0] % now != 0) continue;
    int answer = 0;
    for (int i = 0; i < n - 1; ++i) {
      if (v[i] % now != 0) {
        answer = -1;
        break;
      }
      answer += v[i] / now - 1;
    }
    if (answer != -1) ans = min(answer, ans);
    int then = now;
    now = v[0] / now;
    answer = 0;
    for (int i = 0; i < n - 1; ++i) {
      if (v[i] % now != 0) {
        answer = -1;
        break;
      }
      answer += v[i] / now - 1;
    }
    if (answer != -1) ans = min(answer, ans);
    now = then;
  }
  printf("%d\n", ans);
  return 0;
}
