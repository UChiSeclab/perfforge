#include <bits/stdc++.h>
using namespace std;

// Checker functions
void check_large_loops_invariant(int n, int *a) {
    int totalMonsters = 0;
    for (int i = 1; i <= n; ++i) {
        totalMonsters += a[i];
    }
    if (totalMonsters > 1000000) {
        cerr << "Warning: Performance bottleneck condition triggered - high monster count across stages!" << endl;
        abort();
    }
}

void check_nested_calculations_invariant(int n, long long r1, long long r2, long long r3, int *a) {
    for (int i = 1; i <= n; ++i) {
        if (r2 > r1 && r3 > r1 && a[i] > 100000) {
            cerr << "Warning: Performance bottleneck condition triggered - excessive nested calculations!" << endl;
            abort();
        }
    }
}

void check_transitions_invariant(int n, long long d, int *a) {
    for (int i = 1; i < n; ++i) {
        if (a[i] != a[i + 1] && d > 1000000) {
            cerr << "Warning: Performance bottleneck condition triggered - inefficient stage transitions!" << endl;
            abort();
        }
    }
}

long long n, d, r1, r2, r3, i, w[1000008], x[1000008], y[1000008], z[1000008];

int main() {
    scanf("%I64d%I64d%I64d%I64d%I64d", &n, &r1, &r2, &r3, &d);

    // Insert performance checks after reading input
    check_large_loops_invariant(n, w);
    check_nested_calculations_invariant(n, r1, r2, r3, w);
    check_transitions_invariant(n, d, w);

    for (r3 < r1 ? r1 = r3 : 0;
         i++ < n; scanf("%I64d", w + i), z[i] = w[i] * r1 + r3,
                 z[i] =
                     min(z[i],
                         (d << 1) + (w[i] = min(r2 + min(r2, r1),
                                                w[i] * r1 + min(r1 << 1, r3)))))
    ;
    for (x[i--] = -d, x[i] = y[i] = z[i]; --i;
         (y[i] = w[i] + d + d + y[i + 1]) <
                 (x[i] = min(z[i] + d + x[i + 1],
                             w[i] + w[i + 1] + (d << 2) + x[i + 2]))
             ? x[i] = y[i]
             : 0)
    ;
    printf("%I64d\n", x[1]), exit(0);
}