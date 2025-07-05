#include <bits/stdc++.h>

int m;
int _moves = -1;

// Checkers
void check_large_ratio_invariant(int n, int m, int depth) {
    if (depth > 50 && (m / n > 1000000)) {
        std::cerr << "Warning: Performance bottleneck condition triggered - large n to m ratio with deep recursion!" << std::endl;
        abort();
    }
}

void check_recursive_inefficiency(int n, int m) {
    if (n > m && m > 100000000) {
        std::cerr << "Warning: Performance bottleneck condition triggered - excessive recursion with large m!" << std::endl;
        abort();
    }
}

void check_multiplicative_growth(int n, int m, int moves) {
    if (moves > 100 && (m % n != 0)) {
        std::cerr << "Warning: Performance bottleneck condition triggered - high moves with non-linear growth!" << std::endl;
        abort();
    }
}

void solve(int n, int moves) {
    check_large_ratio_invariant(n, m, moves);  // Check for large ratio
    check_recursive_inefficiency(n, m);        // Check for inefficiency
    check_multiplicative_growth(n, m, moves);  // Check for multiplicative growth

    if (n == m) {
        _moves = moves;
        return;
    } else if (n > m)
        return;
    else if (_moves == -1) {
        solve(n * 2, moves + 1);
        if (_moves == -1) solve(n * 3, moves + 1);
    }
    return;
}

int main(int argc, char const *argv[]) {
    int n;
    std::cin >> n >> m;
    solve(n, 0);
    std::cout << _moves << std::endl;
    return 0;
}