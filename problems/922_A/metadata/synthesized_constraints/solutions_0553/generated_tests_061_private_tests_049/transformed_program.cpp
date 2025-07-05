#include <bits/stdc++.h>
using namespace std;

// Checker functions for performance invariants
void check_large_discrepancy(long long a, long long b) {
    if (b < 10 && a > 1000000) {
        cerr << "Warning: Performance bottleneck condition triggered due to large discrepancy between a and b!" << endl;
        abort();
    }
}

void check_initial_conditions(long long a, long long b) {
    if (b == 1 && a > 1000000) {
        cerr << "Warning: Performance bottleneck condition triggered due to insufficient initial copied toys!" << endl;
        abort();
    }
}

void check_iteration_growth(long long a, long long b) {
    if (a > 1000000 && b < 10) {
        cerr << "Warning: Performance bottleneck condition triggered due to iteration growth!" << endl;
        abort();
    }
}

int main() {
    long long int a, b, cp, k, i, org;
    cin >> a >> b;

    // Insert checks after input is read
    check_large_discrepancy(a, b);   // Check for large discrepancy between a and b
    check_initial_conditions(a, b);  // Check for insufficient initial copies
    check_iteration_growth(a, b);    // Check for potential iteration growth issue

    if (b == 0) {
        cout << "No" << endl;
        return 0;
    }
    org = b;
    cp = b - 1;
    while (cp > 0 && cp < a) {
        cp += 2;
    }
    if (a == cp && b == org) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}