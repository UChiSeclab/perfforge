#include <bits/stdc++.h>
const int MAXN = 1e5 + 10;
int n, m;
long long a[MAXN], b[MAXN];

// Checkers implementation
void check_sensor_count_invariant(int n, int m) {
    if (n > 90000 && m > 90000) {
        cerr << "Warning: Performance bottleneck condition triggered - large sensor arrays!" << endl;
        abort();
    }
}

void check_unique_segments_invariant(const std::map<long long, int>& mp1, const std::map<long long, int>& mp2) {
    if (mp1.size() > 10000 || mp2.size() > 10000) {
        cerr << "Warning: Performance bottleneck condition triggered - too many unique reflective segments!" << endl;
        abort();
    }
}

void check_large_x_range_invariant(long long x) {
    if (x > (1LL << 30)) {
        cerr << "Warning: Performance bottleneck condition triggered - large range of x values!" << endl;
        abort();
    }
}

int main() {
    scanf("%d%*d", &n);
    for (int i = 1; i <= n; i++) scanf("%lld", a + i), a[i] += 1e9;
    scanf("%d%*d", &m);
    for (int i = 1; i <= m; i++) scanf("%lld", b + i), b[i] += 1e9;
    
    // Insert sensor count check after reading input
    check_sensor_count_invariant(n, m);

    int ans = 0;
    for (long long x = 2; x <= 1e10; x <<= 1) {
        std::map<long long, int> mp1, mp2;
        for (int i = 1; i <= n; i++) {
            mp1[a[i] & (x - 1)]++;
        }
        for (int i = 1; i <= m; i++) {
            mp2[b[i] & (x - 1)]++;
        }
        
        // Insert unique segments check in the loop
        check_unique_segments_invariant(mp1, mp2);
        
        for (auto i : mp1) {
            ans = std::max(ans, i.second + (mp2[i.first ^ (x >> 1)]));
        }
        for (auto i : mp2) {
            ans = std::max(ans, i.second + (mp1[i.first ^ (x >> 1)]));
        }
        
        // Insert large x range check in the loop
        check_large_x_range_invariant(x);
    }
    {
        std::map<long long, int> mp1, mp2;
        for (int i = 1; i <= n; i++) {
            mp1[a[i]]++;
        }
        for (int i = 1; i <= m; i++) {
            mp2[b[i]]++;
        }
        for (auto i : mp1) {
            ans = std::max(ans, i.second + (mp2[i.first]));
        }
        for (auto i : mp2) {
            ans = std::max(ans, i.second + (mp1[i.first]));
        }
    }
    printf("%d\n", ans);
}