#include <bits/stdc++.h>
using namespace std;

// Checker function for recursion depth
void check_recursion_depth(int total_calls, int threshold) {
    if (total_calls > threshold) {
        cerr << "Warning: Recursion depth or number of calls too high!" << endl;
        abort();
    }
}

// Checker function for large loop iterations
void check_large_loop_iterations(int ball_count, int threshold) {
    if (ball_count > threshold) {
        cerr << "Warning: Large number of loop iterations in recursion!" << endl;
        abort();
    }
}

// Checker function for inefficient memoization
void check_memoization_efficiency(long long failed_memoization, long long total_calls, double inefficiency_ratio) {
    if ((double)failed_memoization / total_calls > inefficiency_ratio) {
        cerr << "Warning: Memoization inefficiency detected!" << endl;
        abort();
    }
}

long long mod_minus(long long a, long long b) {
    return (a - b + 1000000007) % 1000000007;
}

int ara[1005];
long long dp[1005], fake_place[1005][1005];
long long func(int seat, int ball, int &call_count) {
    call_count++; // Count each recursive call
    if (!ball) return 1;
    if (seat == 1) return 1;
    if (fake_place[seat][ball] != -1) return fake_place[seat][ball];
    int i;
    long long ans = 0;

    // Check large loop iterations
    check_large_loop_iterations(ball, 500); // Example threshold

    for (i = 0; i <= ball; i++) {
        ans += func(seat - 1, i, call_count);
        ans %= 1000000007;
    }
    return fake_place[seat][ball] = ans;
}

int main() {
    int k, i, j;
    for (i = 0; i < 1005; i++)
        for (j = 0; j < 1005; j++) fake_place[i][j] = -1;

    scanf("%d", &k);
    for (i = 0; i < k; i++) scanf("%d", &ara[i]);

    dp[0] = 1;
    int total = ara[0];
    int call_count = 0; // Initialize call counter

    for (i = 1; i < k; i++) {
        call_count = 0; // Reset call count for each i

        dp[i] =
            dp[i - 1] * (mod_minus(func(total + 1, ara[i], call_count), func(total, ara[i], call_count)));
        dp[i] %= 1000000007;
        total += ara[i];

        // Check recursion depth and memoization efficiency after processing each color
        check_recursion_depth(call_count, 100000); // Example threshold
        check_memoization_efficiency(call_count - fake_place[total + 1][ara[i]], call_count, 0.1); // Example inefficiency ratio
    }

    printf("%I64d\n", dp[k - 1]);
    return 0;
}