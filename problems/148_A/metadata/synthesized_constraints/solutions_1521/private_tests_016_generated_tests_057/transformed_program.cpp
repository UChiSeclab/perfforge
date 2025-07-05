#include <bits/stdc++.h>
using namespace std;

// Function to check high iteration count
void check_high_iteration_count(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - high iteration count due to large d." << endl;
        abort();
    }
}

// Function to check complex condition evaluation
void check_complex_condition_evaluation(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - complex condition evaluation due to none of k, l, m, n being 1." << endl;
        abort();
    }
}

// Function to check divisibility spread
void check_divisibility_spread(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - inefficient divisibility spread causing more condition checks." << endl;
        abort();
    }
}

int main() {
    int k, l, m, n, d;
    int count(0);
    cin >> k >> l >> m >> n >> d;
    count = d;
    
    // Insert checks after input reading and before processing
    check_high_iteration_count(d > 10000); // Check for large d causing high iterations
    check_complex_condition_evaluation((k != 1 && l != 1 && m != 1 && n != 1)); // Check if none of the divisors is 1
    check_divisibility_spread(d > 5000 && k * l * m * n > 200); // Example condition for inefficient spread

    if (k == 1 || l == 1 || m == 1 || n == 1) {
        cout << d << endl;
    } else {
        for (int i = 1; i <= d; i++) {
            if ((i % k != 0) && (i % l != 0) && (i % m != 0) && (i % n != 0)) count--;
        }
        cout << count << endl;
    }
    
    return 0;
}