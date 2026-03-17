#include <bits/stdc++.h>
using namespace std;
long long int a[(int)1e5];
long long int f(int i, int d) {
  if (a[i] == 1) return 0;
  long long int mn = a[i] / d;
  long long int mx = mn + !!(a[i] % d);
  long long int cur = mn * mn * (d - a[i] % d);
  cur += mx * mx * (a[i] % d);
  d++;
  mn = a[i] / d;
  mx = mn + !!(a[i] % d);
  cur -= mn * mn * (d - a[i] % d);
  cur -= mx * mx * (a[i] % d);
  return cur;
}
struct st {
  int i, d;
  bool operator<(const st& o) const { return f(i, d) < f(o.i, o.d); }
};
int main() {
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) scanf("%lld", a + i);
  priority_queue<st> pq;
  long long int ans = 0;
  for (int i = 0; i < n; i++) {
    pq.push({i, 1});
    ans += a[i] * a[i];
  }
  for (int i = n; i < k; i++) {
    auto t = pq.top();
    pq.pop();
    ans -= f(t.i, t.d);
    pq.push({t.i, t.d + 1});
  }
  cout << ans << "\n";
}
