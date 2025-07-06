#include <bits/stdc++.h>
using namespace std;

long long n, k, d;
long long dp[110][110][3];

void check_recursion_branches(bool condition) {
    if (condition) {
        cerr << "Warning: High recursion depth with excessive branching!" << endl;
        abort();
    }
}

void check_memoization_inefficiency(bool condition) {
    if (condition) {
        cerr << "Warning: Inefficient use of memoization with large branching factor!" << endl;
        abort();
    }
}

void check_path_weight_conditions(bool condition) {
    if (condition) {
        cerr << "Warning: High number of combinations with large total path weights!" << endl;
        abort();
    }
}

long long myfunc(long long i, long long sum, long long cnt) {
    if (i >= d) cnt = 1;
    if (sum <= 0) {
        if (sum == 0) {
            if (cnt == 1) return 1;
        }
        return 0;
    }
    if (dp[i][sum][cnt] != -1) return dp[i][sum][cnt];
    long long ret1 = 0;
    for (long long j = 1; j <= k; j++) {
        ret1 = (ret1 + myfunc(j, sum - j, cnt) % 1000000007) % 1000000007;
    }
    dp[i][sum][cnt] = ret1 % 1000000007;
    return dp[i][sum][cnt];
}

int main() {
    cin >> n >> k >> d;
    memset(dp, -1, sizeof dp);

    // Check for deep recursion and high branching
    check_recursion_branches(n > 90 && k > 50);

    // Check for inefficient memoization usage
    check_memoization_inefficiency(k > 50);

    // Check for high weight path conditions
    check_path_weight_conditions(n > 90 && d < 5);

    long long ans = 0;
    for (long long i = 1; i <= k; i++) {
        ans = (ans + myfunc(i, n - i, 0) % 1000000007) % 1000000007;
    }
    cout << ans << endl;
    return 0;
}