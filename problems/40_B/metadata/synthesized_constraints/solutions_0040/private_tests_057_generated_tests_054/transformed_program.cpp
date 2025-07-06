#include <bits/stdc++.h>
using namespace std;

// Checker functions for performance invariants

void check_large_width_invariant(int m, int x) {
    if (m > 2 * x) {
        cerr << "Warning: Performance bottleneck condition triggered - width m significantly larger than 2*x!" << endl;
        abort();
    }
}

void check_large_x_invariant(int n, int m, int x) {
    if (x > (n / 2) || x > (m / 2)) {
        cerr << "Warning: Performance bottleneck condition triggered - x is large relative to n or m!" << endl;
        abort();
    }
}

void check_large_dimensions_invariant(int n, int m, int x) {
    if ((n > 2000 && m > 2000) && x > 500) {
        cerr << "Warning: Performance bottleneck condition triggered - large board dimensions with large x!" << endl;
        abort();
    }
}

int main() {
    int n, m, x, ans = 0;
    cin >> n >> m >> x;
    
    // Insert performance checkers at effective points after reading inputs
    check_large_width_invariant(m, x);        // Check if m is significantly larger than 2*x
    check_large_x_invariant(n, m, x);         // Check if x is large relative to n or m
    check_large_dimensions_invariant(n, m, x); // Check for large dimensions with large x
    
    for (int i = 0; i < n - 2 * x + 2; i++)
        for (int j = 0; j < m - 2 * x + 2; j++)
            if (i % 2 == j % 2) ans++;
    
    for (int i = 0; i < n - 2 * (x + 1) + 2; i++)
        for (int j = 0; j < m - 2 * (x + 1) + 2; j++)
            if (i % 2 == j % 2) ans--;
    
    cout << ans;
    return 0;
}