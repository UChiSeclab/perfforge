#include <bits/stdc++.h>
using namespace std;

// Checker for iterative marking of dragons invariant
void check_iterative_marking_invariant(int k, int l, int m, int n, int d) {
    if ((k != 1 && l != 1 && m != 1 && n != 1) && d > 50000) {
        cerr << "Warning: Iterative marking invariant triggered - high number of dragons checked!" << endl;
        abort();
    }
}

// Checker for double loop execution invariant
void check_double_loop_execution_invariant(int k, int l, int m, int n, int d) {
    if ((k != 1 && l != 1 && m != 1 && n != 1) && d > 50000) {
        cerr << "Warning: Double loop execution invariant triggered - potential performance bottleneck!" << endl;
        abort();
    }
}

int main() {
    int k, l, m, n, i, j, d, fucked = 0;
    cin >> k >> l >> m >> n >> d;
    int p[100010];
    
    // Run performance checkers
    check_iterative_marking_invariant(k, l, m, n, d);
    check_double_loop_execution_invariant(k, l, m, n, d);

    if (k == 1 || l == 1 || m == 1 || n == 1) {
        cout << d;
    } else {
        for (i = 1; i <= d; i++) {
            if (i % k == 0 || i % l == 0 || i % m == 0 || i % n == 0) {
                p[i] = -1;
            } else {
                p[i] = 0;
            }
        }
        for (j = 1; j <= d; j++) {
            if (p[j] == -1) {
                fucked++;
            }
        }
        cout << fucked << endl;
    }
    return 0;
}