#include <bits/stdc++.h>
using namespace std;
vector<int> a, b, c;
int n, k, x;

// Checker functions for performance bottlenecks
void check_high_iteration_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - high number of operations (k)!" << endl;
        abort();
    }
}

void check_data_redistribution_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - repeated strength redistribution!" << endl;
        abort();
    }
}

void check_bitwise_operations_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive bitwise operations!" << endl;
        abort();
    }
}

void check_switching_arrays_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - frequent array switching!" << endl;
        abort();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    scanf("%d %d %d", &n, &k, &x);
    int t;

    // Initialize vectors with zeros
    for (int i = 0; i < 1050; i++) {
        a.push_back(0);
        b.push_back(0);
        c.push_back(0);
    }

    // Read ranger strengths
    for (int i = 0; i < n; i++) {
        scanf("%d", &t);
        a[t]++;
    }

    // Check for high iteration count before the main loop
    check_high_iteration_invariant(k > 50000);

    int cnt[1050];
    for (int i = 0; i < k; i++) {
        if (i % 2 == 0) {
            b = c;
            cnt[0] = a[0];
            for (int i = 1; i < 1050; i++) cnt[i] = cnt[i - 1] + a[i];
            for (int i = 0; i < 1050; i++) {
                int prev = 0;
                if (i > 0) prev = cnt[i - 1];
                if (prev % 2 == 0) {
                    b[i ^ x] += ceil((double)a[i] / 2.00);
                    b[i] += a[i] / 2;
                } else {
                    b[i] += ceil((double)a[i] / 2.00);
                    b[i ^ x] += a[i] / 2;
                }
            }
        } else {
            cnt[0] = b[0];
            for (int i = 1; i < 1050; i++) cnt[i] = cnt[i - 1] + b[i];
            a = c;
            for (int i = 0; i < 1050; i++) {
                int prev = 0;
                if (i > 0) prev = cnt[i - 1];
                if (prev % 2 == 0) {
                    a[i ^ x] += ceil((double)b[i] / 2.00);
                    a[i] += b[i] / 2;
                } else {
                    a[i] += ceil((double)b[i] / 2.00);
                    a[i ^ x] += b[i] / 2;
                }
            }
        }
    }

    // Check invariants after the main loop
    check_data_redistribution_invariant(k > 50000 && n < 1000);
    check_bitwise_operations_invariant(k > 50000 && n < 1000);
    check_switching_arrays_invariant(k > 50000 && n < 1000);

    int mini = 10000;
    int maxi = -1;
    if (k % 2 == 0) {
        for (int i = 0; i < 1050; i++) {
            if (a[i] > 0) {
                mini = min(i, mini);
                maxi = max(i, maxi);
            }
        }
    } else {
        for (int i = 0; i < 1050; i++) {
            if (b[i] > 0) {
                mini = min(i, mini);
                maxi = max(i, maxi);
            }
        }
    }
    cout << maxi << " " << mini;
    return 0;
}