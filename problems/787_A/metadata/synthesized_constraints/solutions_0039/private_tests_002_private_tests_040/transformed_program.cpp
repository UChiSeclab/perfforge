#include <bits/stdc++.h>
using namespace std;

// Function to check invariant 1
void check_equal_increments(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - equal increments with close initial times!" << endl;
        abort();
    }
}

// Function to check invariant 2
void check_small_difference(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - small initial difference with equal/factorial increments!" << endl;
        abort();
    }
}

// Function to check invariant 3
void check_gcd_condition(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - initial difference not a multiple of GCD of increments!" << endl;
        abort();
    }
}

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    // Check for equal increments with close initial times
    check_equal_increments(a == c && abs(b - d) < max(a, c));

    // Check for small initial differences with equal/factorial increments
    check_small_difference((a == c || a % c == 0 || c % a == 0) && abs(b - d) < 10);

    // Check if the difference is not a multiple of GCD of increments
    check_gcd_condition(abs(b - d) % __gcd(a, c) != 0);

    // Main loop to find the first common scream time
    while (b != d && b < 1e8) {
        b < d ? b += a : d += c;
    }

    if (b == d) {
        cout << b << endl;
    } else {
        cout << "-1\n";
    }
    return 0;
}