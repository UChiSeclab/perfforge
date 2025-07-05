#include <bits/stdc++.h>
using namespace std;
int n, a[11][11], ans;

// Checker for recursive calls
void check_recursive_calls_invariant(int n) {
    if (n > 8) {
        cerr << "Warning: Performance bottleneck condition triggered due to possible excessive recursive calls!" << endl;
        abort();
    }
}

// Checker for excessive relax calls
void check_excessive_relax_calls(int relaxCallCount) {
    if (relaxCallCount > 10) {
        cerr << "Warning: Performance bottleneck condition triggered due to excessive calls to relax!" << endl;
        abort();
    }
}

int read(int xn, int xm) {
  bool flag = xn < n;
  flag ? (xm >= n ? read(xn + 1, 0)
                  : (scanf("%d", &a[xn][xm]), read(xn, xm + 1)))
       : flag = false;
  return 0;
}

void init() {
  scanf("%d", &n);
  read(0, 0);
  check_recursive_calls_invariant(n); // Check after reading input for graph size
}

int gogo(int xn, int xm, int md) {
  bool flag = true;
  md < n ? (a[xn][xm] = min(a[xn][xm], a[xn][md] + a[md][xm]),
            gogo(xn, xm, md + 1))
         : flag = false;
  return 0;
}

int relax(int xn, int xm) {
  bool flag = xn < n;
  flag ? (xm >= n ? relax(xn + 1, 0) : (gogo(xn, xm, 0), relax(xn, xm + 1)))
       : flag = false;
  return 0;
}

int find_ans(int xn, int xm) {
  bool flag = xn < n;
  flag ? (xm >= n ? find_ans(xn + 1, 0)
                  : (ans = max(ans, a[xn][xm]), find_ans(xn, xm + 1)))
       : flag = false;
  return 0;
}

void solve() {
  int relaxCallCount = 0;
  while (relaxCallCount < 10) { // Replacing loops with conditionals
    relax(0, 0);
    relaxCallCount++;
  }
  check_excessive_relax_calls(relaxCallCount); // Check after several relax calls
  find_ans(0, 0);
  cout << ans << endl;
}

int main() {
  init();
  solve();
}