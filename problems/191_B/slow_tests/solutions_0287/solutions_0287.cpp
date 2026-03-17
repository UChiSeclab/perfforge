#include <bits/stdc++.h>
using namespace std;
struct plot {
  int indice;
  long long int valeur;
};
int comparer(const void* a, const void* b) { return *(int*)b - *(int*)a; }
int main() {
  int n, k, i;
  long long int total;
  long long int atteignable = 0;
  int p[100000];
  int q[100000];
  int dernier, reponse;
  long long int pluspetit;
  cin >> n >> k;
  cin >> total;
  for (i = 0; i < n; i++) {
    cin >> p[i];
    q[i] = p[i];
  }
  qsort(p, n - 1, sizeof(int), comparer);
  for (i = 0; i < k; i++) {
    atteignable += (long long int)p[i];
  }
  dernier = p[k - 1];
  if (atteignable <= total)
    printf("%d\n", n);
  else {
    pluspetit = (long long int)dernier + total - atteignable + 1;
    for (i = 0; i < n; i++) {
      if (q[i] >= pluspetit) {
        reponse = i + 1;
        i = n + 10;
      }
    }
    if (i > n + 5)
      printf("%d\n", reponse);
    else
      printf("%d\n", n);
  }
  return 0;
}
