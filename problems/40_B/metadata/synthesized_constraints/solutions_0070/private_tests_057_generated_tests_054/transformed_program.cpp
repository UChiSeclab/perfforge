#include <bits/stdc++.h>
using namespace std;

// Check if n and m remain large after reduction
void check_loop_invariant(int n, int m) {
    if (n > 100 && m > 100) {
        cerr << "Warning: Performance bottleneck condition triggered - large loops!" << endl;
        abort();
    }
}

// Check if n and m allow frequent boundary checks
void check_boundary_invariant(int n, int m, int x) {
    if ((n > 20 || m > 20) && x > 1) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive boundary checks!" << endl;
        abort();
    }
}

// Check if dimensions remain substantial after reduction
void check_reduction_invariant(int n, int m) {
    if (n > 0 && m > 0 && n * m > 10000) {
        cerr << "Warning: Performance bottleneck condition triggered - large computation area after reduction!" << endl;
        abort();
    }
}

int main() {
    cout << fixed;
    cout.precision(9);
    int n, m, x;
    cin >> n >> m >> x;

    // Checkers before computation
    check_loop_invariant(n, m);
    check_boundary_invariant(n, m, x);

    n -= 2 * (x - 1);
    m -= 2 * (x - 1);

    // Additional check after reduction
    check_reduction_invariant(n, m);

    if (n <= 0 || m <= 0) {
        cout << 0 << "\n";
    } else {
        int r = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (i == 0 || j == 0 || i == m - 1 || j == n - 1) {
                    if ((i + j) % 2 == 0) {
                        r++;
                    }
                }
        cout << r << "\n";
    }
    return 0;
}