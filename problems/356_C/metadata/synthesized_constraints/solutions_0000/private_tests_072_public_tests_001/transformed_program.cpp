#include <bits/stdc++.h>
using namespace std;

// Function to check high sum invariant
void check_high_sum_invariant(long long sum, long long N) {
    if (sum > N * 4) {
        cerr << "Warning: high_sum_invariant triggered - total student count is very high compared to compartments" << endl;
        abort();
    }
}

// Function to check iteration invariant
void check_iteration_invariant(long long x, long long sum) {
    if (x > sum / 3) {
        cerr << "Warning: iteration_invariant triggered - excessive loop iterations" << endl;
        abort();
    }
}

// Function to check adjustment invariant
void check_adjustment_invariant(long long adjustmentCount, long long threshold) {
    if (adjustmentCount > threshold) {
        cerr << "Warning: adjustment_invariant triggered - too many adjustments in compartments" << endl;
        abort();
    }
}

signed main() {
    long long N;
    cin >> N;
    vector<long long> cnt(5);
    long long sum = 0;
    for (long long i = 0; i < N; i++) {
        long long c;
        cin >> c;
        cnt[c]++;
        sum += c;
    }
    
    // Check for high sum invariant after input
    check_high_sum_invariant(sum, N);
    
    long long ans = LLONG_MAX;
    long long adjustmentCount = 0;
    const long long adjustmentThreshold = 100;

    for (long long x = 0; x * 3 <= sum; x++) {
        if ((sum - 3 * x) % 4) continue;
        
        // Check iteration invariant within the loop
        check_iteration_invariant(x, sum);

        long long y = (sum - 3 * x) / 4;
        vector<long long> a = cnt;
        long long val = 0;
        
        if (a[4] >= y) {
            long long t = a[4] - y;
            val += t;
            a[3] += t;
            adjustmentCount++;

            if (x - a[3] <= a[2])
                val += (a[2] - (x - a[3])) * 2 + a[1];
            else
                val += max(0ll, a[1] - (x - a[3] - a[2]));
        } else {
            if (a[4] + a[3] >= x + y) {
                val = a[1] + a[2] * 2 + (a[4] + a[3] - x - y) * 3;
            } else if (a[4] + a[3] + a[2] >= x + y)
                val = a[1] + (a[4] + a[3] + a[2] - x - y) * 2;
            else
                val = a[4] + a[3] + a[2] + a[1] - x - y;
        }
        
        // Check adjustment invariant after compartment adjustments
        check_adjustment_invariant(adjustmentCount, adjustmentThreshold);

        chmin(ans, val);
    }
    
    if (ans == LLONG_MAX)
        cout << -1 << endl;
    else
        cout << ans << endl;

    return 0;
}