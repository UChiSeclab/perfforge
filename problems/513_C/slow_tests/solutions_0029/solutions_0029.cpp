#include <bits/stdc++.h>
using namespace std;
int v[8], n, L[8], R[8], aux[8];
double soma;
void vai(int num, int u, double chance) {
  if (u == n) {
    for (int i = 0; i < n; i++) {
      if (v[i] == 0)
        aux[i] = num - 16;
      else if (v[i] == 1)
        aux[i] = num + 16;
      else
        aux[i] = num;
    }
    sort(aux, aux + n);
    if (aux[n - 2] == num) soma += chance;
    return;
  }
  if (L[u] < num) {
    v[u] = 0;
    vai(num, u + 1,
        chance * ((double)(min(R[u] - L[u] + 1, num - L[u])) /
                  (double)(R[u] - L[u] + 1)));
  }
  if (num < R[u]) {
    v[u] = 1;
    vai(num, u + 1,
        chance * ((double)(min(R[u] - L[u] + 1, R[u] - num)) /
                  (double)(R[u] - L[u] + 1)));
  }
  if (L[u] <= num and num <= R[u]) {
    v[u] = 2;
    vai(num, u + 1, chance * 1.0 / ((double)(R[u] - L[u] + 1)));
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d %d", L + i, R + i);
  double total = 0.0;
  for (int i = 1; i <= 10003; i++) {
    soma = 0.0;
    vai(i, 0, 1.0);
    total += soma * i;
  }
  printf("%.12lf\n", total);
  return 0;
}
