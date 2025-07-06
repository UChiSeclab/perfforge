#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-9;
const double PI = 2 * acos(0.0);

void check_iteration_count(long long b) {
    if (b > 1000000) { // Example threshold; adjust as needed based on typical performance limits
        cerr << "Warning: Performance bottleneck condition triggered - high iteration count due to large b!" << endl;
        abort();
    }
}

void check_large_computation(long long a, long long b) {
    if (a > 1000 && b > 1000000) { // Example thresholds for large computations
        cerr << "Warning: Performance bottleneck condition triggered - large arithmetic operations!" << endl;
        abort();
    }
}

void check_modulo_operations(long long b) {
    if (b > 1000000) { // Example threshold
        cerr << "Warning: Performance bottleneck condition triggered - expensive modulo operations!" << endl;
        abort();
    }
}

int main() {
    long long int a, b, re, sum = 0;
    scanf("%lld", &a);
    scanf("%lld", &b);
    
    // Insert checker functions at this point to preemptively detect performance bottlenecks
    check_iteration_count(b);
    check_large_computation(a, b);
    check_modulo_operations(b);
    
    long long int ff = (a * (a + 1)) / 2;
    ff %= 1000000007;
    
    for (long long int i = 1; i < b; i++) {
        sum += i * a + ((i * b) % 1000000007 * ff) % 1000000007;
        sum %= 1000000007;
    }
    
    printf("%lld ", sum);
    printf("\n");
}