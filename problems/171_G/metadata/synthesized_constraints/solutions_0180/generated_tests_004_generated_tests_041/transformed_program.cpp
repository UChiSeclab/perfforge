#include <iostream>
using namespace std;

int a1, a2;
int recursiveCallCount = 0; // Track the number of recursive calls

// Checker functions
void check_recursive_depth_invariant(int n) {
    if (n >= 15) {  // Threshold chosen based on the nature of exponential growth
        cerr << "Warning: Performance bottleneck condition triggered - high recursive depth." << endl;
        abort();
    }
}

void check_memoization_invariant(int n, int callCount) {
    if (n >= 15 && callCount > 1000) {  // Call count threshold based on expected exponential calls
        cerr << "Warning: Performance bottleneck condition triggered - excessive recursive calls without memoization." << endl;
        abort();
    }
}

void check_call_overhead_invariant(int n, int callCount) {
    if (n >= 15 && callCount > 500) {  // This threshold accounts for expected recursive growth
        cerr << "Warning: Performance bottleneck condition triggered - high recursive call overhead." << endl;
        abort();
    }
}

int f(int n) {
    recursiveCallCount++;
    check_memoization_invariant(n, recursiveCallCount); // Check for memoization issue
    check_call_overhead_invariant(n, recursiveCallCount); // Check for call overhead

    if (n == 0) return a1;
    if (n == 1) return a2;
    return f(n - 1) + f(n - 2);
}

int main() {
    int n;
    cin >> a1 >> a2 >> n;

    check_recursive_depth_invariant(n); // Check before starting the recursive process

    cout << f(n) << endl;

    return 0;
}