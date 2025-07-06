#include <bits/stdc++.h>
using namespace std;

// Function to check for large 'b' which might cause performance bottleneck
void check_large_b_invariant(long long b) {
    if (b > 1000000) {  // Arbitrary threshold for demonstration purposes
        cerr << "Warning: Performance bottleneck condition triggered due to large b!" << endl;
        abort();
    }
}

// Function to check for arithmetic complexity
void check_arithmetic_complexity_invariant(long long b) {
    if (b > 1000000) {  // Threshold to ensure we catch potential slowdowns
        cerr << "Warning: Arithmetic complexity bottleneck due to large b!" << endl;
        abort();
    }
}

// Function to check for conditional logic complexity
void check_conditional_logic_invariant(long long b) {
    if (b > 1000000) {  // This bounds the loop operations
        cerr << "Warning: Conditional logic bottleneck due to large b!" << endl;
        abort();
    }
}

int main() {
    long long a, b, p, d, num, sum;
    cin >> a >> b;

    // Check performance-related invariants based on the input
    check_large_b_invariant(b);
    check_arithmetic_complexity_invariant(b);
    check_conditional_logic_invariant(b);

    long long i;
    sum = 0;
    for (i = 1; i < b; i++) {
        long long k = (i * b + i) * 2;
        int flag = 0;
        if (a % 2 == 0) {
            p = a / 2;
            flag = 1;
        } else {
            p = a;
        }
        if (flag == 0) {
            k = k / 2;
            num = (a - 1) / 2;
            flag = 1;
        } else {
            num = (a - 1);
        }
        d = (k + ((((num) * b) % 1000000007) * i) % 1000000007) % 1000000007;
        sum += (p * d) % 1000000007;
        sum = sum % 1000000007;
    }
    cout << sum << endl;
    return 0;
}