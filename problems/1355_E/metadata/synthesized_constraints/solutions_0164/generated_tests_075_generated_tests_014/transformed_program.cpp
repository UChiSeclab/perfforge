#include <bits/stdc++.h>
using namespace std;

// Checker functions
void check_height_variance_invariant(const vector<long long>& heights, int n, int heightThreshold) {
    long long min_height = *min_element(heights.begin(), heights.end());
    long long max_height = *max_element(heights.begin(), heights.end());
    if ((max_height - min_height) > heightThreshold) {
        cerr << "Warning: Performance bottleneck condition triggered due to high variance in pillar heights!" << endl;
        abort();
    }
}

void check_search_range_invariant(int initialLow, int initialHigh, int rangeThreshold) {
    if ((initialHigh - initialLow) > rangeThreshold) {
        cerr << "Warning: Performance bottleneck condition triggered due to large search range in ternary search!" << endl;
        abort();
    }
}

void check_cost_dynamics_invariant(long long a, long long r, long long m) {
    if ((a > r && r > m) || (m > a && a > r)) {
        cerr << "Warning: Performance bottleneck condition triggered due to complex cost dynamics!" << endl;
        abort();
    }
}

void check_input_size_variance_invariant(int n, const vector<long long>& heights, int sizeThreshold, int varianceThreshold) {
    long long min_height = *min_element(heights.begin(), heights.end());
    long long max_height = *max_element(heights.begin(), heights.end());
    if (n > sizeThreshold && (max_height - min_height) > varianceThreshold) {
        cerr << "Warning: Performance bottleneck condition triggered due to high input size and variance!" << endl;
        abort();
    }
}

// Original program with integrated checks
int main() {
    int n;
    long long a, r, m;
    cin >> n >> a >> r >> m;
    vector<long long> arr(n);
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
    }

    // Insert checks after reading input
    check_height_variance_invariant(arr, n, 1000); // Arbitrary threshold for height variance
    check_search_range_invariant(0, 1e9 + 1, 1e9); // Threshold for range in ternary search
    check_cost_dynamics_invariant(a, r, m); // Check cost dynamics complexity
    check_input_size_variance_invariant(n, arr, 10000, 1000); // Threshold for size and variance

    int l = 0, r = 1e9 + 1, m1, m2;
    while (l < r) {
        m1 = l + (r - l) / 3;
        m2 = l + 2 * (r - l) / 3;
        if (f(m1, arr, n, a, r, m) > f(m2, arr, n, a, r, m))
            l = m1 + 1;
        else
            r = m2;
    }
    cout << f(l, arr, n, a, r, m) << endl;
    return 0;
}

// Helper function to calculate cost
long long f(int h, const vector<long long>& arr, int n, long long a, long long r, long long m) {
    long long pos = 0, neg = 0;
    for (int i = 0; i < n; i++) {
        pos += max(0ll, arr[i] - h);
        neg += max(0ll, h - arr[i]);
    }
    if (a + r < m) return a * neg + r * pos;
    long long mini = min(pos, neg);
    return m * mini + a * (neg - mini) + r * (pos - mini);
}