#include <bits/stdc++.h>
using namespace std;

int a[101010], f[101010], num[101010];

// Function to calculate power
inline long long power(long long a, int k) {
    long long ans = 1;
    for (; k; k >>= 1, a *= a)
        if (k & 1) ans *= a;
    return ans;
}

// Check for large maximum element with high k
void check_large_max_element(int maxElement, int k) {
    if (maxElement > 50000 && k > 50) {
        cerr << "Warning: Performance bottleneck condition triggered - large maximum element with high k!" << endl;
        abort();
    }
}

// Check for high exponentiation cost
void check_high_exponentiation_cost(int k, int n) {
    if (k > 50 && n > 10000) {
        cerr << "Warning: Performance bottleneck condition triggered - high exponentiation cost!" << endl;
        abort();
    }
}

int main() {
    // Initialize sieve for prime factors
    for (int i = 2; i < 101010; i++) {
        if (!f[i]) {
            f[i] = i;
            if ((long long)i * i >= 101010) continue;
            for (int j = i * i; j < 101010; j += i) f[j] = i;
        }
    }

    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++) scanf("%d", a + i);

    // Check performance conditions
    check_high_exponentiation_cost(k, n);

    if (k == 2) {
        long long ans = 0;
        for (int i = 1; i <= n; i++) {
            int u = a[i], val = 1;
            while (u > 1) {
                int p = f[u], num = 0;
                while (u % p == 0) u /= p, num ^= 1;
                if (num) val *= p;
            }
            ans += num[val];
            num[val]++;
        }
        cout << ans << endl;
        return 0;
    }

    int mx = 0;
    for (int i = 1; i <= n; i++) {
        num[a[i]]++;
        mx = max(mx, a[i]);
    }

    // Check performance condition for large maximum element
    check_large_max_element(mx, k);

    int ed = 1;
    while (k * log(ed) < log((double)mx * mx + 1)) ed++;
    ed++;
    long long ans = 0;
    for (int i = 1; i <= ed; i++) {
        long long val = power((long long)i, k);
        for (int j = 1; j <= mx; j++)
            if (val % j == 0) {
                long long x = val / j;
                if (0 < x && x <= mx && x <= j) {
                    if (x < j)
                        ans += (long long)num[j] * num[x];
                    else
                        ans += (long long)num[j] * (num[j] - 1) >> 1;
                }
            }
    }
    cout << ans << endl;
}