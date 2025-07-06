#include <bits/stdc++.h>
using namespace std;

void check_ineffective_iteration(long long n, long long p) {
    if (p == 1 && n < 5000000) {
        cerr << "Warning: Performance bottleneck condition triggered due to ineffective iteration with p=1!" << endl;
        abort();
    }
}

void check_high_loop_iterations(long long n, long long p) {
    if ((p == 1 && n < 5000000) || (p > 0 && n < (1 << 20) && n % p != 0)) {
        cerr << "Warning: Performance bottleneck condition triggered due to high loop iterations with small n!" << endl;
        abort();
    }
}

void check_constraint_based_iteration(long long n, long long p) {
    if (p >= 0 && n / p > 5000000) {
        cerr << "Warning: Performance bottleneck condition triggered due to constraint-based iteration limit!" << endl;
        abort();
    }
}

long long N, P;
int main() {
    scanf("%lld %lld", &N, &P);
    
    // Insert checks to detect performance bottlenecks
    check_ineffective_iteration(N, P);
    check_high_loop_iterations(N, P);
    check_constraint_based_iteration(N, P);
    
    for (long long k = 1; k <= 5000000; k++) {
        long long R = N - k * P;
        long long L = __builtin_popcount(R);
        if (L <= k && k <= R) {
            printf("%lld\n", k);
            return 0;
        }
    }
    printf("-1\n");
    return 0;
}