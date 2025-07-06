#include <bits/stdc++.h>
using namespace std;

int n, m;
const int maxn = 100006;
long long t, T, x, cst;

// Phase 3: Checker functions

void check_temp_difference_invariant(int m, long long t, long long T) {
    if (T - t < 10) { // Arbitrarily chosen small range threshold
        cerr << "Warning: Performance bottleneck condition triggered due to small temperature difference!" << endl;
        abort();
    }
}

void check_high_temp_invariant(long long t, long long m, long long T) {
    if (t + m > 2*T) { // Threshold chosen as double the normal threshold
        cerr << "Warning: Performance bottleneck condition triggered due to frequent high temperature cost path!" << endl;
        abort();
    }
}

void check_modulus_division_invariant(int m, long long t, long long T) {
    if ((T - t) > 0 && m % (T - t) > (T - t) / 2) { // Threshold is half of the difference
        cerr << "Warning: Performance bottleneck condition triggered due to inefficient modulus division!" << endl;
        abort();
    }
}

int main() {
    scanf("%d%d", &n, &m);
    long long ans = 0;
    for (int i = 0; i != n; i++) {
        scanf("%I64d%I64d%I64d%I64d", &t, &T, &x, &cst);

        // Phase 4: Insert checks after reading input for each region

        // Check for small temperature difference leading to high computation
        check_temp_difference_invariant(m, t, T);

        // Check for high internal bus temperature
        check_high_temp_invariant(t, m, T);

        // Check for inefficient modulus and division operations
        check_modulus_division_invariant(m, t, T);

        long long ta1 = 0, ta2 = 0;
        ta1 += cst;
        if (t + m > T) ta1 += x * m;
        if (T - t > 0)
            if (m % (T - t))
                ta2 = cst * (m / (T - t) + 1);
            else
                ta2 = cst * (m / (T - t));
        else
            ta2 = ta1 + 1;
        ans += min(ta1, ta2);
    }
    printf("%I64d\n", ans);
}