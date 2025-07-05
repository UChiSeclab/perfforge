#include <bits/stdc++.h>
using namespace std;

// Checker functions implementing performance-characterizing invariants
void check_large_difference_invariant(int k, int y) {
    if (k <= y) {
        cerr << "Warning: Performance bottleneck condition triggered - large initial difference between k and y!" << endl;
        abort();
    }
}

void check_high_iteration_invariant(int k, int y) {
    if (y > 1000000 * k) {
        cerr << "Warning: Performance bottleneck condition triggered - high number of iterations due to y being much larger than k!" << endl;
        abort();
    }
}

int main() {
    int x, y, n, k, ki;
    cin >> y >> k >> n;

    // Check for potential performance bottlenecks
    check_large_difference_invariant(k, y);
    check_high_iteration_invariant(k, y);

    ki = k;
    while (k - y <= 0) k += ki;
    x = k - y;
    if (x + y > n) {
        cout << "-1" << endl;
        return 0;
    }
    while (x + y <= n) {
        cout << x << " ";
        k += ki;
        x = k - y;
    }
    cout << endl;
    return 0;
}