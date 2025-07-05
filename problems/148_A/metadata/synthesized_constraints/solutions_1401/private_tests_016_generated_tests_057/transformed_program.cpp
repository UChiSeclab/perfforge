#include <bits/stdc++.h>
using namespace std;

// Checker functions
void check_divisibility_invariant(int k, int l, int m, int n) {
    if (k != 1 && l != 1 && m != 1 && n != 1) {
        cerr << "Warning: Performance bottleneck condition triggered - no trivial divisibility." << endl;
        abort();
    }
}

void check_large_input_invariant(int d) {
    if (d > 90000) {  // Threshold demonstrating potential slowdown
        cerr << "Warning: Performance bottleneck condition triggered - large number of dragons." << endl;
        abort();
    }
}

void check_array_invariant(int d) {
    if (d > 90000) {  // Threshold focusing on inefficient usage of `arr`
        cerr << "Warning: Performance bottleneck condition triggered - inefficient array usage." << endl;
        abort();
    }
}

int main() {
    int k, l, m, n, d;
    // Read inputs
    scanf("%d %d %d %d %d", &k, &l, &m, &n, &d);

    // Insert checkers after input reading to detect bottlenecks early
    check_divisibility_invariant(k, l, m, n);
    check_large_input_invariant(d);
    check_array_invariant(d);

    int arr[d];

    if (k == 1 || l == 1 || m == 1 || n == 1) {
        printf("%d\n", d);
    } else {
        for (int i = 1; i <= d; i++) {
            if (i % k == 0)
                arr[i - 1] = 1;
            else if (i % l == 0)
                arr[i - 1] = 1;
            else if (i % m == 0)
                arr[i - 1] = 1;
            else if (i % n == 0)
                arr[i - 1] = 1;
            else
                arr[i - 1] = 0;
        }
        int count = 0;
        for (int i = 0; i < d; i++) {
            if (arr[i] == 1) count++;
        }
        printf("%d\n", count);
    }
    return 0;
}