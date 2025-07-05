#include <bits/stdc++.h>
using namespace std;

void check_large_iteration_invariant(long long n) {
    if (n < 1000005) {
        cerr << "Warning: Large iteration invariant triggered - excessive range in loop" << endl;
        abort();
    }
}

void check_default_case_invariant(long long defaultCaseCount, long long totalIterations) {
    if (defaultCaseCount > 0.9 * totalIterations) {
        cerr << "Warning: Default case invariant triggered - frequent default logic" << endl;
        abort();
    }
}

void check_complex_update_invariant(long long complexUpdates, long long n) {
    if (complexUpdates > 0.2 * n) {
        cerr << "Warning: Complex update invariant triggered - inefficient dp updates" << endl;
        abort();
    }
}

void check_redundant_loop_invariant(long long n) {
    if (n > 1000000) {
        cerr << "Warning: Redundant loop invariant triggered - large redundant loop range" << endl;
        abort();
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long t;
    t = 1;
    while (t--) {
        long long n;
        cin >> n;
        long long a, b;
        set<long long> s;
        map<long long, long long> m;
        for (long long i = 0; i < n; i++) {
            cin >> a >> b;
            s.insert(a);
            m[a] = b;
        }

        long long dp[1000005];
        memset(dp, 0, sizeof(dp));
        if (m[0] > 0) dp[0] = 1;

        long long defaultCaseCount = 0;
        long long complexUpdates = 0;

        check_large_iteration_invariant(n); // Check before large fixed iteration

        for (long long i = 1; i <= 1000004; i++) {
            if (s.find(i) == s.end()) {
                dp[i] = dp[i - 1];
                defaultCaseCount++;
            } else {
                if (m[i] >= i)
                    dp[i] = 1;
                else {
                    dp[i] = dp[i - m[i] - 1] + 1;
                    complexUpdates++;
                }
            }
        }

        check_default_case_invariant(defaultCaseCount, 1000005); // Check after loop
        check_complex_update_invariant(complexUpdates, n); // Check after loop

        long long ans = dp[0];

        check_redundant_loop_invariant(n); // Check before second large iteration

        for (long long i = 1; i <= 1000004; i++) {
            if (dp[i] > ans) ans = dp[i];
        }

        cout << n - ans << "\n";
    }
}