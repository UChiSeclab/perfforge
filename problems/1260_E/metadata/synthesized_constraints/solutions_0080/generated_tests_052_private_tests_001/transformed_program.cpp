#include <bits/stdc++.h>
using namespace std;

// Checker functions
void check_recursion_invariant(int cnt, int idx, int maxDepth) {
    if (cnt > maxDepth) {
        cerr << "Warning: Performance bottleneck condition triggered - recursion depth too high!" << endl;
        abort();
    }
}

void check_branching_invariant(int n, int threshold) {
    if (n > threshold) {
        cerr << "Warning: Performance bottleneck condition triggered - high branching factor!" << endl;
        abort();
    }
}

void check_recursive_calls_invariant(int callCount, int callThreshold) {
    if (callCount > callThreshold) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive recursive calls!" << endl;
        abort();
    }
}

long long powmod(long long a, long long b) {
    long long res = 1;
    if (a >= 1000000007) a %= 1000000007;
    for (; b; b >>= 1) {
        if (b & 1) res = res * a;
        if (res >= 1000000007) res %= 1000000007;
        a = a * a;
        if (a >= 1000000007) a %= 1000000007;
    }
    return res;
}

long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }

const long long LOGN = 20;
const long long N = (1 << LOGN) + 99;
long long dp[LOGN + 2][N];
long long sum[100];
long long n;
long long bribes[N];
int recursionCallCount = 0;

long long f(long long cnt, long long idx) {
    // Check recursion invariant
    check_recursion_invariant(cnt, idx, LOGN / 2); // Check for high recursion depth
    recursionCallCount++;
    check_recursive_calls_invariant(recursionCallCount, 5000); // Check for excessive recursive calls

    if (dp[cnt][idx] != -1) return dp[cnt][idx];
    if (bribes[idx] == -1) return 0;
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
    check_branching_invariant(n, (1 << (LOGN - 2))); // Check for high branching factor

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