#include <bits/stdc++.h>
using namespace std;

inline long long read() {
    long long a = 0, f = 1;
    char ch = getchar();
    for (; !isdigit(ch); ch = getchar())
        if (ch == '-') f = -1;
    for (; isdigit(ch); ch = getchar()) a = (a << 3) + (a << 1) + ch - '0';
    return a * f;
}

void write(long long x) {
    if (x < 0) x = -x, putchar('-');
    if (x > 9) write(x / 10);
    putchar((x % 10) ^ 48);
}

const long long mod = 998244353;
const long long N = 1e3 + 5;

struct node {
    long long x, y, data;
    inline bool operator<(const node& a) const { return data < a.data; }
} p[N * N];

inline long long qpow(long long a, long long n) {
    long long ans = 1;
    int powerCalculationCount = 0; // Counter for power calculations
    for (; n; n >>= 1, a = a * a % mod) {
        if (n & 1) ans = ans * a % mod;
        powerCalculationCount++;
    }
    check_expensive_power_calculations(powerCalculationCount); // Check for excessive power calculations
    return ans;
}

inline long long getinv(long long a) { return qpow(a, mod - 2); }

long long f, fs, xs, ys, fsw, xsw, ysw;
long long X, Y, n, m, cnt, pos;

void check_high_comparable_elements(int comparableElements) {
    if (comparableElements > 1000) { // Arbitrary threshold for demonstration
        cerr << "Warning: Performance bottleneck due to high number of comparable elements!" << endl;
        abort();
    }
}

void check_high_index_in_sorted(int position, int totalElements) {
    if (position > totalElements / 2) { // If starting from a high index, potential bottleneck
        cerr << "Warning: Performance bottleneck due to high index in sorted elements!" << endl;
        abort();
    }
}

void check_expensive_power_calculations(int powerCalculationCount) {
    if (powerCalculationCount > 5000) { // Threshold for excessive pow calculations
        cerr << "Warning: Performance bottleneck due to excessive power calculations!" << endl;
        abort();
    }
}

signed main() {
    n = read(), m = read();
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            p[++cnt].x = i;
            p[cnt].y = j;
            p[cnt].data = read();
        }
    }
    X = read(), Y = read();
    sort(p + 1, p + cnt + 1);

    for (int i = 1; i <= cnt; i++)
        if (p[i].x == X && p[i].y == Y) {
            pos = i;
            break;
        }

    check_high_index_in_sorted(pos, cnt); // Check if the initial position is a bottleneck

    int comparableElements = 0;

    for (int i = 1, j = 0; i <= pos; i++) {
        f = (fs - 2 * p[i].x * xs % mod - 2 * p[i].y * ys % mod + mod + mod) % mod;
        f = f * qpow(j, mod - 2) % mod;
        f = (f + p[i].x * p[i].x % mod * qpow(j, mod - 1)) % mod;
        f = (f + p[i].y * p[i].y % mod * qpow(j, mod - 1)) % mod;
        fsw += f;
        fsw += p[i].x * p[i].x % mod;
        fsw += p[i].y * p[i].y % mod;
        fsw %= mod;
        xsw += p[i].x;
        xs %= mod;
        ysw += p[i].y;
        ys %= mod;
        if (p[i].data < p[i + 1].data) {
            j = i;
            fs = (fs + fsw) % mod;
            xs = (xs + xsw) % mod;
            ys = (ys + ysw) % mod;
            fsw = xsw = ysw = 0;
        }
        comparableElements++;
    }

    check_high_comparable_elements(comparableElements); // Check for high number of comparable elements

    printf("%lld\n", (f + mod) % mod);
    return 0;
}