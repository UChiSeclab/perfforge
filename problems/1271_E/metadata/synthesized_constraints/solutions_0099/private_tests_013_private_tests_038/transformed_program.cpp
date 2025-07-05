#include <bits/stdc++.h>
using namespace std;

// Performance checkers
void check_recursion_depth(int len) {
    if (len > 50) {
        cerr << "Warning: Performance bottleneck condition triggered - recursion too deep!" << endl;
        abort();
    }
}

void check_binary_length_invariant(int bit_length) {
    if (bit_length > 60) {
        cerr << "Warning: Performance bottleneck condition triggered - binary length too long!" << endl;
        abort();
    }
}

void check_solve_invariant(int solve_count) {
    if (solve_count > 10000) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive solve calls!" << endl;
        abort();
    }
}

const int MAXN = 5e5 + 2;
long long n, k;
int d[65], t[65];
int solve_call_count = 0;  // Counter for solve method calls

long long dfs(int len, bool limit, bool lead, int match) {
    check_recursion_depth(len);  // Check recursion depth
    
    if (!len) return match == 0;
    if (!match && !limit && !lead) return (1LL << len);
    int up = limit ? d[len] : 1;
    long long ans = 0;
    if (lead) ans += dfs(len - 1, limit && up == 0, 1, match);
    if (match) {
        if (up >= t[match])
            ans += dfs(len - 1, limit && up == t[match], 0, match - 1);
    } else
        for (register int i = (0), I = (up) + 1; i < I; ++i)
            ans += dfs(len - 1, limit && up == i, lead && i == 0, 0);
    return ans;
}

long long solve(long long x) {
    if (x > n) return 0;
    
    solve_call_count++;
    check_solve_invariant(solve_call_count);  // Check solve method calls

    memset(t, 0, sizeof(t));
    int bit_length = 0;
    while (x) {
        t[++t[0]] = x & 1;
        x = x >> 1;
        bit_length++;
    }
    check_binary_length_invariant(bit_length);  // Check binary length

    return dfs(d[0], 1, 1, t[0]);
}

int work() {
    scanf("%lld%lld", &n, &k);
    long long x = n;
    int binary_length = 0;
    while (x) {
        d[++d[0]] = x & 1;
        x = x >> 1;
        binary_length++;
    }
    check_binary_length_invariant(binary_length);  // Check initial binary length

    long long ans = 1;
    {
        long long l = 1, r = n / 2;
        while (l <= r) {
            const long long mid = (l + r) >> 1;
            if (solve(mid * 2) + solve(mid * 2 + 1) >= k)
                ans = max(ans, mid * 2), l = mid + 1;
            else
                r = mid - 1;
        }
    }
    {
        long long l = 1, r = (n + 1) / 2;
        while (l <= r) {
            const long long mid = (l + r) >> 1;
            if (solve(mid * 2 - 1) >= k)
                ans = max(ans, mid * 2 - 1), l = mid + 1;
            else
                r = mid - 1;
        }
    }
    return printf("%lld\n", ans);
}

int main() {
    work();
    return 0;
}