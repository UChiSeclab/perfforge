#include <bits/stdc++.h>
using namespace std;

// Checker function for high recursion depth and branching factor
void check_recursion_depth(int m, int n) {
    int factorCount = 0;
    while (m % 2 == 0) {
        m /= 2;
        factorCount++;
    }
    while (m % 3 == 0) {
        m /= 3;
        factorCount++;
    }
    if (factorCount > 30) { // arbitrary threshold based on potential slowdown
        cerr << "Warning: Performance bottleneck condition triggered - high recursion depth or branching factor!" << endl;
        abort();
    }
}

// Checker function for large search space from factorization
void check_large_search_space(int n, int m) {
    int originalM = m;
    while (m % 2 == 0) {
        m /= 2;
    }
    while (m % 3 == 0) {
        m /= 3;
    }
    if (m != 1 && originalM / n > 1000000) { // arbitrary threshold to detect excessive search space
        cerr << "Warning: Performance bottleneck condition triggered - large search space from factorization!" << endl;
        abort();
    }
}

int f(int m, int n, int cnt = 0) {
    if (m == n) return cnt;
    int a = -1, b = -1;
    if (m == 1) return -1;
    if (m % 2 == 0) {
        a = f(m / 2, n, cnt + 1);
    }
    if (m % 3 == 0) {
        b = f(m / 3, n, cnt + 1);
    }
    return max(a, b);
}

int main() {
    int n, m;
    cin >> n >> m;

    // Insert checks before calling the main recursive function
    check_recursion_depth(m, n);  // Check for high recursion depth and branching
    check_large_search_space(n, m);  // Check for large search space from factorization

    cout << f(m, n, 0) << endl;
    return 0;
}