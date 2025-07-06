#include <iostream>
#include <map>
using namespace std;

int a, b, c;

// Check for high recursion depth
void check_recursion_depth_invariant(int depth) {
    if (depth > 15) { // Assuming a threshold value based on analysis
        cerr << "Warning: Performance bottleneck condition triggered - high recursion depth!" << endl;
        abort();
    }
}

// Check for memoization
void check_memoization_invariant(bool isMemoized) {
    if (!isMemoized) {
        cerr << "Warning: Performance bottleneck condition triggered - lack of memoization!" << endl;
        abort();
    }
}

map<int, int> memo; // Memoization cache

int f(int c) {
    if (c == 0) return a;
    if (c == 1) return b;

    // Check memoization
    check_memoization_invariant(memo.find(c) != memo.end());

    // Check recursion depth
    check_recursion_depth_invariant(c);

    if (memo.find(c) != memo.end()) {
        return memo[c];
    }
    int result = f(c - 1) + f(c - 2);
    memo[c] = result; // Store the result for memoization
    return result;
}

int main() {
    cin >> a >> b >> c;
    int k = f(c);
    cout << k;

    getchar();
    getchar();
}