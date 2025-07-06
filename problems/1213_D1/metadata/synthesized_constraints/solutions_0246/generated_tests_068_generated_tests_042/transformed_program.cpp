#include <bits/stdc++.h>
using namespace std;

// Checker for division operations in nested loops
void check_division_invariant(int totalDivisions) {
    if (totalDivisions > 1000) { // Example threshold
        cerr << "Warning: Performance bottleneck due to excessive division operations!" << endl;
        abort();
    }
}

// Checker for size of intermediate vector
void check_vector_size_invariant(const std::vector<long long>& v) {
    if (v.size() > 500) { // Example threshold
        cerr << "Warning: Performance bottleneck due to large intermediate vector!" << endl;
        abort();
    }
}

// Checker for repeated sorting operations
void check_sort_invariant(int sortCount) {
    if (sortCount > 200) { // Example threshold
        cerr << "Warning: Performance bottleneck due to excessive sorting operations!" << endl;
        abort();
    }
}

void start() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int32_t main() {
    start();
    long long n, k;
    cin >> n >> k;
    long long a[n];
    for (long long i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<long long> v;
    int totalDivisions = 0; // Track total division operations

    for (long long i = 0; i < n; i++) {
        long long x = a[i];
        while (x > 0) {
            v.push_back(x);
            x /= 2;
            totalDivisions++;
        }
    }

    // Check the size of the vector after populating it
    check_vector_size_invariant(v);
    // Check the number of division operations
    check_division_invariant(totalDivisions);

    long long ans = LLONG_MAX;
    int sortCount = 0; // Track number of sorts

    for (auto res : v) {
        vector<long long> cnt;
        for (long long i = 0; i < n; i++) {
            long long x = a[i];
            long long cur = 0;
            while (x > res) {
                x /= 2;
                cur++;
            }
            if (x == res) {
                cnt.push_back(cur);
            }
        }
        if (cnt.size() < k) {
            continue;
        }
        sort(cnt.begin(), cnt.end());
        sortCount++;
        // Check sorting operations frequency
        check_sort_invariant(sortCount);

        long long sum = 0;
        for (long long i = 0; i < k; i++) sum += cnt[i];
        ans = min(ans, sum);
    }
    cout << ans << "\n";
}