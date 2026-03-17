#include <bits/stdc++.h>
using namespace std;
int arr[6], bar[6];
int ans = 6;
int n;
void f(int pos) {
  if (pos == 6) {
    int tmp = 0;
    for (int i = 0; i < 6; i++)
      if (bar[i] < n) tmp++;
    ans = min(ans, tmp);
    return;
  }
  for (int i = 0; i < 6; i++) {
    if (bar[i] >= arr[pos]) {
      bar[i] -= arr[pos];
      f(pos + 1);
      bar[i] += arr[pos];
    }
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < 6; i++) bar[i] = n;
  int a, b;
  scanf("%d%d", &a, &b);
  arr[0] = arr[1] = arr[2] = arr[3] = a;
  arr[4] = arr[5] = b;
  f(0);
  printf("%d", ans);
  return 0;
}
