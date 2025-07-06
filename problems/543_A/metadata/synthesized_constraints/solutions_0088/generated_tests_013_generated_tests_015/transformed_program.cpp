#include <bits/stdc++.h>
using namespace std;
const int N = 501;
int n, m, b, mod, a[N], F[2][N][N];

// Check if the bug tolerance is high, leading to a broader search space
void check_high_bug_tolerance(int b) {
    if (b > 400) { // Arbitrary threshold close to the maximum constraint
        cerr << "Warning: Performance bottleneck condition triggered - high bug tolerance." << endl;
        abort();
    }
}

// Check if the line allocation is near the upper limit, complicating plan formation
void check_line_allocation(int m) {
    if (m > 450) { // Arbitrary threshold close to the maximum constraint
        cerr << "Warning: Performance bottleneck condition triggered - high line allocation." << endl;
        abort();
    }
}

// Check if the bug rates allow too many valid combinations, increasing computation
void check_bug_rate_combination(int n, int b, int* a) {
    int sum_bug_rates = 0;
    for (int i = 1; i <= n; i++) {
        sum_bug_rates += a[i];
    }
    if (sum_bug_rates < b) {
        cerr << "Warning: Performance bottleneck condition triggered - favorable bug rate combination." << endl;
        abort();
    }
}

void enter() {
  cin >> n >> m >> b >> mod;
  for (int i = 1; i <= n; i++) cin >> a[i];
  
  // Introduce checks after reading inputs
  check_high_bug_tolerance(b); // Check for high bug tolerance
  check_line_allocation(m); // Check for high line allocation
  check_bug_rate_combination(n, b, a); // Check bug rate combination
}

void process3() {
  F[0][0][0] = 1;
  for (int it = 0; it <= n; it++) {
    int i = it & 1;
    for (int j = 0; j <= m; j++)
      for (int k = 0; k <= b; k++) {
        if (it < n && j < m && k + a[it + 1] <= b)
          F[i][j + 1][k + a[it + 1]] =
              (F[i][j + 1][k + a[it + 1]] + F[i][j][k]) % mod;
        F[i ^ 1][j][k] = (F[i ^ 1][j][k] + F[i][j][k]) % mod;
        if (it < n) F[i][j][k] = 0;
      }
  }
  int res = 0;
  for (int i = 0; i <= b; i++) res = (res + F[(n)&1][m][i]) % mod;
  cout << res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  enter();
  process3();
}