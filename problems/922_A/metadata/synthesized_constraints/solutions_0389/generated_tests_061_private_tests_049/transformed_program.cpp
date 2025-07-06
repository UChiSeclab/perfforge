#include <bits/stdc++.h>
using namespace std;

// Checker function for large `a` with minimal initial copies
void check_large_a_with_minimal_initial_copies(long long a, long long cp) {
    if (a > 100000000 && cp == 0) { // Arbitrary threshold for large a
        cerr << "Warning: Performance bottleneck condition triggered - large a with minimal initial copies!" << endl;
        abort();
    }
}

// Checker function for high discrepancy between `a` and `b`
void check_discrepancy_between_a_and_b(long long a, long long b) {
    if (a > 2 * b) { // Arbitrary threshold for discrepancy
        cerr << "Warning: Performance bottleneck condition triggered - high discrepancy between a and b!" << endl;
        abort();
    }
}

int main() {
    long long int a, b, cp, k, i, org;
    cin >> a >> b;
    
    // Check for performance bottlenecks after reading input
    check_large_a_with_minimal_initial_copies(a, 0); // Initially, cp is 0
    check_discrepancy_between_a_and_b(a, b);

    if (b == 0) {
        cout << "No" << endl;
        return 0;
    }
    org = 1, cp = 0;
    while (org < b) {
        org++;
        cp++;
    }
    while (cp > 0 && cp < a) {
        cp += 2;
    }
    if (a == cp && b == org) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}