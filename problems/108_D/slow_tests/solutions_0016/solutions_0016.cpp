#include <bits/stdc++.h>
using namespace std;
long long mem[100100];
long long nn = 100000;
void Set(long long n, long long r) {
  for (long long i = 1; i <= r; i++) mem[i]--, mem[n--]++;
  return;
}
void Set2(long long n, long long r) {
  for (long long i = 1; i <= r; i++) mem[i]++, mem[n--]--;
  return;
}
double calc() {
  vector<long long> a, b;
  for (long long i = nn; i >= 1; i--)
    if (mem[i] > 0) {
      while (mem[i]--) a.push_back(i);
    } else if (mem[i] < 0) {
      mem[i] = -mem[i];
      while (mem[i]--) b.push_back(i);
    }
  double ret = 1.0;
  long long ia = 0, ib = 0, sa = a.size(), sb = b.size();
  while (ia < sa || ib < sb) {
    if (ia < sa) ret *= a[ia];
    if (ib < sb) ret /= b[ib];
    ia++, ib++;
  }
  return ret;
}
int main() {
  long long n, m, h;
  long long a[1010], sum = 0;
  scanf("%I64d %I64d %I64d", &n, &m, &h);
  for (long long i = 1; i <= m; i++) {
    scanf("%I64d", &a[i]);
    sum += a[i];
  }
  if (sum < n) {
    cout << -1 << endl;
    return 0;
  }
  sum--;
  n--;
  a[h]--;
  long long x = sum - a[h];
  double ans = 0.0;
  for (long long i = 1; i <= n; i++)
    if (i <= a[h] && n - i <= x) {
      memset(mem, 0, sizeof(mem));
      Set(a[h], i);
      Set(x, n - i);
      Set2(sum, n);
      ans += calc();
    }
  printf("%.10lf\n", ans);
  return 0;
}
