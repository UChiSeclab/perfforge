#include <bits/stdc++.h>
using namespace std;
const int di[] = {-1, 0, 1, 0, -1, 1, 1, -1};
const int dj[] = {0, 1, 0, -1, -1, 1, -1, 1};
const long long MOD = 1e9 + 7;
const long long INF = 1e9;
const long double EPS = 1e-7;

long long fastPow(long long a, int p, int m) {
    if (p == 0) return 1;
    if (p % 2 == 1) return (a * fastPow(a, p - 1, m)) % m;
    long long c = fastPow(a, p / 2, m);
    return (c * c) % m;
}

vector<int> mem(1e5 + 5, -1);

long long fact(long long n) {
    if (n == 0) return 1;
    if (~mem[n]) return mem[n];
    return mem[n] = (n * fact(n - 1)) % MOD;
}

long long nCr(long long n, long long r) {
    if (!(n >= r)) return 0;
    long long ret = fact(n) * fastPow(fact(r), MOD - 2, MOD);
    ret %= MOD;
    ret *= fastPow(fact(n - r), MOD - 2, MOD);
    ret %= MOD;
    return ret;
}

bool lucky(int n) {
    while (n) {
        if (n % 10 != 4 && n % 10 != 7) return false;
        n /= 10;
    }
    return true;
}

void check_modular_arithmetic_invariant(int uniqueLuckyCount, int threshold = 100) {
    if (uniqueLuckyCount > threshold) {
        cerr << "Warning: Performance bottleneck condition triggered - high number of unique lucky numbers!" << endl;
        abort();
    }
}

void check_combination_invariant(int uniqueLuckyCount, int threshold = 100) {
    if (uniqueLuckyCount * uniqueLuckyCount > threshold) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive combination calculations!" << endl;
        abort();
    }
}

void check_dp_invariant(int uniqueLuckyCount, int k, int threshold = 100) {
    if (uniqueLuckyCount * k > threshold) {
        cerr << "Warning: Performance bottleneck condition triggered - potential DP table overhead!" << endl;
        abort();
    }
}

vector<long long> cnt;

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    map<int, long long> cntm;
    long long others = n;
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        if (lucky(x)) cntm[x]++, others--;
    }

    int uniqueLuckyCount = cntm.size();

    // Insert checks based on performance-characterizing invariants
    check_modular_arithmetic_invariant(uniqueLuckyCount);
    check_combination_invariant(uniqueLuckyCount);
    check_dp_invariant(uniqueLuckyCount, k);

    for (auto& i : cntm) cnt.push_back(i.second);
    if (k == 1) {
        printf("%d\n", n);
    } else {
        vector<vector<long long>> dp(2, vector<long long>(1e5 + 5));
        if (cnt.empty()) {
            dp[0][0] = 1;
        } else {
            dp[cnt.size() & 1][0] = 1;
            for (int i = (int)cnt.size() - 1; i >= 0; i--) {
                dp[i & 1][0] = 1;
                for (int j = 1; j <= k && j <= cnt.size() - i; j++) {
                    dp[i & 1][j] = cnt[i] * dp[(i + 1) & 1][j - 1];
                    dp[i & 1][j] %= MOD;
                    dp[i & 1][j] += dp[(i + 1) & 1][j];
                    dp[i & 1][j] %= MOD;
                }
            }
        }
        long long r = 0;
        for (int i = 0; i <= k; i++) {
            r += (nCr(others, i) * dp[0][k - i]) % MOD;
            r %= MOD;
        }
        printf("%I64d\n", r);
    }
    cin.ignore(), cin.get();
}