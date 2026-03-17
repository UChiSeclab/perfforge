#include <bits/stdc++.h>
using namespace std;
int bits;
bool cmp(int a, int b) {
  a = ((1 << bits) - 1) & a;
  b = ((1 << bits) - 1) & b;
  return a < b;
}
int main() {
  int n;
  scanf("%d", &n);
  int vec[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &vec[i]);
  }
  int ans = 0;
  ans = 0;
  int pot = 1;
  for (int i = 1; i <= 25; i++) {
    bits = i;
    sort(vec, vec + n, cmp);
    int cnt = 0;
    for (int j = 0; j < n; j++) {
      int num = (((1 << bits) - 1) & vec[j]);
      int aux = (1 << (bits - 1));
      int ini = j + 1, fin;
      if (aux - num >= 0)
        ini = max(ini, (int)(lower_bound(vec, vec + n, aux - num, cmp) - vec));
      aux = (1 << bits) - 1;
      fin = upper_bound(vec, vec + n, aux - num, cmp) - vec;
      if (ini < fin) cnt += fin - ini;
      aux = (1 << (bits - 1)) + (1 << bits);
      if (aux - num >= (1 << bits))
        ini = n;
      else
        ini =
            max(j + 1, (int)(lower_bound(vec, vec + n, aux - num, cmp) - vec));
      fin = n;
      if (ini < fin) cnt += fin - ini;
    }
    if (cnt % 2 == 1) ans += pot;
    pot <<= 1;
  }
  printf("%d\n", ans);
  return 0;
}
