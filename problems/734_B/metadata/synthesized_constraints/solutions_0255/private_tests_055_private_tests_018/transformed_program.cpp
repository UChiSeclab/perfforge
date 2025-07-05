#include <bits/stdc++.h>
using namespace std;

// Checker function to detect high availability of digits 2, 5, and 6
void check_digit_availability_invariant(int k2, int k5, int k6) {
    if (k2 > 1000000 && k5 > 1000000 && k6 > 1000000) {
        cerr << "Warning: Performance bottleneck condition triggered due to high availability of digits 2, 5, and 6!" << endl;
        abort();
    }
}

// Checker function to detect excessive loop iterations before termination
void check_exhaustion_condition(int k2, int k3, int k5, int k6) {
    if (k2 > 1000000 && (k2 - min({k3, k5, k6})) > 1000000) {
        cerr << "Warning: Performance bottleneck condition triggered due to excessive loop iterations before termination!" << endl;
        abort();
    }
}

// Main function
int main() {
    int k2, k3, k5, k6;
    int r = 0;
    cin >> k2 >> k3 >> k5 >> k6;

    // Check for performance bottlenecks
    check_digit_availability_invariant(k2, k5, k6);
    check_exhaustion_condition(k2, k3, k5, k6);

    while (1) {
        if (k2 != 0 && k5 != 0 && k6 != 0) {
            r = r + 256;
            k2--;
            k5--;
            k6--;
        }
        if (k2 != 0 && k3 != 0 && k5 == 0 || k2 != 0 && k3 != 0 && k6 == 0) {
            r = r + 32;
            k2--;
            k3--;
        }
        if (k2 == 0 || (k3 == 0 && k5 == 0) || (k3 == 0 && k6 == 0)) break;
    }
    cout << r << endl;
}