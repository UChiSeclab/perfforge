#include <bits/stdc++.h>
using namespace std;

// Check for deep recursion due to large `n`
void check_deep_recursion_invariant(int n) {
    if (n >= 15) {
        cerr << "Warning: Performance bottleneck condition triggered - deep recursion due to large n" << endl;
        abort();
    }
}

// Check for exponential growth in computation
void check_exponential_growth_invariant(int n) {
    if (n > 10) {
        cerr << "Warning: Performance bottleneck condition triggered - exponential growth in recursion" << endl;
        abort();
    }
}

// Check for inefficient base case handling
void check_base_case_handling_invariant(int n) {
    if (n > 12) {
        cerr << "Warning: Performance bottleneck condition triggered - inefficient base case handling" << endl;
        abort();
    }
}

int f(int n1, int n2, int n) {
    if (n == 0)
        return n1;
    else if (n == 1)
        return n2;
    return f(n1, n2, n - 1) + f(n1, n2, n - 2);
}

int main() {
    int n1, n2, n;
    cin >> n1 >> n2 >> n;

    // Inserted checks to detect potential performance bottlenecks
    check_deep_recursion_invariant(n);
    check_exponential_growth_invariant(n);
    check_base_case_handling_invariant(n);

    cout << f(n1, n2, n);
}