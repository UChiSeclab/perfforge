#include <bits/stdc++.h>
using namespace std;

long long cntzero(long long num) {
    long long ans = 0;
    while (num != 0) {
        if (num % 2) ans++;
        num /= 2;
    }
    return ans;
}

// Invariant 1: Detect inefficient loop termination
void check_inefficient_loop_termination(long long n, long long p, long long i, long long newn) {
    if (newn < i && n <= abs(p)) {
        cerr << "Warning: Performance bottleneck condition triggered - inefficient loop termination!" << endl;
        abort();
    }
}

// Invariant 2: Detect small n with unfavorable positive p
void check_small_n_unfavorable_p(long long n, long long p) {
    if (n <= abs(p) && p > 0) {
        cerr << "Warning: Performance bottleneck condition triggered - small n with unfavorable p!" << endl;
        abort();
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    long long n, p;
    cin >> n >> p;

    // Check for small n with unfavorable p before the loop starts
    check_small_n_unfavorable_p(n, p);

    for (long long i = 1; clock() < 1.95 * CLOCKS_PER_SEC; i++) {
        long long newn = n - p * i;

        // Check for inefficient loop termination in each iteration
        check_inefficient_loop_termination(n, p, i, newn);

        if (newn < i) continue;
        if (cntzero(newn) <= i) {
            cout << i;
            return 0;
        }
    }
    cout << -1;
    return 0;
}