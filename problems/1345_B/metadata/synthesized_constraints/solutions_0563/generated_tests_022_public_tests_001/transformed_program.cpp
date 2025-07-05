#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
long long sum[N];

void check_large_iterations_invariant(int l, long long n) {
    if (l > 100000 && n > 0) { 
        cerr << "Warning: Large iterations invariant triggered - high l with remaining cards" << endl;
        abort();
    }
}

void check_low_reduction_invariant(int l, long long n, long long sum_l) {
    if (l > 100000 && n % sum_l > 0 && n >= sum_l) {
        cerr << "Warning: Low reduction invariant triggered - n is not reducing efficiently" << endl;
        abort();
    }
}

void check_high_initial_n_invariant(long long n, long long sum_l) {
    if (n > 1000000 && n % sum_l > n / 10) {
        cerr << "Warning: High initial n invariant triggered - low constructibility" << endl;
        abort();
    }
}

int main() {
    sum[1] = 2;
    for (int i = 2; i < N; i++) sum[i] = sum[i - 1] + 3 * i - 1;
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        int ans = 0;
        int l = N - 10;

        // Initial invariant check after reading input
        check_high_initial_n_invariant(n, sum[l]);

        while (l) {
            if (!n) break;

            // Check for large iterations
            check_large_iterations_invariant(l, n);

            if (n >= sum[l]) {
                ans += n / sum[l];
                n %= sum[l];
            }

            // Check for low reduction efficiency
            check_low_reduction_invariant(l, n, sum[l]);

            l--;
        }
        cout << ans << endl;
    }
}