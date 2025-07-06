#include <bits/stdc++.h>
using namespace std;

// Checker functions
void check_comparison_invariant(long long n, long long k) {
    if (n > 10 * k) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive comparisons due to large n relative to k!" << endl;
        abort();
    }
}

void check_adjustment_invariant(long long s, long long b, long long ai) {
    if (s + ai > b && s + ai < b + 1000) {
        cerr << "Warning: Performance bottleneck condition triggered - frequent adjustments due to frequent near-limit comparisons!" << endl;
        abort();
    }
}

void check_sorting_invariant(long long n) {
    if (n > 10000) {
        cerr << "Warning: Performance bottleneck condition triggered - potential excessive sorting operations!" << endl;
        abort();
    }
}

void check_nested_loop_invariant(long long k, long long n) {
    if (k < n / 10) {
        cerr << "Warning: Performance bottleneck condition triggered - potentially excessive nested loop iterations!" << endl;
        abort();
    }
}

long long n, k, b, s, ans;

int main() {
    cin >> n >> k >> b;
    
    // Perform invariant checks
    check_comparison_invariant(n, k);
    check_sorting_invariant(n);
    check_nested_loop_invariant(k, n);

    vector<pair<long long, long long>> a(n - 1);
    for (int i = 0; i < n - 1; i++) cin >> a[i].first, a[i].second = i;

    sort(a.rbegin(), a.rend());

    for (int i = 0; i < k - 1; i++) s += a[i].first;

    ans = n - 1;
    for (int i = k; i < n - 1; i++) {
        check_adjustment_invariant(s, b, a[i].first);
        if (s + a[i].first > b) ans = min(ans, a[i].second);
    }

    s += a[k - 1].first;
    if (s > b)
        for (int i = 0; i < k; i++) ans = min(ans, a[i].second);

    cout << ans + 1;
}