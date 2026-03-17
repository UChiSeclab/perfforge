#include <bits/stdc++.h>
const int INF = 2e9 + 7;
const long long INFLL = 1e16 + 7;
const double EPS = 1e-6;
using namespace std;
const int maxn = 1e5 + 5;
int n, m;
int a[maxn];
int poli(long long mod) {
  long long now = 1;
  long long ret = 0;
  for (int k = (int)0; k < (int)n; k++) {
    ret += now * a[k];
    ret %= mod;
    now = (now * m) % mod;
  }
  if (ret) return 1;
  return 0;
}
int main() {
  scanf("%d%d", &n, &m);
  n++;
  int last = -1, sum = 0;
  for (int k = (int)0; k < (int)n; k++) {
    char tmp[100];
    scanf("%s", &tmp);
    if (tmp[0] == '?') {
      last = k & 1;
      a[k] = INF;
      sum++;
    } else
      sscanf(tmp, "%d", &a[k]);
  }
  if (m == 0) {
    if (a[0] != INF) {
      if (a[0] == 0)
        printf("Yes\n");
      else
        printf("No\n");
    } else {
      if ((n - sum) % 2)
        printf("Yes\n");
      else
        printf("No\n");
    }
    return 0;
  }
  if (last != -1) {
    if (n % 2 == 0)
      printf("Yes\n");
    else
      printf("No\n");
    return 0;
  }
  int cek = 0;
  long long ten[25];
  ten[0] = 1;
  for (int k = (int)1; k < (int)18; k++) ten[k] = ten[k - 1] * 10;
  for (int k = (int)3; k < (int)9; k++) cek = (cek | poli(ten[k] + 7));
  cek = (cek | poli(ten[9]));
  for (int k = (int)INF; k < (int)INF + 200; k++) cek = (cek | poli(k));
  if (cek == 0)
    printf("Yes\n");
  else
    printf("No\n");
  return 0;
}
