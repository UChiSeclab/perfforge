#include <bits/stdc++.h>
using namespace std;

// Checker function for large loop execution condition
void check_loop_condition(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered! Large loop execution." << endl;
        abort();
    }
}

// Checker function for excessive modulus operations
void check_modulus_operations(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck due to excessive modulus operations!" << endl;
        abort();
    }
}

int main() {
    int k, l, m, n, d, count = 0;
    cin >> k >> l >> m >> n >> d;
    count = d;
    
    // Insert check for large loop execution
    check_loop_condition(k > 1 && l > 1 && m > 1 && n > 1 && d > 80000); // Example threshold: d > 80000
    
    if (k == 1 || m == 1 || n == 1 || l == 1) {
        cout << d;
    } else {
        // Insert check for excessive modulus operations before the loop
        check_modulus_operations(d > 80000); // Example threshold: d > 80000

        for (int i = 0; i <= d; i++) {
            if (i % k != 0 && i % l != 0 && i % m != 0 && i % n != 0) count--;
        }
        cout << count;
    }
}