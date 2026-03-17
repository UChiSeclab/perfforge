#include <bits/stdc++.h>
using namespace std;
template <typename T>
int sgn(T val) {
  return (T(0) < val) - (val < T(0));
}
using namespace std;
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
void Solver656E::run() {
  int n;
  cin >> n;
  vector<vector<int>> m(n, vector<int>(n));
  cycle(0, n, [&](int i) { cycle(0, n, [&](int j) { cin >> m[i][j]; }); });
  cycle(0, n, [&](int) {
    auto mm = m;
    cycle(0, n, [&](int i) {
      cycle(0, n, [&](int j) {
        cycle(0, n,
              [&](int k) { mm[i][j] = min(mm[i][j], m[i][k] + m[k][j]); });
      });
    });
    m = move(mm);
  });
  int ans = 0;
  cycle(0, n,
        [&](int i) { cycle(0, n, [&](int j) { ans = max(ans, m[i][j]); }); });
  cout << ans;
}
int main() {
  Solver656E solver;
  solver.run();
}
