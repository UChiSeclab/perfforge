#include <bits/stdc++.h>
using namespace std;
int a[100100], b[100100];
map<int, int> ma, mb;
int main() {
  int n, pos;
  cin >> n >> pos;
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  int m, p;
  cin >> m >> p;
  for (int i = 1; i <= m; i++) scanf("%d", &b[i]);
  if (n == 1 && m == 1 && a[1] == b[1]) {
    puts("2");
    return 0;
  }
  int ans = 0;
  for (int i = 1; i < 31; i++) {
    ma.clear(), mb.clear();
    vector<int> vec;
    int t = (1 << i);
    for (int i = 1; i <= n; i++) {
      vec.push_back(a[i] % t);
      ma[a[i] % t]++;
    }
    for (int i = 1; i <= m; i++) mb[b[i] % t]++;
    for (auto p : ma) {
      int r = (p.first + (1 << i - 1)) % t;
      ans = max(ans, mb[r] + p.second);
    }
    for (auto p : mb) {
      int r = (p.first + (1 << i - 1)) % t;
      ans = max(ans, p.second + ma[r]);
    }
  }
  cout << ans << endl;
  return 0;
}
