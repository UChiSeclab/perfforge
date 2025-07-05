#include <bits/stdc++.h>
using namespace std;

int a1, a2, a3;

void check_recursion_invariant(int n) {
    if (n > 15) {  // Assuming a threshold based on the problem constraints
        cerr << "Warning: Recursion depth too high - potential performance bottleneck!" << endl;
        abort();
    }
}

void check_function_call_growth(int n) {
    if (n > 15) {  // Same threshold to detect exponential growth
        cerr << "Warning: Exponential growth in function calls - performance may degrade!" << endl;
        abort();
    }
}

int f(int n) {
    // Check for recursion depth and exponential growth
    check_recursion_invariant(n);
    check_function_call_growth(n);
    
    if (n == 0) return a1;
    if (n == 1) return a2;
    return f(n - 1) + f(n - 2);
}

int main() {
    cin >> a1 >> a2 >> a3;
    
    // Check before starting the recursive function calls
    check_recursion_invariant(a3);
    check_function_call_growth(a3);

    cout << f(a3);
    return 0;
}