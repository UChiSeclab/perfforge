#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int N = 1e5 + 5;

// Checker functions
void check_large_loop_invariant(int n, int m) {
    if (n > 0 && m > 0 && n * m > 1e6) { // Threshold of 1 million iterations
        cerr << "Warning: Performance bottleneck condition triggered! Large loop execution." << endl;
        abort();
    }
}

void check_boundary_condition_invariant(int n, int m, int x) {
    if (x < min(n, m) / 4) { // Arbitrary threshold for illustration
        cerr << "Warning: Performance bottleneck condition triggered! Boundary conditions leading to excessive iterations." << endl;
        abort();
    }
}

void check_pattern_driven_invariant(int n, int m, int x) {
    if (x < 10) { // Arbitrary low threshold for illustration
        cerr << "Warning: Performance bottleneck condition triggered! Pattern-driven excessive iterations." << endl;
        abort();
    }
}

int main() {
    int n, m, x;
    cin >> n >> m >> x;

    // Apply checker functions after input read
    check_large_loop_invariant(n - 2 * x + 2, m - 2 * x + 2);
    check_boundary_condition_invariant(n, m, x);
    check_pattern_driven_invariant(n, m, x);

    n = n - 2 * x + 2;
    m = m - 2 * x + 2;
    if (n < 0 or m < 0) return puts("0");

    int result = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (i == 0 or j == 0 or i == n - 1 or j == m - 1)
                if ((i + j) % 2 == 0) result++;
    
    cout << result << endl;
}