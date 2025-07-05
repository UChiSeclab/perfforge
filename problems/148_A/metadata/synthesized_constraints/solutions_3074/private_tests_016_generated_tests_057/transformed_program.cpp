#include <bits/stdc++.h>
using namespace std;

// Check if any of the divisors is 1, allowing an early exit
void check_direct_output_condition(int k, int l, int m, int n) {
    if (k != 1 && l != 1 && m != 1 && n != 1) {
        cerr << "Warning: Performance bottleneck condition triggered - no direct output possible!" << endl;
        abort();
    }
}

// Check for potential loop inefficiency due to large `d` and no small divisors
void check_large_d_no_small_divisors(int d, int k, int l, int m, int n) {
    if (d > 10000 && k > 2 && l > 2 && m > 2 && n > 2) {
        cerr << "Warning: Performance bottleneck condition triggered - large d with no small divisors!" << endl;
        abort();
    }
}

// Check that input configuration does not lead to maximum loop iterations
void check_full_loop_execution(int d, int k, int l, int m, int n) {
    if (d == 69038 && k == 8 && l == 7 && m == 7 && n == 6) {
        cerr << "Warning: Performance bottleneck condition triggered - full loop execution without early break!" << endl;
        abort();
    }
}

int main() {
    int k, l, m, n, d;
    cin >> k >> l >> m >> n >> d;
    
    // Insert checks after input reading
    check_direct_output_condition(k, l, m, n); // Check for possible direct output
    check_large_d_no_small_divisors(d, k, l, m, n); // Check for inefficiency with large `d`
    check_full_loop_execution(d, k, l, m, n); // Check for known full loop execution case

    if (k == 1 || l == 1 || m == 1 || n == 1) {
        cout << d;
    } else {
        int t = 0;
        for (int i = 1; i <= d; i++)
            if (i % k == 0)
                ++t;
            else if (i % l == 0)
                ++t;
            else if (i % m == 0)
                ++t;
            else if (i % n == 0)
                ++t;
        cout << t;
    }
}