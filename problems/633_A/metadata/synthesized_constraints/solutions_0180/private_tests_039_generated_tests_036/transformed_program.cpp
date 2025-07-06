#include <bits/stdc++.h>
using namespace std;

// Function to check for common divisor invariant
void check_common_divisor_invariant(int a, int b, int c) {
    if (std::gcd(a, b) % c != 0 && a != c && b != c) {
        cerr << "Warning: Potential infinite loop due to common divisor invariant!" << endl;
        abort();
    }
}

// Function to check for gcd divisor invariant
void check_gcd_divisor_invariant(int a, int b, int c) {
    if (c % std::gcd(a, b) != 0) {
        cerr << "Warning: No solution possible due to GCD not dividing c!" << endl;
        abort();
    }
}

// Function to check for iterative overhead invariant
void check_iterative_overhead_invariant(int a, int b, int c) {
    if (a < c / 100 && b < c / 100) {
        cerr << "Warning: High number of iterations due to small a and b relative to c!" << endl;
        abort();
    }
}

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    // Check performance invariants before starting heavy computation
    check_common_divisor_invariant(a, b, c);
    check_gcd_divisor_invariant(a, b, c);
    check_iterative_overhead_invariant(a, b, c);

    if (a == c || b == c) {
        cout << "YES" << endl;
        return 0;
    }
    if (a > c && b > c) {
        cout << "NO" << endl;
        return 0;
    }
    int cur = 0;
    int cur_b = 0;
    for (int i = 0; i < 10010; i++) {
        for (int i = 0; i < 10010; i++) {
            if ((cur + cur_b) == c) {
                cout << "YES" << endl;
                return 0;
            }
            cur_b += b;
        }
        cur_b = 0;
        cur += a;
    }
    cout << "NO" << endl;
    return 0;
}