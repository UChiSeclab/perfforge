#include <bits/stdc++.h>
using namespace std;

inline long long min2(long long a, long long b) {
    return (a) < (b) ? (a) : (b);
}

inline long long max2(long long a, long long b) {
    return (a) > (b) ? (a) : (b);
}

inline long long max3(long long a, long long b, long long c) {
    return (a) > (b) ? ((a) > (c) ? (a) : (c)) : ((b) > (c) ? (b) : (c));
}

inline long long min3(long long a, long long b, long long c) {
    return (a) < (b) ? ((a) < (c) ? (a) : (c)) : ((b) < (c) ? (b) : (c));
}

using namespace std::chrono;

long long int n, m, k;
long long int dp[2001][2001];

void check_large_recursive_state_space(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck - large recursive state space detected!" << endl;
        abort();
    }
}

void check_high_recursive_call_overhead(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck - high recursive call overhead detected!" << endl;
        abort();
    }
}

void check_large_dp_table(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck - large dynamic programming table detected!" << endl;
        abort();
    }
}

long long int fun(long long int i, long long int c) {
    if (i == n + 1) {
        if (c == k)
            return 1;
        else
            return 0;
    }

    if (dp[i][c] != -1) return dp[i][c];

    if (i == 1)
        dp[i][c] = (m * fun(i + 1, c)) % 998244353;
    else
        dp[i][c] = (((m - 1) * fun(i + 1, c + 1)) % 998244353 +
                    (1 * fun(i + 1, c)) % 998244353) %
                   998244353;

    return dp[i][c];
}

void process() {
    cin >> n >> m >> k;
    memset(dp, -1, sizeof(dp));

    // Check #1: Large recursive state space
    check_large_recursive_state_space(n > 1500);

    // Check #2: High recursive call overhead
    check_high_recursive_call_overhead(n > 1500 && k > 0.75 * n);

    // Check #3: Large dynamic programming table
    check_large_dp_table(n * k > 2000000);

    cout << fun(1, 0) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    process();
}