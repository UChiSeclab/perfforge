#include <bits/stdc++.h>
using namespace std;

int gdc(int a, int b) {
    if (!b)
        return a;
    else
        return gdc(b, a % b);
}

// Performance checks based on derived invariants
void check_minDiff_invariant(int minDiff, int maxGap) {
    if (minDiff < 1 || maxGap / minDiff > 100000) {  // Example threshold
        cerr << "Warning: Performance bottleneck condition triggered - small minDiff relative to gaps!" << endl;
        abort();
    }
}

void check_large_gap_invariant(int maxGap, int minDiff) {
    if (maxGap > 100000 && minDiff < 10) {  // Example threshold
        cerr << "Warning: Performance bottleneck condition triggered - large gap with small minDiff!" << endl;
        abort();
    }
}

void check_uneven_spacing_invariant(int minDiff, int n) {
    if (minDiff < 1 && n > 10000) {  // Example threshold
        cerr << "Warning: Performance bottleneck condition triggered - high density with uneven spacing!" << endl;
        abort();
    }
}

int execute() {
    int n;
    cin >> n;
    int a[n], i, diff[n], minDiff, ans = 0;
    for (i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);

    // Calculate differences
    for (i = 1; i < n; i++) diff[i - 1] = a[i] - a[i - 1];
    minDiff = diff[0];
    int maxGap = diff[0];

    // Calculate minDiff using GCD
    for (i = 1; i < n - 1 && ans != 1; i++) {
        minDiff = gdc(minDiff, diff[i]);
        if (diff[i] > maxGap) maxGap = diff[i];
    }

    // Insert performance checks after computing minDiff
    check_minDiff_invariant(minDiff, maxGap);
    check_large_gap_invariant(maxGap, minDiff);
    check_uneven_spacing_invariant(minDiff, n);

    // Calculate number of points to add
    for (i = 0; i < n - 1; i++) {
        while (a[i] + minDiff != a[i + 1]) {
            a[i] += minDiff;
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}

char mtest = false;
unsigned short TE = 1;

int main() {
    ios_base::sync_with_stdio(false);
    if (mtest) cin >> TE;
    while (TE--) execute();
    return 0;
}