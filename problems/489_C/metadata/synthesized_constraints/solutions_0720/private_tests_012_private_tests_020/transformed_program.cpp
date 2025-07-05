#include <bits/stdc++.h>
using namespace std;

// Checkers for performance invariants
void check_recursion_invariant(int recursionDepth, int maxDepth) {
    if (recursionDepth > maxDepth) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive recursion depth!" << endl;
        abort();
    }
}

void check_input_size_invariant(int m, int s) {
    if (m > 90 && s > 810) { // Assuming these as thresholds near the upper limit
        cerr << "Warning: Performance bottleneck condition triggered - input size at limit!" << endl;
        abort();
    }
}

// Update the plus1 and minus1 functions to track recursion depth
void plus1(int a[], int m, int depth) {
    check_recursion_invariant(depth, 100); // Check recursion depth
    if (a[0] == 9 && m == 0) {
        a[0] = -1;
        exit;
    }
    if (a[m] != 9)
        a[m]++;
    else
        plus1(a, m - 1, depth + 1);
}

void minus1(int b[], int m, int depth) {
    check_recursion_invariant(depth, 100); // Check recursion depth
    if (b[0] == 0 && m == 0) {
        b[0] = -1;
        exit;
    }
    if (b[m] != 0)
        b[m]--;
    else
        minus1(b, m - 1, depth + 1);
}

int main() {
    int i, j, m, sum, ans = 0;
    int a[101], b[101];
    std::cin >> m >> sum;

    // Input size invariant check
    check_input_size_invariant(m, sum);

    a[0] = 1;
    if (m != 1 && sum == 0) {
        std::cout << "-1 -1";
        return 0;
    }
    if (sum > 9 * m) {
        std::cout << "-1 -1";
        return 0;
    }
    if (m == 1 && sum == 0) {
        std::cout << "0 0";
        return 0;
    }
    for (i = 1; i < m; i++) a[i] = 0;
    for (i = 0; i < m; i++) b[i] = 9;
    int ss = 1;
    while (ss != sum) {
        plus1(a, m - 1, 1); // Start recursion depth at 1
        ss++;
        if (a[0] == -1) {
            std::cout << "-1 -1";
            return 0;
        }
    }
    ss = m * 9;
    while (ss != sum) {
        minus1(b, m - 1, 1); // Start recursion depth at 1
        ss--;
        ss = 0;
        for (i = 0; i < m; i++) ss += b[i];
    }
    for (i = 0; i < m; i++) std::cout << a[i];
    std::cout << ' ';
    for (i = 0; i < m; i++) std::cout << b[i];
    std::cin >> i;
    return 0;
}