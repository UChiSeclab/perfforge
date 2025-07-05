#include <bits/stdc++.h>
using namespace std;

// Checker for large t, indicating many iterations
void check_large_t_invariant(int t) {
    if (t > 90) { // Threshold close to the upper constraint of 100
        cerr << "Warning: Performance bottleneck condition triggered - large number of iterations due to t!" << endl;
        abort();
    }
}

// Checker for large values in input sequence
void check_large_values_invariant(int p) {
    if (p > 900) { // Arbitrary high value to indicate computational increase
        cerr << "Warning: Performance bottleneck condition triggered - large values in input sequence!" << endl;
        abort();
    }
}

int main() {
    int t;
    cin >> t;
    check_large_t_invariant(t); // Check after reading t

    int count = 1;
    long long int sum = 0;
    while (t--) {
        int p;
        cin >> p;
        check_large_values_invariant(p); // Check for each value of p

        sum += count * p;
        count++;
    }
    cout << sum << endl;
    return 0;
}