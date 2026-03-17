#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100001;
const long long INFINITE = 0x7FFFFFFFFFFFFFFFll;
int n;
long long m, res;
long long tem[MAXN], bnd[MAXN], mon[MAXN], car[MAXN];
inline long long min(long long x, long long y) { return (x < y) ? x : y; }
int main() {
  scanf("%d %I64d\n", &n, &m);
  for (int i = 1; i <= n; ++i)
    scanf("%I64d %I64d %I64d %I64d\n", &tem[i], &bnd[i], &mon[i], &car[i]);
  long long tmp;
  for (int i = 1; i <= n; ++i) {
    if (bnd[i] <= tem[i])
      res += car[i] + m * mon[i];
    else {
      long long num = m / (bnd[i] - tem[i]) + (m % (bnd[i] - tem[i]) > 0);
      if (tem[i] + m > bnd[i])
        res += tmp = min(car[i] + m * mon[i], num * car[i]);
      else
        res += tmp = min(car[i], num * car[i]);
    }
  }
  printf("%I64d\n", res);
  fclose(stdin);
  fclose(stdout);
  return 0;
}
