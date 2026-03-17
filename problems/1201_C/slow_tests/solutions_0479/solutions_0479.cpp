#include <bits/stdc++.h>
int cmp(const void *p, const void *q) {
  return ((*((long long int *)p)) - (*((long long int *)q)));
}
int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  long long int arr[n];
  for (int i = 0; i < n; i++) {
    scanf("%lld", &arr[i]);
  }
  qsort(arr, n, sizeof(long long int), cmp);
  int c = (n / 2);
  int d = (n / 2);
  while (d < n && arr[c] == arr[d]) {
    d++;
  }
  d--;
  long long int ans = arr[n / 2];
  while (k > 0) {
    if ((d - c + 1) > k) {
      break;
    }
    k -= (d - c + 1);
    arr[n / 2]++;
    d++;
    while (d < n && arr[d] == arr[n / 2]) {
      d++;
    }
    d--;
  }
  printf("%lld\n", arr[n / 2]);
}
