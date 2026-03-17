#include <bits/stdc++.h>
using namespace std;
const int MAXN = 500 + 5;
const double EPS = 1e-6;
const long long INF = 1e9;
int a[MAXN];
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  if (n == 1) {
    printf("%d", k - a[0]);
    return 0;
  }
  bool was;
  for (int i = 0; i < (k * n) + 1; i++) {
    was = false;
    int last = a[0];
    for (int j = 1; j < n; j++) {
      if (a[j] != last) {
        if (a[j - 1] < k) {
          a[j - 1]++;
          was = true;
        }
      }
      if (j == n - 1) {
        if (a[n - 1] < k) {
          a[n - 1]++;
          was = true;
        }
      }
      last = a[j];
    }
    if (!was) {
      printf("%d", i);
      return 0;
    }
  }
  return 0;
}
