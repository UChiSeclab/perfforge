#include <bits/stdc++.h>
using namespace std;
const long long N = 111111;
long long n, A, R, M, h[N];

// Performance Checker Functions
void check_large_height_range_invariant(long long minHeight, long long maxHeight) {
    if ((maxHeight - minHeight) > 1000000) { // Arbitrary large threshold for illustration
        cerr << "Warning: Performance bottleneck condition triggered - large height range!" << endl;
        abort();
    }
}

void check_brick_addition_invariant(long long additions, long long totalPillars) {
    if (additions > totalPillars * 0.75) { // If more than 75% of pillars require additions
        cerr << "Warning: Performance bottleneck condition triggered - excessive brick additions!" << endl;
        abort();
    }
}

void check_ternary_search_invariant(long long l, long long r) {
    if ((r - l) > 1000000) { // Arbitrary large threshold for search range
        cerr << "Warning: Performance bottleneck condition triggered - large ternary search range!" << endl;
        abort();
    }
}

long long f(long long H) {
    long long x = 0, y = 0;
    for (long long i = 0; i < n; ++i) {
        if (h[i] > H)
            x += h[i] - H;
        else
            y += H - h[i];
    }
    
    check_brick_addition_invariant(y, n); // Check for excessive additions
    
    return min(x, y) * M + (x - min(x, y)) * R + (y - min(x, y)) * A;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin >> n >> A >> R >> M;
    M = min(M, A + R);
    for (long long i = 0; i < n; ++i) cin >> h[i];
    
    long long l = 0, r = 1e9;
    long long minHeight = *min_element(h, h + n);
    long long maxHeight = *max_element(h, h + n);
    
    check_large_height_range_invariant(minHeight, maxHeight); // Check for large height range
    
    while (r - l > 20) {
        long long lmed = l + (r - l) / 3;
        long long rmed = r - (r - l) / 3;
        
        check_ternary_search_invariant(l, r); // Check for large ternary search range
        
        if (f(lmed) < f(rmed))
            r = rmed;
        else
            l = lmed;
    }
    long long res = 1e18;
    for (long long i = l; i <= r; ++i) res = min(res, f(i));
    cout << res;
}