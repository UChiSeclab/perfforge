#include <bits/stdc++.h>
using namespace std;

int sum(int n) {
    int ans = 0;
    for (int ii = 1; ii <= n; ii++) {
        ans = ans + ii;
    }
    return ans;
}

// Checker functions
void check_height_invariant(int x) {
    if (x > 100000) { // arbitrary threshold for large pyramid heights
        cerr << "Warning: Performance bottleneck condition triggered - large pyramid height x!" << endl;
        abort();
    }
}

void check_sum_invariant(int callCount) {
    if (callCount > 100000) { // arbitrary threshold for excessive sum calls
        cerr << "Warning: Performance bottleneck condition triggered - excessive calls to sum function!" << endl;
        abort();
    }
}

void check_decrement_invariant(int n, int decrement) {
    if (decrement < n / 10) { // small decrement relative to initial n
        cerr << "Warning: Performance bottleneck condition triggered - small decrement in n!" << endl;
        abort();
    }
}

int main() {
    int test, n, a, x, b, countp = 0;
    cin >> test;
    for (int ss = 0; ss < test; ss++) {
        countp = 0;
        cin >> n;
        int sumCallCount = 0; // Initialize a counter for sum function calls

        while (n >= 2) {
            x = 1;
            while (true) {
                a = sum(x);
                sumCallCount++; // Increment counter for each call to sum
                b = 3 * a - x;
                if (b > n) {
                    x--;
                    break;
                }
                x++;
                check_height_invariant(x); // Check for large pyramid height
            }

            b = 3 * sum(x) - x;
            int decrement = n - b;
            check_decrement_invariant(n, decrement); // Check small decrement
            n = n - b;
            countp++;
        }
        check_sum_invariant(sumCallCount); // Check after processing each test case
        cout << countp << endl;
    }
    return 0;
}