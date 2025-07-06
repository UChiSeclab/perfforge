#include <bits/stdc++.h>
using namespace std;

long long readint() {
    long long x = 0, s = 1;
    char c;
    while ((c = getchar()), c < '0' || c > '9') {
        if (c == '-') s = -1;
    }
    while (c >= '0' && c <= '9') {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return s * x;
}

void print(long long x) {
    char c[20];
    if (!x) {
        putchar('0');
        return;
    }
    if (x < 0) putchar('-'), x = -x;
    int i = 0;
    while (x > 0) c[++i] = x % 10, x /= 10;
    while (i) putchar(c[i--] + 48);
}

void scan(long long& x) { x = readint(); }
template <typename T, typename... A>
void print(T& x, A&... a) {
    print(x);
    putchar(' ');
    print(a...);
}

template <typename T, typename... A>
void scan(T& x, A&... a) {
    scan(x);
    scan(a...);
}

long long n, m, k;
long long A[77][77];
long long memo1[72][72][72][38];
long long dp1(long long r, long long c, long long d, long long rem) {
    if (rem < 0) return -2000000007;
    if (c == m) return (d ? -2000000007 : 0);
    if (memo1[r][c][d][rem] != -1) return memo1[r][c][d][rem];
    return memo1[r][c][d][rem] =
               max(dp1(r, c + 1, d, rem),
                   dp1(r, c + 1, (d + A[r][c]) % k, rem - 1) + A[r][c]);
}

long long memo2[72][72];
long long dp2(long long r, long long d) {
    if (r == n) return (d ? -2000000007 : 0);
    if (memo2[r][d] != -1) return memo2[r][d];
    long long ret = -2000000007;
    for (long long i = 0; i < k; i++) {
        ret = max(ret, dp2(r + 1, (i + d) % k) + dp1(r, 0, i, m / 2));
    }
    return memo2[r][d] = ret;
}

void check_divisor_invariant(long long k) {
    if (k > 60) { 
        cerr << "Warning: Performance bottleneck condition triggered due to large divisor k!" << endl;
        abort();
    }
}

void check_matrix_width_invariant(long long m) {
    if (m > 60) { 
        cerr << "Warning: Performance bottleneck condition triggered due to large matrix width m!" << endl;
        abort();
    }
}

void check_element_value_invariant(const long long A[77][77], long long n, long long m, long long k) {
    long long similarCount = 0;
    for (long long i = 0; i < n; ++i) {
        for (long long j = 0; j < m; ++j) {
            if (A[i][j] >= k / 2) similarCount++;
        }
    }
    if (similarCount > (n * m) / 2) { // If more than half the elements are similar in this way
        cerr << "Warning: Performance bottleneck condition triggered due to element value similarity!" << endl;
        abort();
    }
}

int32_t main() {
    scan(n, m, k);
    memset(memo1, -1, sizeof memo1);
    memset(memo2, -1, sizeof memo2);
    
    for (long long i = 0; i < n; i++) {
        for (long long j = 0; j < m; j++) {
            scan(A[i][j]);
        }
    }

    // Check for potential performance bottlenecks
    check_divisor_invariant(k);
    check_matrix_width_invariant(m);
    check_element_value_invariant(A, n, m, k);

    cout << dp2(0, 0) << endl;
}