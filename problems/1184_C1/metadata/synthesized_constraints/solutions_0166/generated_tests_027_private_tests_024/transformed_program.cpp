#include <bits/stdc++.h>
using namespace std;
const long long NMAX = 1e6;
long long x[NMAX + 5], y[NMAX + 5];
pair<long long, long long> base[NMAX + 5];
long long sum[NMAX + 2];
long long N, M;
map<pair<int, int>, bool> mp;

// Checkers for performance bottlenecks
void check_nested_loop_invariant(int xx, int yy, int rad) {
    if (rad >= 50) {
        cerr << "Warning: Performance bottleneck condition triggered - high range of rad in nested loops!" << endl;
        abort();
    }
}

void check_repetitive_point_checks(int xx, int yy, int rad) {
    if (xx > 45 || yy > 45) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive evaluations due to large xx or yy!" << endl;
        abort();
    }
}

void check_boundary_condition_verification(int xx, int yy, int rad) {
    if (xx * yy * rad > 10000) { // Arbitrary threshold based on typical loop depth at n=10
        cerr << "Warning: Performance bottleneck condition triggered - inefficient boundary condition checks!" << endl;
        abort();
    }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> N;
  int R = 4 * N + 1;
  for (int i = 1; i <= R; ++i) {
    cin >> x[i] >> y[i];
    mp[{x[i], y[i]}] = 1;
  }
  for (int xx = 0; xx <= 50; ++xx) {
    for (int yy = 0; yy <= 50; ++yy) {
      for (int rad = 50; rad >= 2; --rad) {
        map<pair<int, int>, bool> used;
        for (int i = 0; i < rad; ++i) {
          used[{xx + i, yy}] = used[{xx + rad, yy + i}] =
              used[{xx + rad - i, yy + rad}] = used[{xx, yy + rad - i}] = 1;
        }
        int cnt = 0;
        for (int i = 1; i <= R; ++i) {
          if (!used[{x[i], y[i]}]) ++cnt;
        }
        if (cnt != 1) continue;
        for (int i = 1; i <= R; ++i) {
          if (!used[{x[i], y[i]}]) {
            cout << x[i] << ' ' << y[i] << '\n';
            return 0;
          }
        }
        // Insert performance checkers here
        check_nested_loop_invariant(xx, yy, rad);
        check_repetitive_point_checks(xx, yy, rad);
        check_boundary_condition_verification(xx, yy, rad);
      }
    }
  }
  return 0;
}