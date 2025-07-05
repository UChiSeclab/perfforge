#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

const int maxN = 1e5;
long long n, row, col, c;

long long sum(long long t) {
    long long max_l = col - 1, max_r = n - col;
    long long ans = 0;
    ans += 1 + min(t, max_l) + min(t, max_r);
    long long aux_t = t;
    for (int i = row - 1; i >= 1; i--) {
        aux_t--;
        if (aux_t < 0) break;
        ans += 1 + min(aux_t, max_l) + min(aux_t, max_r);
    }
    for (int i = row + 1; i <= n; i++) {
        t--;
        if (t < 0) break;
        ans += 1 + min(t, max_l) + min(t, max_r);
    }
    return ans;
}

void check_large_n_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered due to large n!" << endl;
        abort();
    }
}

void check_loop_iteration_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered due to high loop iterations!" << endl;
        abort();
    }
}

void check_binary_search_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered during binary search!" << endl;
        abort();
    }
}

int main() {
    scanf("%lld %lld", &n, &row);
    scanf("%lld %lld", &col, &c);

    // Check for large n causing inefficiencies in computation
    check_large_n_invariant(n > 1e8);

    long long lo = 0, hi = 1e5;

    while (lo < hi) {
        long long mi = lo + (hi - lo) / 2;

        // Check inefficiencies in loop due to high iteration counts
        check_loop_iteration_invariant(mi > 1e4);

        if (sum(mi) >= c)
            hi = mi;
        else
            lo = mi + 1;
    }

    // Check inefficiencies in binary search due to large n or small c
    check_binary_search_invariant((n * n) > 1e9 && c < (n * n * 0.1));

    printf("%lld\n", hi);
    return 0;
}