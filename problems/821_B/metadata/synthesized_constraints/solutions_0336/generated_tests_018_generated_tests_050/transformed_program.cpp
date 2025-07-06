#include <bits/stdc++.h>
using namespace std;

// Define the check functions
void check_large_iteration_space_invariant(long long m, long long b) {
    if (m * b > 1e7) { // Arbitrary threshold based on saturation of performance
        cerr << "Warning: Performance bottleneck condition triggered - large iteration space!" << endl;
        abort();
    }
}

void check_expensive_computation_invariant(long long m) {
    if (m > 500) { // Assumes large m affects `ceil` negatively in high iteration counts
        cerr << "Warning: Performance bottleneck condition triggered - expensive computation in loop!" << endl;
        abort();
    }
}

void check_quadratic_summation_invariant(long long m, long long b) {
    if ((m * b) > 1e7) { // Simplified threshold for loop checks
        cerr << "Warning: Performance bottleneck condition triggered - quadratic summation operations!" << endl;
        abort();
    }
}

int main() {
    long long m, b;
    long long maxx = 0;
    cin >> m >> b;

    // Check for large iteration space
    check_large_iteration_space_invariant(m, b);
    
    // Check for expensive computation in loop
    check_expensive_computation_invariant(m);
    
    // Check for quadratic summation operations
    check_quadratic_summation_invariant(m, b);

    for (long long i = 0; i <= m * b; i++) {
        long long t = (-1) * ceil((float)i / m) + b;
        long long sum = (t * (t + 1) / 2) * (i + 1) + (i * (i + 1) / 2) * (t + 1);
        maxx = max(maxx, sum);
    }
    cout << maxx;
}