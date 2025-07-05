#include <bits/stdc++.h>
#pragma GCC optimize(2)
#pragma GCC optimize(3)
using namespace std;
const int N = 2e5 + 10;
int n, m;
struct uzi {
  int x, y;
} p[N], q[N];
int x[N * 20];
pair<int, int> s[N * 20];
int cnt;

// Checker functions
void check_large_iteration(int range) {
    if (range > 1000000) {
        cerr << "Warning: Large iteration range may cause performance degradation!" << endl;
        abort();
    }
}

void check_condition_frequency(int pos, int cnt) {
    if (pos > cnt) {
        cerr << "Warning: High frequency of condition checks detected!" << endl;
        abort();
    }
}

void check_searchlight_coverage(int c_max, int a_max, int d_max, int b_max) {
    if (c_max > a_max && d_max > b_max) {
        cerr << "Warning: Extensive searchlight coverage may increase iteration count!" << endl;
        abort();
    }
}

void check_initial_ans_value(int ans) {
    if (ans > 1000000) {
        cerr << "Warning: High initial value of ans may cause excessive iterations!" << endl;
        abort();
    }
}

int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> p[i].x >> p[i].y;
  for (int i = 1; i <= m; i++) cin >> q[i].x >> q[i].y;

  // Check searchlight coverage
  int a_max = 0, b_max = 0, c_max = 0, d_max = 0;
  for (int i = 1; i <= n; i++) {
      a_max = max(a_max, p[i].x);
      b_max = max(b_max, p[i].y);
  }
  for (int i = 1; i <= m; i++) {
      c_max = max(c_max, q[i].x);
      d_max = max(d_max, q[i].y);
  }
  check_searchlight_coverage(c_max, a_max, d_max, b_max);

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (q[j].y >= p[i].y && q[j].x >= p[i].x) {
        s[++cnt] = {q[j].y - p[i].y + 1, q[j].x - p[i].x + 1};
      }
    }
  }
  sort(s + 1, s + 1 + cnt);

  for (int i = cnt; i >= 1; i--) x[i] = max(x[i + 1], s[i].second);

  int ans = 1000005, pos = 1;
  // Check initial ans value
  check_initial_ans_value(ans);

  for (int i = 0; i <= 1000000 && i < ans; i++) {
    check_large_iteration(i); // Check large iteration range
    while (pos <= cnt && s[pos].first <= i) pos++;
    check_condition_frequency(pos, cnt); // Check condition frequency
    ans = min(ans, i + x[pos]);
  }
  cout << ans << '\n';
  return 0;
}