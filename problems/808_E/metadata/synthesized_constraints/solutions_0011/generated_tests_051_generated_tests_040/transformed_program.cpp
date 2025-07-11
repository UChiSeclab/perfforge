#include <bits/stdc++.h>
using namespace std;

void read(int &x) {
  char ch = getchar();
  x = 0;
  for (; ch == ' ' || ch == '\n'; ch = getchar())
    ;
  for (; ch != ' ' && ch != '\n'; x = x * 10 + ch - '0', ch = getchar())
    ;
}

void write(long long x) {
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
}

void check_weight_2_invariant(int cnt2, int n) {
    if (cnt2 > n / 4) {
        cerr << "Warning: Performance bottleneck condition triggered due to high count of weight 2 items!" << endl;
        abort();
    }
}

void check_weight_combination_invariant(int cnt2, int m) {
    if (cnt2 > m / 4) {
        cerr << "Warning: Performance bottleneck condition triggered due to weight 2 items approaching half of capacity!" << endl;
        abort();
    }
}

int cnt[4];
long long dat[4][100004];
bool cmp(int a, int b) { return a > b; }
long long dp[300004], stane[300004];

int main() {
  int n, m;
  read(n), read(m);
  for (int i = 1; i <= n; i++) {
    int w, c;
    read(w), read(c);
    dat[w][++cnt[w]] = c;
  }

  // Insert checks after input reading
  check_weight_2_invariant(cnt[2], n);
  check_weight_combination_invariant(cnt[2], m);

  for (int i = 1; i <= 3; i++) sort(dat[i] + 1, dat[i] + 1 + cnt[i], cmp);
  for (int i = 1; i < 100004; i++)
    for (int j = 1; j <= 3; j++) dat[j][i] = dat[j][i - 1] + dat[j][i];
  for (int i = 1; i < 300004; i++) {
    if (i < 100004)
      stane[i] = dat[1][i];
    else
      stane[i] = dat[1][100003];
  }
  for (int i = 1; i < 300004; i++) {
    if (i <= 1 || stane[i] >= dat[2][1] + stane[i - 2]) {
      dp[i] = stane[i];
      continue;
    }
    int l = 0, r = min(cnt[2], i / 2) + 1;
    while (r > l + 1) {
      int mid = (l + r) / 2;
      if (dat[2][mid] + stane[i - 2 * mid] >
          dat[2][mid - 1] + stane[i - 2 * (mid - 1)])
        l = mid;
      else
        r = mid;
    }
    dp[i] = dat[2][l] + stane[i - 2 * l];
  }
  long long ans = 0;
  for (int i = 0; i * 3 <= m; i++) ans = max(ans, dp[m - i * 3] + dat[3][i]);
  write(ans);
}