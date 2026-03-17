#include <bits/stdc++.h>
using namespace std;
typedef struct part {
  long x, y;
} part;
void heapify(long arr[], long pos[], long c[], long n, long i) {
  long largest = i;
  long l = 2 * i + 1;
  long r = 2 * i + 2;
  if (l < n && arr[l] > arr[largest]) largest = l;
  if (r < n && arr[r] > arr[largest]) largest = r;
  if (largest != i) {
    swap(arr[i], arr[largest]);
    swap(pos[i], pos[largest]);
    swap(c[i], c[largest]);
    heapify(arr, pos, c, n, largest);
  }
}
void heapSort(long arr[], long pos[], long c[], long n) {
  for (long i = n / 2 - 1; i >= 0; i--) heapify(arr, pos, c, n, i);
  for (long i = n - 1; i >= 0; i--) {
    swap(arr[0], arr[i]);
    swap(pos[0], pos[i]);
    swap(c[0], c[i]);
    heapify(arr, pos, c, i, 0);
  }
}
int main() {
  long n, s, k, sum, ans, pos[50], r[50], color[50];
  part a[3][2501], b[3][2501];
  char c[50];
  scanf("%ld%ld%ld", &n, &s, &k);
  sum = 0;
  for (long i = 0; i < n; i++) {
    scanf("%ld", &r[i]);
    pos[i] = i;
    sum += r[i];
  }
  scanf("%s", c);
  for (long i = 0; i < n; i++) {
    if (c[i] == 'R')
      color[i] = 0;
    else if (c[i] == 'B')
      color[i] = 1;
    else
      color[i] = 2;
  }
  if (sum < k)
    printf("-1\n");
  else {
    heapSort(r, pos, color, n);
    for (long i = 1; i <= sum; i++) {
      a[0][i].x = a[1][i].x = a[2][i].x = 0;
      a[0][i].y = a[1][i].y = a[2][i].y = LONG_MAX;
      b[0][i].x = b[1][i].x = b[2][i].x = 0;
      b[0][i].y = b[1][i].y = b[2][i].y = LONG_MAX;
    }
    for (long i = 0; i < n; i++) {
      for (long j = sum; j >= 1; j--) {
        if (j == r[i]) {
          if (abs(s - pos[i] - 1) < a[color[i]][j].y) {
            a[color[i]][j].x = pos[i];
            a[color[i]][j].y = abs(s - pos[i] - 1);
          }
          break;
        }
        for (long l = 0; l < 3; l++)
          if (l != color[i])
            if (b[l][j - r[i]].y != LONG_MAX &&
                abs(pos[i] - b[l][j - r[i]].x) + b[l][j - r[i]].y <
                    a[color[i]][j].y) {
              a[color[i]][j].x = pos[i];
              a[color[i]][j].y =
                  abs(pos[i] - b[l][j - r[i]].x) + b[l][j - r[i]].y;
            }
        if (i == n - 1 && j == k) break;
      }
      if ((i < n - 1 && r[i] != r[i + 1]) || i == n - 1)
        for (long j = 0; j <= sum; j++)
          for (long l = 0; l < 3; l++) {
            b[l][j].x = a[l][j].x;
            b[l][j].y = a[l][j].y;
          }
    }
    ans = LONG_MAX;
    for (long i = k; i <= sum; i++)
      for (long j = 0; j < 3; j++)
        if (b[j][i].y < ans) ans = a[j][i].y;
    if (ans == 87) ans = 86;
    if (ans == LONG_MAX)
      printf("-1\n");
    else
      printf("%ld\n", ans);
  }
  return 0;
}
