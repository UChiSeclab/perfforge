#include <bits/stdc++.h>
using namespace std;

// Checker function for high maximum stick length
void check_max_length_invariant(int mx) {
    if (mx > 1000000 - 1000) {  // Assume "close to maximum" means within 1000 of the upper limit.
        cerr << "Warning: High maximum stick length triggering performance bottleneck!" << endl;
        abort();
    }
}

// Checker function for high frequency of stick count adjustments
void check_adjustment_invariant(const int* a, int size) {
    int adjustments = 0;
    for (int i = 0; i < size; ++i) {
        if (a[i] & 1) adjustments++;
    }
    if (adjustments > size / 10) {  // Consider it a bottleneck if more than 10% adjustments.
        cerr << "Warning: High frequency of stick count adjustments!" << endl;
        abort();
    }
}

// Checker function for large range of stick lengths
void check_large_range_invariant(int min, int max) {
    if (max - min > 1000000 - 2) {  // Large range close to maximum possible.
        cerr << "Warning: Large range of stick lengths causing slowdown!" << endl;
        abort();
    }
}

int a[1000100];

int main(int argc, char const *argv[]) {
    int n, mx = 0;
    scanf("%d", &n);
    int min_length = INT_MAX, max_length = INT_MIN;
    for (int i = 0, x; i < n; ++i) {
        scanf("%d", &x);
        ++a[x];
        mx = max(mx, x);
        min_length = min(min_length, x);
        max_length = max(max_length, x);
    }

    // Insert performance checks
    check_max_length_invariant(mx);
    check_large_range_invariant(min_length, max_length);

    for (int i = mx; i >= 2; --i) {
        if (a[i] & 1) {
            --a[i];
            if (a[i - 1] > 0) ++a[i - 1];
        }
    }
    
    // Insert adjustment check after processing adjustments
    check_adjustment_invariant(a, 1000100);

    long long ans = 0;
    pair<int, int> left = {0, 0};
    for (int i = mx; i >= 2; --i) {
        if (a[i] == 0) continue;
        if (left.second == 2 && a[i] >= 2) {
            ans += 1LL * left.first * i;
            a[i] -= 2;
        }
        if (a[i] > 2) {
            ans += (1LL * i * i) * (a[i] / 4LL);
            a[i] -= (a[i] / 4LL) * 4LL;
        }
        left.first = i;
        left.second = a[i];
    }
    printf("%lld\n", ans);
    return 0;
}