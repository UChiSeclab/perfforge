#include <bits/stdc++.h>
using namespace std;

// Checker for large outer loop iterations
void check_outer_loop_invariant(long long m, long long b) {
    if (m * b > 10000) {  // Arbitrary threshold considering maximum input constraints
        cerr << "Warning: Performance bottleneck condition triggered - large outer loop iterations!" << endl;
        abort();
    }
}

// Checker for nested loop with high iteration count
void check_inner_loop_invariant(long long i, long long m, long long b) {
    long long y = ((-i) / m) + b;
    if (y > 1000) {  // Arbitrary threshold to detect high iterations in inner loop
        cerr << "Warning: Performance bottleneck condition triggered - high inner loop iterations!" << endl;
        abort();
    }
}

// Checker for arithmetic operations overhead
void check_arithmetic_invariant(long long m, long long b) {
    if (m * b > 5000) {  // Arbitrary threshold considering potential arithmetic overhead
        cerr << "Warning: Performance bottleneck condition triggered - high arithmetic operations!" << endl;
        abort();
    }
}

int main() {
    long long int m, b, i, j;
    cin >> m >> b;

    // Check for performance bottlenecks based on the input parameters
    check_outer_loop_invariant(m, b);
    check_arithmetic_invariant(m, b);

    long long int max = 0, ans = 0;
    for (i = 0; i <= (m * b); i = i + m) {
        ans = 0;
        long long int y = ((-i) / m) + b;

        // Check each iteration of the outer loop for potential inner loop bottlenecks
        check_inner_loop_invariant(i, m, b);

        for (j = 0; j <= y; j++) {
            ans += (i * (i + 1)) / 2;
            ans += j * (i + 1);
        }
        if (ans > max) {
            max = ans;
        }
    }
    cout << max << endl;
    return 0;
}