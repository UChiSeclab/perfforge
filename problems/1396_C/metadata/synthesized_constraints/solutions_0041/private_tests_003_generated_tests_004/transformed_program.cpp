#include <bits/stdc++.h>
using namespace std;

// Function to check if number of iterations and multiset usage could lead to performance issues
void check_multiset_invariant(long long n, const std::multiset<long long>& cur) {
    if (n > 100000 && cur.size() > n / 10) {
        cerr << "Warning: multiset_invariant triggered - excessive multiset operations with large n" << endl;
        abort();
    }
}

// Function to check if DP updates and branching could cause performance issues
void check_dp_invariant(long long d, long long r1, long long r2, long long r3) {
    if ((d > 1000000 || r1 > 1000000 || r2 > 1000000 || r3 > 1000000)) {
        cerr << "Warning: dp_invariant triggered - high reload/teleportation times affecting DP" << endl;
        abort();
    }
}

// Function to check if teleportation and reload times could cause performance issues
void check_time_invariant(long long d, long long r1, long long r2, long long r3, const vector<long long>& it) {
    long long max_monsters = *max_element(it.begin(), it.end());
    if ((d + r1 + r2 + r3) > 3000000 && max_monsters > 100000) {
        cerr << "Warning: time_invariant triggered - high teleportation/reload times with large monster counts" << endl;
        abort();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    long long n, r1, r2, r3, d;
    cin >> n >> r1 >> r2 >> r3 >> d;
    
    vector<long long> it(n);
    for (long long i = 0; i < n; i++) {
        cin >> it[i];
    }
    
    // Insert invariants checks here
    check_dp_invariant(d, r1, r2, r3);
    check_time_invariant(d, r1, r2, r3, it);

    long long ans = 0;
    vector<long long> pre2(n + 1, 0), dp(n, 0);
    multiset<long long> cur, cur2;
    
    for (long long i = 0; i < n; i++) {
        long long mi = it[i] * r1 + r3;
        mi = min(mi, min(r2 + r1, (it[i] + 2) * r1));
        pre2[i + 1] = pre2[i] + mi;
    }
    
    long long ba = 0;
    for (long long i = 0; i < n; i++) {
        dp[i] = pre2[i + 1] + 2 * d * i;
        if (i == 0) {
            dp[i] += 2 * d;
        }
        if (!cur.empty()) {
            long long xx = *cur.begin();
            dp[i] = min(dp[i], pre2[i + 1] + xx + 2 * i * d);
        }
        if (i > 0) {
            dp[i] = min(dp[i], dp[i - 1] + it[i] * r1 + r3);
        } else {
            dp[i] = min(dp[i], it[i] * r1 + r3);
        }
        if (i == n - 1) {
            long long ans = dp[n - 1];
            long long xx = *cur2.begin();
            ans = min(ans, pre2[i + 1] + xx + i * d + 2 * d);
            ans = min(ans, pre2[i] + xx + i * d + it[i] * r1 + r3);
            ans = min(ans, dp[n - 3] + pre2[i + 1] - pre2[i - 1] + 2 * d);
            cout << ans + (n - 1) * d << endl;
            return 0;
        }
        long long cot = 0;
        if (i > 0) {
            cot = dp[i - 1];
        }
        cur.insert(-pre2[i] - 2 * i * d + cot);
        cur2.insert(-pre2[i] - i * d + cot);

        // Check multiset invariant after insertions
        check_multiset_invariant(n, cur);
    }
    
    return 0;
}