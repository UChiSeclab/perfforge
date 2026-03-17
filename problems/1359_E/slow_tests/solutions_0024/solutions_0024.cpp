#include <bits/stdc++.h>
using namespace std;
class Debugger {
 public:
  template <typename T>
  void printVector(vector<T> const &vec, bool printSize = true) {
    if (printSize) {
      cout << vec.size() << endl;
    }
    for (auto &elem : vec) {
      cout << elem << " ";
    }
    cout << endl;
  }
  template <typename T>
  void printMatrix(vector<vector<T>> const &matrix) {
    cout << matrix.size() << " ";
    if (!matrix.empty()) {
      cout << matrix[0].size();
    }
    cout << endl;
    for (auto &vec : matrix) {
      printVector(vec, false);
    }
    cout << endl;
  }
};
const int maxN = 100005;
const int MOD = 998244353;
class TaskE {
 private:
  Debugger debugger;
  vector<int> f;
  int mul(int a, int b) { return (long long)a * b % MOD; }
  int pot(int b, int e) {
    int ans = 1;
    while (e) {
      if (e & 1) {
        ans = mul(ans, b);
      }
      b = mul(b, b);
      e /= 2;
    }
    return ans;
  }
  int inv(int x) { return pot(x, MOD - 2); }
  int comb(int n, int k) {
    int ans = f[n];
    ans = mul(ans, inv(f[n - k]));
    ans = mul(ans, inv(f[k]));
    return ans;
  }

 public:
  void solveOne(int it) {
    int limit, n;
    cin >> limit >> n;
    f.resize(limit + 1);
    f[0] = 1;
    for (int i = 1; i <= limit; i++) {
      f[i] = mul(i, f[i - 1]);
    }
    int ans = 0;
    for (int first = 1; first <= limit; first++) {
      int k = limit / first - 1;
      if (k < n - 1) {
        continue;
      }
      ans += comb(k, n - 1);
      ans %= MOD;
    }
    cout << ans << endl;
  }
  void solve() {
    int tc = 1;
    for (int it = 1; it <= tc; it++) {
      solveOne(it);
    }
  }
};
int main() {
  ios_base::sync_with_stdio(false);
  TaskE solver;
  solver.solve();
  return 0;
}
