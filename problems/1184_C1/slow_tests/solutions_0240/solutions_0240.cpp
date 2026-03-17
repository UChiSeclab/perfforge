#include <bits/stdc++.h>
using namespace std;
pair<int, int> a[100];
int t;
void check(int x1, int y1, int x2, int y2) {
  int cnt = 0;
  pair<int, int> temp;
  for (int i = 1; i <= t; i++) {
    int x = a[i].first;
    int y = a[i].second;
    if (x == x1 && (y1 <= y && y <= y2)) continue;
    if (x == x2 && (y1 <= y && y <= y2)) continue;
    if (y == y1 && (x1 <= x && x <= x2)) continue;
    if (y == y2 && (x1 <= x && x <= x2)) continue;
    cnt++;
    temp = make_pair(x, y);
    if (cnt > 1) return;
  }
  if (cnt == 1) {
    printf("%d %d\n", temp.first, temp.second);
    exit(0);
  }
}
int main() {
  int n;
  cin >> n;
  t = 4 * n + 1;
  for (int i = 1; i <= t; i++) {
    int x, y;
    cin >> x >> y;
    a[i] = make_pair(x, y);
  }
  for (int i = 0; i <= 50; i++)
    for (int j = 0; j <= 50; j++)
      for (int w = i + 1; w <= 50; w++)
        for (int h = j + 1; h <= 50; h++) check(i, j, w, h);
}
