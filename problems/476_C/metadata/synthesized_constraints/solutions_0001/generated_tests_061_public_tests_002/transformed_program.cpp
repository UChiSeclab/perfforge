#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;

// Checker functions for performance bottlenecks
void check_large_iteration_count(int b) {
    if (b > 5000000) {  // Threshold chosen based on constraints and typical slow path conditions
        cerr << "Warning: Performance bottleneck condition triggered - large iteration count due to high value of b!" << endl;
        abort();
    }
}

void check_iteration_dependent_computation(int b) {
    if (b > 5000000) {  // Same threshold as above
        cerr << "Warning: Performance bottleneck condition triggered - repeated arithmetic operations in a high iteration loop!" << endl;
        abort();
    }
}

void check_multiplicative_overhead(int b) {
    if (b > 5000000) {  // Same threshold as others for consistency
        cerr << "Warning: Performance bottleneck condition triggered - multiplicative overhead in loop iterations!" << endl;
        abort();
    }
}

int main() {
    int a, b;
    scanf("%d%d", &a, &b);

    // Insert checkers after reading inputs
    check_large_iteration_count(b);
    check_iteration_dependent_computation(b);
    check_multiplicative_overhead(b);

    long long int ans = 0;
    for (int i = 1; i < b; i++) {
        int n = a;
        long long int temp;
        if (n % 2 == 0) {
            temp = n + 1;
            temp = (temp * (n / 2)) % mod;
            temp = (temp * i) % mod;
        } else {
            temp = n;
            temp = (temp * ((n + 1) / 2)) % mod;
            temp = (temp * i) % mod;
        }
        temp = (temp * b) % mod;
        ans = (ans + temp) % mod;
        temp = ((long long int)i * n) % mod;
        ans = (ans + temp) % mod;
    }
    cout << ans;
}