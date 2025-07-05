#include <bits/stdc++.h>
using namespace std;

int a1, a2;

inline int read_int() {
    int s = 0, w = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') {
            w = -1;
        }
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        s = s * 10 + ch - '0';
        ch = getchar();
    }
    return s * w;
}

// Checker function for the recursive depth invariant
void check_recursive_depth_invariant(int n) {
    if (n > 15) {  // Threshold chosen to warn about potentially slow scenarios
        cerr << "Warning: Performance bottleneck condition triggered - excessive recursive depth" << endl;
        abort();
    }
}

int dp(int n) {
    // Check the invariant before proceeding with recursion
    check_recursive_depth_invariant(n);

    if (n == 0) {
        return a1;
    }
    if (n == 1) {
        return a2;
    }
    return dp(n - 1) + dp(n - 2);
}

int main() {
    a1 = read_int();
    a2 = read_int();
    int n = read_int();
    cout << dp(n);
    return 0;
}