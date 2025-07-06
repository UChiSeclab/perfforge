#include <bits/stdc++.h>
using namespace std;

// Checker function for large position values
void check_position_invariant(int maxPosition) {
    if (maxPosition > 100000) {
        cerr << "Warning: Performance bottleneck condition triggered - excessively high position value leading to extensive iterations!" << endl;
        abort();
    }
}

// Checker function for linear processing
void check_linear_processing_invariant(int maxPosition, int n) {
    if (maxPosition > 10 * n) {
        cerr << "Warning: Performance bottleneck condition triggered - high position range relative to number of beacons!" << endl;
        abort();
    }
}

// Checker function for dense operations
void check_dense_operation_invariant(int maxPosition) {
    if (maxPosition > 100000) {
        cerr << "Warning: Performance bottleneck condition triggered - dense operations on large position range!" << endl;
        abort();
    }
}

int main() {
    int n, i, j, d;
    vector<pair<int, int>> ab;
    cin >> n;
    for (i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        ab.push_back(make_pair(a, b));
    }
    sort(ab.begin(), ab.end());

    int maxPosition = ab.back().first; // Calculate the maximum position for checking
    check_position_invariant(maxPosition);
    check_linear_processing_invariant(maxPosition, n);
    check_dense_operation_invariant(maxPosition);

    vector<int> cnt(maxPosition + 2);
    vector<int> dst(maxPosition + 1);

    for (auto p : ab) {
        cnt[p.first + 1]++;
    }
    for (i = 0; i < maxPosition + 1; i++) cnt[i + 1] += cnt[i];
    j = 0;
    d = 0;
    for (i = 0; i < n; i++) {
        for (; j < ab[i].first; j++) {
            dst[j] = d;
        }
        dst[j] = cnt[j];
        if (ab[i].second <= j) dst[j] -= cnt[j - ab[i].second];
        if (ab[i].second < j) dst[j] += dst[j - ab[i].second - 1];
        d = dst[j];
    }
    int mn = n - cnt[0];
    for (i = 0; i < maxPosition + 1; i++) {
        mn = min(mn, n - cnt[i + 1] + dst[i]);
    }
    cout << mn << endl;
    return 0;
}