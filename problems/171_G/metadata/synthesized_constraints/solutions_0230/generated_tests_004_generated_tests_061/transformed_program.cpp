#include <iostream>
using namespace std;

int a, b, c;
int f(int n, int depth = 0); // Added recursion depth tracking

// Helper function for checking recursion depth
void check_recursion_depth_invariant(int depth) {
    if (depth > 15) { // Assuming a threshold for recursion depth
        cerr << "Warning: Performance bottleneck condition triggered due to deep recursion!" << endl;
        abort();
    }
}

// Helper function to check for excessive repeated calculations
void check_repeated_calculation_invariant(int n) {
    if (n > 15) { // Assuming n > 15 will result in noticeable repeated calculations
        cerr << "Warning: Performance bottleneck condition triggered due to excessive repeated calculations!" << endl;
        abort();
    }
}

int main() {
    cin >> a >> b >> c;

    // Check for performance bottleneck conditions before entering the recursive function
    check_repeated_calculation_invariant(c);

    cout << f(c);
    return 0;
}

// Recursive function with depth tracking
int f(int n, int depth) {
    check_recursion_depth_invariant(depth); // Check recursion depth before proceeding

    if (n == 0) {
        return a;
    }
    if (n == 1) {
        return b;
    }
    // Increment depth at each recursive call
    return f(n - 2, depth + 1) + f(n - 1, depth + 1);
}