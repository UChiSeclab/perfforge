#include <bits/stdc++.h>
using namespace std;

// Function to check performance invariants
void check_performance_invariants(int k, int l, int m, int n, int d) {
    // Check if none of the divisors are 1 and d is large
    if ((k > 1 && l > 1 && m > 1 && n > 1) && d > 10000) { // Threshold for d is arbitrarily set high
        cerr << "Warning: Performance bottleneck condition triggered - extensive divisor checks due to none being 1." << endl;
        abort();
    }
}

int main() {
    int k, l, m, n, d;
    int cont = 0;
    cin >> k >> l >> m >> n >> d;

    // Insert the performance check here
    check_performance_invariants(k, l, m, n, d);

    cont = d;
    if (k == 1 || l == 1 || m == 1 || n == 1) {
        cout << d << endl;
    } else {
        for (int i = 1; i <= d; i++) {
            if ((i % k != 0) && (i % l != 0) && (i % m != 0) && (i % n != 0)) cont--;
        }
        cout << cont << endl;
    }
    return 0;
}