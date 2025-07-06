#include <bits/stdc++.h>
using namespace std;

// Checker functions from Phase 3
void check_high_iteration_loop(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - high iteration loop!" << endl;
        abort();
    }
}

void check_inefficient_modulo_operation(int a, int m) {
    if (a % m < m / 10) { // Arbitrary threshold for small increments
        cerr << "Warning: Performance bottleneck condition triggered - inefficient modulo operation!" << endl;
        abort();
    }
}

void check_stagnant_incremental_change(int previous_a, int current_a) {
    if (previous_a == current_a) { // Detects if there is no change
        cerr << "Warning: Performance bottleneck condition triggered - stagnant incremental change!" << endl;
        abort();
    }
}

int main() {
    int a, m;
    cin >> a >> m;

    // Pre-loop check for a potentially high iteration loop
    check_high_iteration_loop(a > 1e7); // Example threshold check before entering the loop

    int previous_a; // To track changes in 'a'

    while (a <= 1e8) {
        previous_a = a; // Store the previous value of 'a'
        
        // Insert check for inefficient modulo operation
        check_inefficient_modulo_operation(a, m);

        a += a % m;
        
        // Insert check for stagnant incremental change
        check_stagnant_incremental_change(previous_a, a);

        if (a % m == 0) {
            cout << "Yes";
            exit(0);
        }
    }

    cout << "No" << endl;
}