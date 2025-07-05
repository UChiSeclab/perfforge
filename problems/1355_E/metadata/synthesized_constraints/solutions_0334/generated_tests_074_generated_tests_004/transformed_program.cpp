#include <bits/stdc++.h>

// Checkers for performance invariants
void check_variability_invariant(const std::vector<long long>& h) {
    long long maxHeight = *std::max_element(h.begin(), h.end());
    long long minHeight = *std::min_element(h.begin(), h.end());
    if (maxHeight - minHeight > 1e8) { // Threshold chosen to indicate very high variability
        cerr << "Warning: Performance bottleneck condition triggered due to high variability in pillar heights!" << endl;
        abort();
    }
}

void check_binary_search_invariant(long long lo, long long hi) {
    if (hi - lo > 1e8) { // Arbitrary large threshold for detection
        cerr << "Warning: Performance bottleneck condition triggered due to large range in binary search!" << endl;
        abort();
    }
}

void check_expensive_operation_invariant(long long a, long long b) {
    if (b > 100 * a) { // Arbitrary ratio threshold indicating expensive removal operations
        cerr << "Warning: Performance bottleneck condition triggered due to expensive removal operations!" << endl;
        abort();
    }
}

int main() {
    int n;
    long long a, b, c;
    std::cin >> n >> a >> b >> c;
    std::vector<long long> h(n);
    for (int i = 0; i < n; i++) std::cin >> h[i];

    // Check for high variability in initial heights
    check_variability_invariant(h);

    // Check for expensive operations
    check_expensive_operation_invariant(a, b);
    
    std::sort(h.rbegin(), h.rend());
    auto func = [&](long long targ) {
        long long cnt = 0;
        for (int i = 0; i < n; i++) cnt += std::max(0LL, h[i] - targ);
        long long ret = 0;
        bool ok[100003] = {};
        for (int i = 0; i < n; i++) {
            if (targ - h[i] > cnt) break;
            ret += std::max(0LL, targ - h[i]) * std::min(a + b, c);
            cnt -= std::max(0LL, targ - h[i]);
            ok[i] = true;
        }
        for (int i = 0; i < n; i++) {
            if (ok[i]) continue;
            long long res = targ - h[i];
            if (cnt > 0) {
                res -= cnt;
                ret += cnt * std::min(a + b, c);
                cnt = 0;
            }
            ret += res * a;
        }
        if (cnt > 0) ret += cnt * b;
        return ret;
    };
    long long lo = -1, hi = 1e9 + 1;

    // Check for large initial range in binary search
    check_binary_search_invariant(lo, hi);

    while (hi - lo > 1) {
        long long mid = lo + (hi - lo) / 2;
        long long l = func(mid);
        long long r = func(mid + 1);
        if (l > r)
            lo = mid;
        else
            hi = mid;
    }
    std::cout << std::min(func(lo), func(hi)) << std::endl;
    return 0;
}