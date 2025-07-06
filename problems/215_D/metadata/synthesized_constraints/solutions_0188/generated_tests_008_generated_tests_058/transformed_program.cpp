#include <bits/stdc++.h>
using namespace std;
const int maxN = 1111111;
int n;
long long m, t[maxN], T[maxN], x[maxN], cost[maxN], p[maxN];
long long Min(long long a, long long b) { return a < b ? a : b; }

// Invariant checkers
void check_temperature_difference(long long p) {
    if (p <= 0) {
        cerr << "Warning: Performance bottleneck condition triggered - zero or negative temperature difference resulting in high compensation." << endl;
        abort();
    }
}

void check_high_compensation(long long p, long long m) {
    if (p > 0 && p < m) {
        cerr << "Warning: Performance bottleneck condition triggered - small temperature difference relative to number of students." << endl;
        abort();
    }
}

void check_complex_cost(long long p, long long m) {
    if (p > 0 && p < m && m % p != 0) {
        cerr << "Warning: Performance bottleneck condition triggered - complex cost calculation path." << endl;
        abort();
    }
}

int main() {
    cin >> n >> m;
    long long sol = 0;
    for (int i = 0; i < n; i++) {
        scanf("%I64d%I64d%I64d%I64d", t + i, T + i, x + i, cost + i);
        p[i] = T[i] - t[i];
        
        // Insert checkers
        check_temperature_difference(p[i]);
        check_high_compensation(p[i], m);
        check_complex_cost(p[i], m);

        if (p[i] <= 0) {
            sol += cost[i] + x[i] * m;
        } else if (p[i] >= m) {
            sol += cost[i];
        } else if (m % p[i] == 0) {
            sol += Min(cost[i] * m / p[i], cost[i] + m * x[i]);
        } else {
            long long k = m / p[i];
            long long ost = m % p[i];
            long long d1 = (k + 1) * cost[i];
            long long d2 = k * cost[i] + (p[i] + ost) * x[i];
            long long tmp = Min(d1, d2);
            sol += Min(tmp, cost[i] + x[i] * m);
        }
    }
    printf("%I64d\n", sol);
    return 0;
}