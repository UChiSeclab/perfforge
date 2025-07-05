#include <bits/stdc++.h>
using namespace std;

long long a, b;

// Checkers for performance-characterizing invariants
void check_exponential_growth_invariant(int n) {
    if (n > 15) { // Threshold based on recursion depth
        cerr << "Warning: Exponential recursion growth condition triggered!" << endl;
        abort();
    }
}

void check_recursion_depth_invariant(int n) {
    if (n > 15) { // Threshold based on recursion depth
        cerr << "Warning: Recursion depth condition triggered!" << endl;
        abort();
    }
}

void check_branching_factor_invariant(int n) {
    if (n > 15) { // Threshold for branching factor leading to exponential calls
        cerr << "Warning: High branching factor condition triggered!" << endl;
        abort();
    }
}

long long f(long long n) {
    if (n == 0) return a;
    if (n == 1) return b;
    return f(n - 1) + f(n - 2);
}

int main() {
    long long n;
    cin >> a >> b;
    cin >> n;
    
    // Check for conditions that may lead to performance bottlenecks.
    check_exponential_growth_invariant(n);
    check_recursion_depth_invariant(n);
    check_branching_factor_invariant(n);

    cout << f(n);
    return 0;
}