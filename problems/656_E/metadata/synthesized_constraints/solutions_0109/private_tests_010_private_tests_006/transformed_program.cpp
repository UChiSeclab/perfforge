#include <bits/stdc++.h>
using namespace std;

template <typename T>
int sgn(T val) {
  return (T(0) < val) - (val < T(0));
}

class Solver656E {
 public:
  void run();
  template <class T>
  void cycle(int l, int r, T f) {
    std::function<void()> g[2];
    g[0] = [&]() {};
    g[1] = [&]() {
      f(l);
      cycle(l + 1, r, f);
    };
    g[sgn(r - l)]();
  }
};

// Checkers
void check_input_size_and_computation(int n) {
    if (n == 10) { // Assuming the maximum constraint leads to expensive operations
        cerr << "Warning: Performance bottleneck due to maximum input size!" << endl;
        abort();
    }
}

void check_recursive_invocation(int recursionDepth) {
    if (recursionDepth > 1000) { // Example threshold for excessive recursion
        cerr << "Warning: Performance bottleneck due to excessive recursion!" << endl;
        abort();
    }
}

void check_edge_weight_distributions(const vector<vector<int>>& m) {
    int maxEdgeWeight = 0;
    for (const auto& row : m) {
        for (int weight : row) {
            maxEdgeWeight = max(maxEdgeWeight, weight);
        }
    }
    if (maxEdgeWeight > 90) { // Assuming high weights can lead to slow recalculations
        cerr << "Warning: Performance bottleneck due to large edge weight variance!" << endl;
        abort();
    }
}

void Solver656E::run() {
  int n;
  cin >> n;

  // Check input size invariant
  check_input_size_and_computation(n);

  vector<vector<int>> m(n, vector<int>(n));
  cycle(0, n, [&](int i) {
      cycle(0, n, [&](int j) {
          cin >> m[i][j];
      });
  });

  // Check edge weight invariant
  check_edge_weight_distributions(m);

  cycle(0, n, [&](int) {
    auto mm = m;
    cycle(0, n, [&](int i) {
      cycle(0, n, [&](int j) {
        cycle(0, n, [&](int k) {
            mm[i][j] = min(mm[i][j], m[i][k] + m[k][j]);
        });
      });
    });
    m = move(mm);
  });

  int ans = 0;
  cycle(0, n, [&](int i) {
      cycle(0, n, [&](int j) {
          ans = max(ans, m[i][j]);
      });
  });

  cout << ans;
}

int main() {
  Solver656E solver;
  solver.run();
}