#include <bits/stdc++.h>
using namespace std;

const long long LOGN = 20;
const long long N = (1 << LOGN) + 99;
long long dp[LOGN + 2][N];
long long sum[100];
long long n;
long long bribes[N];

// Performance bottleneck checkers
void check_recursion_invariant(long long cnt, long long idx, long long recursionDepth, long long branchingFactor) {
    if (cnt > recursionDepth && idx > branchingFactor) {
        cerr << "Warning: Performance bottleneck condition triggered due to deep recursion depth and high branching factor!" << endl;
        abort();
    }
}

void check_memoization_invariant(long long dpValue) {
    if (dpValue == -1) {
        cerr << "Warning: Performance bottleneck condition triggered due to insufficient memoization!" << endl;
        abort();
    }
}

void check_input_size_invariant(long long n) {
    if (n >= (1 << 17)) {  // n close to its upper limit
        cerr << "Warning: Performance bottleneck condition triggered due to large input size!" << endl;
        abort();
    }
}

long long f(long long cnt, long long idx) {
    check_recursion_invariant(cnt, idx, 30, 100);  // Check recursion depth and branching factor

    if (bribes[idx] == -1) return 0;
    if (dp[cnt][idx] != -1) return dp[cnt][idx];
    
    check_memoization_invariant(dp[cnt][idx]);  // Check memoization effectiveness

    long long remaining = sum[cnt] - idx;
    long long ans = numeric_limits<long long>::max();
    if (cnt < LOGN) ans = min(ans, f(cnt + 1, idx + 1) + bribes[idx]);
    if (remaining > 0) {
        ans = min(ans, f(cnt, idx + 1));
    }
    return dp[cnt][idx] = ans;
}

int main() {
    cin >> n;
    
    check_input_size_invariant(n);  // Check input size

    for (int i = 0; i < n; i++) {
        cin >> bribes[i];
    }
    memset(dp, -1, sizeof dp);
    reverse(bribes, bribes + n);
    sum[0] = 0;
    long long x = n / 2;
    for (long long i = 1; i < 100; i++) {
        sum[i] = sum[i - 1] + x;
        x /= 2;
    }
    cout << f(0, 0) << endl;
    return 0;
}