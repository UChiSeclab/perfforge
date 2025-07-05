#include <bits/stdc++.h>
using namespace std;

// Check function for large b
void check_large_b_invariant(long long b) {
    if (b > 10000000) {  // Threshold chosen based on the constraint
        cerr << "Warning: Performance bottleneck condition triggered - b is large!" << endl;
        abort();
    }
}

// Check function for loop conditions
void check_loop_invariant(long long b, long long t1, long long a) {
    if ((b > 10000000) && (t1 == b - 1) && (a % 2 == 0)) {
        cerr << "Warning: Performance bottleneck condition triggered - extensive loop with large b!" << endl;
        abort();
    }
}

// Check function for excessive iterations
void check_modulo_operations_invariant(long long iterations) {
    if (iterations > 10000000) {  // Arbitrarily chosen threshold for excessive iterations
        cerr << "Warning: Performance bottleneck condition triggered - excessive modulo operations!" << endl;
        abort();
    }
}

int main() {
    long long a, b;
    while (scanf("%lld%lld", &a, &b) != -1) {
        // Check if b is excessively large before entering the loop
        check_large_b_invariant(b);
        
        long long t, t1;
        long long sum = 0;
        long long k1, k2;
        long long iteration_count = 0;  // To track the number of iterations
        
        for (t1 = 1; t1 < b; t1++) {
            iteration_count++;
            
            if (a % 2 == 0) {
                k1 = a / 2;
                k2 = (a * t1 + t1);
            } else {
                k1 = (a * t1 + t1) / 2;
                k2 = a;
            }
            
            long long p = ((((((k1 % 1000000007) * (k2 % 1000000007)) % 1000000007) %
                           1000000007) * (b % 1000000007)) %
                         1000000007 + (((a % 1000000007) * (t1 % 1000000007)) % 1000000007)) % 1000000007;
            
            sum = sum % 1000000007;
            sum = (p + sum) % 1000000007;
            
            // Check conditions inside the loop
            check_loop_invariant(b, t1, a);
        }
        
        // Check if the number of iterations is excessively high
        check_modulo_operations_invariant(iteration_count);
        
        cout << sum << endl;
    }
}