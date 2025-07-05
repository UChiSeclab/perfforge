#include <bits/stdc++.h>
using namespace std;

// Checker for common divisor invariant
void check_common_divisor_invariant(int a, int b, int c) {
    int gcd = std::gcd(a, b);
    if (gcd > 1 && c % gcd != 0) {
        cerr << "Warning: Performance bottleneck condition triggered - common divisor issue!" << endl;
        abort();
    }
}

// Checker for small close values invariant
void check_small_close_values_invariant(int a, int b, int c) {
    if ((a != c && b != c && a + b != c) && (a - b <= 2 || b - a <= 2)) {
        cerr << "Warning: Performance bottleneck condition triggered - small close values!" << endl;
        abort();
    }
}

int main() {
    long long i, j, a, b, c, t, n;
    cin >> a >> b >> c;

    // Place the invariant checkers before the heavy nested loops
    check_common_divisor_invariant(a, b, c);
    check_small_close_values_invariant(a, b, c);

    if (a == c || b == c || a + b == c) {
        cout << "YES" << endl;
        return 0;
    } else {
        for (i = 0; i <= 10000; i++) {
            for (j = 0; j <= 10000; j++) {
                if (a * i + b * j == c) {
                    cout << "YES" << endl;
                    return 0;
                } else
                    continue;
            }
        }
        cout << "NO" << endl;
    }
}