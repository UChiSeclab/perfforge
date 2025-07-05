#include <bits/stdc++.h>
using namespace std;
const long long N = 1e7 + 5;

void check_close_intervals(int a, int b, int c, int d) {
    if (abs(a - c) <= 1 && abs(b - d) <= 1) {
        cerr << "Warning: Performance bottleneck condition triggered due to close intervals!" << endl;
        abort();
    }
}

void check_small_offset_difference(int a, int b, int c, int d) {
    if (abs(b - d) < min(a, c)) {
        cerr << "Warning: Performance bottleneck condition triggered due to small offset difference!" << endl;
        abort();
    }
}

void check_small_intervals(int a, int c) {
    if (a <= 2 && c <= 2) {
        cerr << "Warning: Performance bottleneck condition triggered due to small interval values!" << endl;
        abort();
    }
}

void solve() {
  long long a, b, c, d;
  cin >> a >> b >> c >> d;

  // Insert performance checks after reading input to avoid overhead in tight loop
  check_close_intervals(a, b, c, d);
  check_small_offset_difference(a, b, c, d);
  check_small_intervals(a, c);

  for (long long i = 0; i < N; i++) {
    long long x = b + i * a;
    double y = ((1.0) * (x - d)) / c;
    if (ceil(y) == floor(y) && y >= 0) {
      cout << x << "\n";
      return;
    }
  }
  cout << -1 << "\n";
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  clock_t start = clock();
  long long t = 1;
  while (t--) {
    solve();
  }
  clock_t stop = clock();
  return 0;
}