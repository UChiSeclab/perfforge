#include <bits/stdc++.h>
using namespace std;

// Function to check nested loop exhaustion
void check_nested_loop_exhaustion(int a, int b, int c, int d) {
    if (std::gcd(a, c) == 1 && ((d - b) % std::gcd(a, c)) != 0) {
        cerr << "Warning: Performance bottleneck condition triggered - nested loop exhaustion likely!" << endl;
        abort();
    }
}

// Function to check lack of early termination
void check_early_termination(int a, int b, int c, int d) {
    if (std::gcd(a, c) == 1 && ((d - b) % std::gcd(a, c)) != 0) {
        cerr << "Warning: Early termination unlikely - loops will fully execute!" << endl;
        abort();
    }
}

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    // Insert checks after reading inputs
    check_nested_loop_exhaustion(a, b, c, d);
    check_early_termination(a, b, c, d);

    for (int i = 0; i < 9999; i++) {
        for (int j = 0; j < 9999; j++) {
            if (b + (a * i) == d + (c * j)) {
                cout << b + (a * i);
                return 0;
            }
        }
    }
    cout << -1 << endl;
    return 0;
}