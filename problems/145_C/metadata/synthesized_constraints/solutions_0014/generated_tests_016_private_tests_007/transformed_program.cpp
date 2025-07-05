#include <bits/stdc++.h>
using namespace std;
vector<long long> lucky;

// Checker functions
void check_recursive_invariant(int total_lucky, int k) {
    if (total_lucky > 50 && k < 10) {
        cerr << "Warning: Performance bottleneck condition triggered - high recursion depth and low k!" << endl;
        abort();
    }
}

void check_factorial_invariant(int others, int total_lucky, int k) {
    if (others > 50000 && total_lucky > 10) {
        cerr << "Warning: Performance bottleneck condition triggered - heavy factorial calculations!" << endl;
        abort();
    }
}

void check_recursive_call_count(int idx, int lucky_size) {
    if (idx > lucky_size - 10) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive recursive call depth!" << endl;
        abort();
    }
}

void check_large_input_invariant(int n, int total_lucky) {
    if (n > 10000 && total_lucky > 20) {
        cerr << "Warning: Performance bottleneck condition triggered - large input with many lucky numbers!" << endl;
        abort();
    }
}

void gen(long long num) {
    if (num > 1000000000) return;
    if (num) lucky.push_back(num);
    gen(num * 10 + 4);
    gen(num * 10 + 7);
}

map<long long, long long> mark;
long long cnt[1034];
long long dp[1034][1034];
long long fact[100005];

long long call(int idx, int cntt) {
    check_recursive_call_count(idx, lucky.size()); // Check for excessive recursive call depth
    if (idx > (int)lucky.size()) {
        if (cntt == 0) return 1;
        return 0;
    }
    long long &ret = dp[idx][cntt];
    if (ret != -1) return ret;
    long long p = 0, q = 0;
    if (cntt) {
        p = (cnt[idx] * (call(idx + 1, cntt - 1))) % 1000000007;
    }
    q = call(idx + 1, cntt);
    return ret = (p + q) % 1000000007;
}

long long bigmod(long long n, long long p) {
    long long ret = 1;
    while (p > 0) {
        if (p % 2) ret = (ret * n) % 1000000007;
        n = (n * n) % 1000000007;
        p /= 2;
    }
    return ret;
}

long long nCr(long long n, long long r) {
    long long up = fact[n];
    long long down = (fact[r] * fact[n - r]) % 1000000007;
    down = bigmod(down, 1000000007 - 2);
    long long ret = (up * down) % 1000000007;
    return ret;
}

int main() {
    gen(0);
    sort(lucky.begin(), lucky.end());
    for (int i = 0; i < (int)lucky.size(); i++) {
        mark[lucky[i]] = i + 1;
    }
    int n, k;
    scanf("%d %d", &n, &k);
    long long others = 0;
    int total_lucky = 0;
    for (int i = 0; i < n; i++) {
        long long a;
        scanf("%lld", &a);
        if (mark[a]) {
            if (cnt[mark[a]] == 0) total_lucky++;
            cnt[mark[a]]++;
        } else
            others++;
    }

    // Checking conditions after input processing
    check_large_input_invariant(n, total_lucky); // Check for large input with many lucky numbers
    check_factorial_invariant(others, total_lucky, k); // Check for heavy factorial calculations
    check_recursive_invariant(total_lucky, k); // Check recursion-related conditions

    fact[0] = 1;
    for (long long i = 1; i < 100005; i++)
        fact[i] = (fact[i - 1] * i) % 1000000007;

    if (others + total_lucky < k) {
        printf("0\n");
        return 0;
    }
    long long ans = 0;
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i <= total_lucky; i++) {
        long long x = k - i;
        if (x <= others && x >= 0) {
            long long temp = nCr(others, x);
            long long temp1 = (call(1, i)) % 1000000007;
            temp = (temp * temp1) % 1000000007;
            ans = (ans + temp) % 1000000007;
        }
    }
    printf("%lld\n", ans);
    return 0;
}