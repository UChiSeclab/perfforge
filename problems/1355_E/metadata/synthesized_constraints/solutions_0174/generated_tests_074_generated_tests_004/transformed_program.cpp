#include <bits/stdc++.h>
#pragma GCC optimize(3, "Ofast", "inline")
using namespace std;
const int N = 100010;
const int mod = 998244353;
const double PI = 3.1415926535898;
int n;
long long a, r, m;
long long h[N];

inline long long calc(long long x) {
    long long p = 0, q = 0;
    for (int i = 1; i <= n; ++i) {
        if (h[i] <= x)
            p += x - h[i];
        else
            q += h[i] - x;
    }
    return min(p * a + q * r,
               min(p, q) * m + (p - min(p, q)) * a + (q - min(p, q)) * r);
}

// Checkers based on the performance-characterizing invariants

void check_height_variance(const vector<long long>& heights) {
    long long min_height = *min_element(heights.begin(), heights.end());
    long long max_height = *max_element(heights.begin(), heights.end());
    if (max_height - min_height > 1000000) {
        cerr << "Warning: Performance bottleneck condition triggered due to high variance in pillar heights!" << endl;
        abort();
    }
}

void check_cost_balance(long long a, long long r, long long m) {
    if (a > 10 * m || r > 10 * m) {
        cerr << "Warning: Performance bottleneck condition triggered due to cost imbalance!" << endl;
        abort();
    }
}

void check_intermediate_calculations(long long n, int iterations) {
    if (n * iterations > 1000000) {
        cerr << "Warning: Performance bottleneck due to excessive intermediate calculations!" << endl;
        abort();
    }
}

void check_number_of_pillars(int n) {
    if (n > 100000) {
        cerr << "Warning: Performance bottleneck due to large number of pillars!" << endl;
        abort();
    }
}

int main() {
    scanf("%d %lld %lld %lld", &n, &a, &r, &m);
    
    // Checking for number of pillars
    check_number_of_pillars(n);

    vector<long long> heights(n);
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", &h[i]);
        heights[i-1] = h[i];
    }
    
    // Checking height variance
    check_height_variance(heights);
    
    // Checking cost balance
    check_cost_balance(a, r, m);
    
    long long l = 0, r = 2000000000, mid, ret = 0;

    // Checking for excessive intermediate calculations
    check_intermediate_calculations(n, 233);

    for (int t = 1; t <= 233; ++t) {
        mid = (l + r) >> 1;
        if (calc(mid) < calc((mid + r) >> 1))
            r = (mid + r) >> 1;
        else
            l = mid;
    }
    printf("%lld\n", calc(l));
    return 0;
}