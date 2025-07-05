#include <bits/stdc++.h>
using namespace std;

// Checker functions as described above
void check_large_n_with_loops(int n) {
    if (n > 3500) {
        cerr << "Warning: Performance bottleneck condition triggered - large n with nested iterations!" << endl;
        abort();
    }
}

void check_frequent_feasibility_checks(int feasibilityCheckCount, int totalIterations) {
    if (feasibilityCheckCount > totalIterations / 2) {
        cerr << "Warning: Performance bottleneck condition triggered - frequent feasibility checks!" << endl;
        abort();
    }
}

void check_high_max_updates(int maxUpdateCount, int totalIterations) {
    if (maxUpdateCount > totalIterations / 10) {
        cerr << "Warning: Performance bottleneck condition triggered - frequent max updates!" << endl;
        abort();
    }
}

int main() {
    int n, a, b, c;
    int max_pieces = 0;
    cin >> n >> a >> b >> c;

    // Place the first check after reading input to detect large n
    check_large_n_with_loops(n);

    int feasibilityCheckCount = 0;
    int maxUpdateCount = 0;
    int totalIterations = 0;

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            totalIterations++;
            int k = (n - (i * a + j * b)) / c;
            if ((k * c + i * a + j * b) == n && k >= 0) {
                feasibilityCheckCount++;
                int m = i + j + k;
                if (m > max_pieces) {
                    max_pieces = m;
                    maxUpdateCount++;
                }
            }
        }
    }

    // Place additional checks after loops to detect frequent conditions
    check_frequent_feasibility_checks(feasibilityCheckCount, totalIterations);
    check_high_max_updates(maxUpdateCount, totalIterations);

    cout << max_pieces;
    return 0;
}