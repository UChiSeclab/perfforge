#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  int boys[n];
  int girls[m];
  for (int i = 0; i < n; i++) boys[i] = 1;
  for (int i = 0; i < m; i++) girls[i] = 1;
  int b;
  scanf("%d", &b);
  for (int i = 0; i < b; i++) {
    int x;
    scanf("%d", &x);
    boys[x] = 0;
  }
  int g;
  scanf("%d", &g);
  for (int i = 0; i < g; i++) {
    int x;
    scanf("%d", &x);
    girls[x] = 0;
  }
  int happy_count = b + g;
  int i = 0;
  while (happy_count < (m + n)) {
    if (i > (m * n * 1000)) {
      cout << "No" << endl;
      return 0;
    }
    int b_idx = i % n;
    int g_idx = i % m;
    if (boys[b_idx] == 0 && girls[g_idx] == 0) {
      i++;
      continue;
    }
    int res = boys[b_idx] & girls[g_idx];
    if (res == 0) {
      boys[b_idx] = girls[g_idx] = 0;
      happy_count++;
    }
    i++;
  }
  cout << "Yes" << endl;
  return 0;
}
