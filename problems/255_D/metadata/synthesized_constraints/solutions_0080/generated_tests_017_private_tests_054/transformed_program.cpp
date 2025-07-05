#include <bits/stdc++.h>
using namespace std;

int n, x, y, c;
int u, d, l, r;
int ur, rd, dl, lu;
int cnt, step;

// Function definitions for checkers
void check_large_grid_invariant(int n, int x, int y, int c);
void check_boundary_expansion_invariant(int n, int c);
void check_initial_position_invariant(int n, int x, int y, int c);

int main() {
  cin >> n >> x >> y >> c;

  // Insert checkers after input reading
  check_large_grid_invariant(n, x, y, c); // Detects large grid with high `c`
  check_boundary_expansion_invariant(n, c); // Detects potential boundary expansion issues
  check_initial_position_invariant(n, x, y, c); // Checks initial position near edge

  cnt = 1;
  u = d = x;
  l = r = y;
  while (cnt < c) {
    step++;
    if (u != 0) u--;
    if (d != n + 1) d++;
    if (l != 0) l--;
    if (r != n + 1) r++;
    if (u != 0) cnt++;
    if (d != n + 1) cnt++;
    if (l != 0) cnt++;
    if (r != n + 1) cnt++;
    cnt += ur;
    cnt += rd;
    cnt += dl;
    cnt += lu;
    ur++;
    rd++;
    dl++;
    lu++;
    if (u == 0) lu--;
    if (u == 0) ur--;
    if (d == n + 1) rd--;
    if (d == n + 1) dl--;
    if (l == 0) dl--;
    if (l == 0) lu--;
    if (r == n + 1) ur--;
    if (r == n + 1) rd--;
    if (ur < 0) ur = 0;
    if (rd < 0) rd = 0;
    if (dl < 0) dl = 0;
    if (lu < 0) lu = 0;
  }
  cout << step << '\n';
  return 0;
}

// Implementations of checker functions
void check_large_grid_invariant(int n, int x, int y, int c) {
    if (n > 1000000 && c > n * n / 4) {
        cerr << "Warning: Performance bottleneck condition triggered due to large grid and high c!" << endl;
        abort();
    }
}

void check_boundary_expansion_invariant(int n, int c) {
    if (c >= n * (n / 2)) {
        cerr << "Warning: Performance bottleneck condition triggered due to boundary expansion!" << endl;
        abort();
    }
}

void check_initial_position_invariant(int n, int x, int y, int c) {
    if ((x < n / 10 || x > n - n / 10) && (y < n / 10 || y > n - n / 10) && c > n * n / 4) {
        cerr << "Warning: Performance bottleneck condition triggered due to initial cell position near edge!" << endl;
        abort();
    }
}