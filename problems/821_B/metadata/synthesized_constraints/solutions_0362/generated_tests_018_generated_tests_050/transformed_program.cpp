#include <bits/stdc++.h>
using namespace std;

// Performance invariant checkers
void check_large_iteration_invariant(long long m, long long b) {
    if (m * b > 1000000) { // Arbitrary threshold chosen based on problem constraints
        cerr << "Warning: Performance bottleneck condition triggered - large loop iteration count!" << endl;
        abort();
    }
}

void check_frequent_computation_invariant(long long X) {
    if (X > 1000000) { // Threshold indicating many calls to the expensive function
        cerr << "Warning: Performance bottleneck condition triggered - frequent computations in loop!" << endl;
        abort();
    }
}

void check_high_arithmetic_overhead_invariant(long long X) {
    if (X > 1000000) { // Use similar threshold indicating potential arithmetic overhead
        cerr << "Warning: Performance bottleneck condition triggered - high arithmetic overhead!" << endl;
        abort();
    }
}

long long gauss(long long n) {
  if (n % 2 == 0)
    return n / 2 * (n + 1);
  else
    return n * (n + 1) / 2;
}

long long cb(int x, int y) { 
    return (x + 1) * gauss(y) + (y + 1) * gauss(x); 
}

int main() {
  long long m, b;
  cin >> m >> b;

  // Insert check for large iteration count
  check_large_iteration_invariant(m, b);

  long long X = m * b;
  long long res = 0;

  // Insert check for frequent computation in loop and high arithmetic overhead
  check_frequent_computation_invariant(X);
  check_high_arithmetic_overhead_invariant(X);

  for (int i = 0; i <= X; i++) {
    int y = floor(((double)i / m) * (-1) + b);
    res = max(res, cb(i, y));
  }
  
  cout << res << endl;
}