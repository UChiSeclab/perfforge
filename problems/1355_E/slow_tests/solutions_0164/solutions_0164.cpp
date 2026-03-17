#include <bits/stdc++.h>
using namespace std;
int n;
long long a, r, m, arr[100005], sum;
long long f(int h) {
  long long pos = 0, neg = 0;
  for (int i = 0; i < n; i++)
    pos += max(0ll, arr[i] - h), neg += max(0ll, h - arr[i]);
  if (a + r < m) return a * neg + r * pos;
  long long mini = min(pos, neg);
  return m * mini + a * (neg - mini) + r * (pos - mini);
}
int main() {
  cin >> n >> a >> r >> m;
  for (int i = 0; i < n; i++) cin >> arr[i], sum += arr[i];
  int l = 0, r = 1e9 + 1, m1, m2;
  while (l < r) {
    m1 = l + (r - l) / 3;
    m2 = l + 2 * (r - l) / 3;
    if (f(m1) > f(m2))
      l = m1 + 1;
    else
      r = m2;
  }
  cout << f(l) << endl;
  return 0;
}
