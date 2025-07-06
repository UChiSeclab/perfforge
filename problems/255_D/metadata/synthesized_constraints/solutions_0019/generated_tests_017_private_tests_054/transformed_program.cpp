#include <bits/stdc++.h>
using namespace std;

// Check if the initial active cell is near the edge
void checkSparseCoverageInvariant(long long x, long long y, long long n) {
    if (x == 1 || x == n || y == 1 || y == n) {
        cerr << "Warning: Performance bottleneck condition triggered - Initial active cell near grid edge!" << endl;
        abort();
    }
}

// Check if c is too high relative to grid size
void checkHighCInvariant(long long c, long long n) {
    if (c > n * n / 2) {
        cerr << "Warning: Performance bottleneck condition triggered - High c relative to grid size!" << endl;
        abort();
    }
}

// Check if the grid size is excessively large
void checkLargeGridInvariant(long long n) {
    if (n > 10000) { // Arbitrary large threshold based on problem constraints
        cerr << "Warning: Performance bottleneck condition triggered - Very large grid size!" << endl;
        abort();
    }
}

int main() {
    long long n, x, y, c;
    while (cin >> n >> x >> y >> c) {
        // Insert checks after reading input
        checkSparseCoverageInvariant(x, y, n);
        checkHighCInvariant(c, n);
        checkLargeGridInvariant(n);
        
        long long r[4] = {y - 1, x - 1, n - y, n - x};
        long long t = 0;
        long long cnt = 1;
        for (;;) {
            for (int i = 0; i < 4; i++) {
                cnt += t - min(max(0LL, t - r[i]) + max(0LL, t - 1 - r[(i + 1) % 4]), t);
            }
            if (cnt >= c) break;
            ++t;
        }
        cout << t << endl;
    }
}