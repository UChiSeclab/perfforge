#include <bits/stdc++.h>
using namespace std;

// Checkers for performance invariants
void check_initial_gap_invariant(long long n, long long x, long long y, long long c) {
    long long initial_on_cells = 1; // Initially, only one cell is on
    if (c > initial_on_cells && (x == 1 || x == n || y == 1 || y == n)) {
        cerr << "Warning: Performance bottleneck condition triggered - high initial gap and edge start" << endl;
        abort();
    }
}

void check_large_grid_sparse_activation_invariant(long long n, long long c) {
    long long max_possible_on_cells = n * n;
    if (n > 1000000 && c < max_possible_on_cells / 1000) { // Example threshold
        cerr << "Warning: Performance bottleneck condition triggered - large grid with sparse activation" << endl;
        abort();
    }
}

void check_boundary_effect_invariant(long long n, long long x, long long y) {
    if ((x == 1 || x == n || y == 1 || y == n) && n > 1000000) { // Example threshold
        cerr << "Warning: Performance bottleneck condition triggered - initial cell on boundary of large grid" << endl;
        abort();
    }
}

long long geit(long long u) {
    long long total = 2 * (u + 1) * u + 1;
    if (u > x - 1) {
        total -= (u + 1 - x) * (u + 1 - x);
        if (u > n + x - y) total += (u - n - x + y + 1) * (u - n - x + y) / 2;
    }
    if (u > y - 1) {
        total -= (u + 1 - y) * (u + 1 - y);
        if (u > x + y - 1) total += (u - x - y + 2) * (u - x - y + 1) / 2;
    }
    if (u > n - x) {
        total -= (u + x - n) * (u + x - n);
        if (u > n - x + y) total += (u - n + x - y) * (u - n + x - y + 1) / 2;
    }
    if (u > n - y) {
        total -= (u + y - n) * (u + y - n);
        if (u > 2 * n - x - y + 1)
            total += (u - 2 * n + x + y) * (u - 2 * n + x + y - 1) / 2;
    }
    return total;
}

int main() {
    while (cin >> n >> x >> y >> t) {
        // Insert invariant checks
        check_initial_gap_invariant(n, x, y, t);
        check_large_grid_sparse_activation_invariant(n, t);
        check_boundary_effect_invariant(n, x, y);

        long long mid = 0;
        while (geit(mid) < t) mid++;
        cout << mid << endl;
    }
    return 0;
}