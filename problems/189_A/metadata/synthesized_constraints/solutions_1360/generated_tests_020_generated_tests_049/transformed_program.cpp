#include <bits/stdc++.h>
using namespace std;

// Invariant checkers
void check_high_iteration_invariant(int n, int a, int b, int c) {
    if (n > 3000 && a < 50 && b < 50 && c < 50) {
        cerr << "Warning: High iteration invariant triggered - excessive combinations" << endl;
        abort();
    }
}

void check_small_piece_sizes_invariant(int n, int a, int b, int c) {
    if (n > 3000 && (a < n/10 || b < n/10 || c < n/10)) {
        cerr << "Warning: Small piece size invariant triggered - extensive search space" << endl;
        abort();
    }
}

void check_large_n_invariant(int n, int a, int b, int c) {
    if (n > 3500 && (a < n/5 && b < n/5 && c < n/5)) {
        cerr << "Warning: Large n invariant triggered - maximizing combinations" << endl;
        abort();
    }
}

int main() {
    int n, a, b, c, piece = 0, i, j, k;
    cin >> n >> a >> b >> c;

    // Insert checks after reading input to prevent unnecessary loop execution
    check_high_iteration_invariant(n, a, b, c);
    check_small_piece_sizes_invariant(n, a, b, c);
    check_large_n_invariant(n, a, b, c);

    if (a == 1 || b == 1 || c == 1) {
        piece = n;
    } else {
        for (i = 0; i <= n / a; i++) {
            for (j = 0; j <= (n - i * a) / b; j++) {
                for (k = 0; k <= (n - i * a - j * b) / c; k++) {
                    if (i * a + j * b + k * c == n) piece = max(piece, i + j + k);
                }
            }
        }
    }
    cout << piece;
    return 0;
}