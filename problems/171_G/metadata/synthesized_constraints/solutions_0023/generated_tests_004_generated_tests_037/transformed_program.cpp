#include <bits/stdc++.h>
using namespace std;

int a0, a1, n;

void check_recursion_depth_invariant(int n) {
    if (n >= 15) { // Threshold chosen based on the problem constraints (1 ≤ n ≤ 20)
        cerr << "Warning: Performance bottleneck condition triggered due to high recursion depth!" << endl;
        abort();
    }
}

void check_repeated_calculation_invariant(int n) {
    if (n >= 15) { // Same threshold as above, due to exponential call growth
        cerr << "Warning: Performance bottleneck condition triggered due to repeated calculations!" << endl;
        abort();
    }
}

int f(int n) {
    if (n == 0) return a0;
    if (n == 1) return a1;
    return f(n - 1) + f(n - 2);
}

int main() {
    cin >> a0 >> a1 >> n;

    // Insert performance checkers here to avoid overhead inside recursive calls
    check_recursion_depth_invariant(n);
    check_repeated_calculation_invariant(n);

    cout << f(n) << endl;
    return 0;
}