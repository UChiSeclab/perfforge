#include <bits/stdc++.h>
using namespace std;

const long long MAX = 1e5 + 5;
const long long modu = 1e9 + 7;
long long n, a, b, c;
long long dp[4005][4005];

void check_recursion_invariant(long long n, long long a, long long b, long long c) {
    if (n > 3000 && (n % a == 0 || n % b == 0 || n % c == 0)) {
        cerr << "Warning: Recursion invariant triggered - large n with multiple partition options" << endl;
        abort();
    }
}

void check_memoization_invariant(long long n, long long a, long long b, long long c) {
    if ((n > 3000) && (a < 10 || b < 10 || c < 10)) {
        cerr << "Warning: Memoization invariant triggered - inefficient memoization with small partition lengths" << endl;
        abort();
    }
}

void check_branching_invariant(long long a, long long b, long long c) {
    if ((a < 5 && b < 5 && c < 5)) {
        cerr << "Warning: Branching invariant triggered - high branching factor due to small partition lengths" << endl;
        abort();
    }
}

long long fun(long long n, long long count) {
    if (n < 0) return 0;
    if (dp[n][count] != -1) return dp[n][count];
    if (n == 0) return count;
    long long ans1 = fun(n - a, count + 1);
    long long ans2 = fun(n - b, count + 1);
    long long ans3 = fun(n - c, count + 1);
    return dp[n][count] = max(ans1, max(ans2, ans3));
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> a >> b >> c;

    // Insert checkers after reading inputs
    check_recursion_invariant(n, a, b, c);
    check_memoization_invariant(n, a, b, c);
    check_branching_invariant(a, b, c);

    memset(dp, -1, sizeof(dp));
    cout << fun(n, 0);
}