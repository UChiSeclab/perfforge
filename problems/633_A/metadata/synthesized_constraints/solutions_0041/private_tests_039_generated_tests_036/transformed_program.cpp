#include <bits/stdc++.h>
using namespace std;

// Checker function for equal damage values
void check_equal_damage_invariant(int a, int b) {
    if (a == b) {
        cerr << "Warning: Performance bottleneck condition triggered - equal damage values detected!" << endl;
        abort();
    }
}

// Checker function for high `c` relative to `a` and `b`
void check_high_c_invariant(int a, int b, int c) {
    if (c > 100 * std::min(a, b)) {
        cerr << "Warning: Performance bottleneck condition triggered - high `c` relative to `a` and `b`!" << endl;
        abort();
    }
}

// Checker function for lack of early exits
void check_early_exit_invariant(int a, int b, int c) {
    int gcd_ab = std::__gcd(a, b);
    if (c % gcd_ab != 0) {
        cerr << "Warning: Performance bottleneck condition triggered - lack of early exits possible due to gcd!" << endl;
        abort();
    }
}

int main() {
    int a, b, c;
    while (~scanf("%d%d%d", &a, &b, &c)) {
        check_equal_damage_invariant(a, b);  // Check for equal damage
        check_high_c_invariant(a, b, c);     // Check for high c relative to a and b
        check_early_exit_invariant(a, b, c); // Check for gcd condition

        int i, j;
        int isok = 0;
        for (i = 0; i < 10000; ++i) {
            for (j = 0; j < 10000; ++j) {
                int fuck = a * i + b * j;
                if (i == 0 && j == 0) continue;
                if (fuck > c) continue;
                if (c % fuck == 0) {
                    isok = 1;
                    goto c;
                }
            }
        }
    c:;
        if (isok)
            puts("Yes");
        else
            puts("No");
    }
    return 0;
}