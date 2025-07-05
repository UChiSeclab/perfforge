#include <bits/stdc++.h>
using namespace std;
const int N = 10;
const int inf = 1 << 29;
int d[N][N];

// Checkers for performance bottlenecks
void check_matrix_loop_invariant(int n) {
    if (n == 10) {
        cerr << "Warning: Performance bottleneck condition triggered - high matrix loop complexity!" << endl;
        abort();
    }
}

void check_edge_weight_invariant(const int d[10][10], int n) {
    bool hasLargeDisparity = false;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i != j && d[i][j] >= 100) {
                hasLargeDisparity = true;
                break;
            }
        }
        if (hasLargeDisparity) break;
    }
    if (hasLargeDisparity) {
        cerr << "Warning: Performance bottleneck condition triggered - large disparity in edge weights!" << endl;
        abort();
    }
}

void check_data_structure_updates(int n) {
    if (n == 10) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive data structure updates!" << endl;
        abort();
    }
}

int loop(function<bool()> ok, function<void()> increment, function<void()> work) {
  return ok() ? work(), increment(), loop(ok, increment, work) : 0;
}

int main() {
  int n;
  scanf("%d", &n);
  
  // Performance bottleneck checks
  check_matrix_loop_invariant(n);

  {
    int i = 0;
    loop([&i, &n]() -> bool { return i < n; }, [&i]() { ++i; },
         [&i, &n]() {
           int j = 0;
           loop([&j, &n]() -> bool { return j < n; }, [&j]() { ++j; },
                [&i, &j]() { scanf("%d", d[i] + j); });
         });
  }
  
  // Check after reading input matrix
  check_edge_weight_invariant(d, n);
  check_data_structure_updates(n);
  
  {
    int k = 0;
    loop([&k, &n]() -> bool { return k < n; }, [&k]() { ++k; },
         [&k, &n]() {
           int i = 0;
           loop([&i, &n]() -> bool { return i < n; }, [&i]() { ++i; },
                [&k, &i, &n]() {
                  int j = 0;
                  loop([&j, &n]() -> bool { return j < n; }, [&j]() { ++j; },
                       [&k, &i, &j]() {
                         d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                       });
                });
         });
  }
  
  int ans = 0;
  {
    int i = 0;
    loop([&i, &n]() -> bool { return i < n; }, [&i]() { ++i; },
         [&i, &n, &ans]() {
           int j = 0;
           loop([&j, &n]() -> bool { return j < n; }, [&j]() { ++j; },
                [&i, &j, &ans]() { ans = max(ans, d[i][j]); });
         });
  }
  
  printf("%d\n", ans);
  return 0;
}