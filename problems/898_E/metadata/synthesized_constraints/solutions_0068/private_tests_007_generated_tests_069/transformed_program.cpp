#include <bits/stdc++.h>
using namespace std;

long long sq(long long m) {
    long long left = 0, right = m + 1;
    while (right - left > 1ll) {
        long long mid = (left + right) / 2;
        if (mid * mid <= m) {
            left = mid;
        } else {
            right = mid;
        }
    }
    return left;
}

// Check for large values in the input array
void check_large_values_invariant(const vector<long long>& a, long long n) {
    int largeValueThreshold = 1e8; // Arbitrary threshold for large values
    int largeValueCount = 0;
    for (long long value : a) {
        if (value >= largeValueThreshold) {
            largeValueCount++;
        }
    }
    // Trigger if more than half of the piles have large values
    if (largeValueCount > n / 2) {
        cerr << "Warning: large_values_invariant triggered - excessive number of large-value piles" << endl;
        abort();
    }
}

signed main() {
    long long n;
    cin >> n;
    vector<long long> a(n);
    
    for (long long i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Integrate the performance invariant check
    check_large_values_invariant(a, n);

    long long num = 0;
    for (long long i = 0; i < n; i++) {
        long long m = sq(a[i]);
        if (m * m == a[i]) {
            num += 1;
        }
    }
    if (num == n / 2) {
        cout << 0 << endl;
    } else if (num > n / 2) {
        vector<long long> vars;
        for (long long i = 0; i < n; i++) {
            long long m = sq(a[i]);
            if (m * m == a[i]) {
                if (a[i] == 0) {
                    vars.push_back(2);
                } else {
                    vars.push_back(1);
                }
            }
        }
        sort(vars.begin(), vars.end());
        long long res = 0;
        for (long long i = 0; i < num - n / 2; i++) {
            res += vars[i];
        }
        cout << res << endl;
    } else {
        vector<long long> vars;
        for (long long i = 0; i < n; i++) {
            long long m = sq(a[i]);
            if (m * m != a[i]) {
                vars.push_back(min(a[i] - m * m, (m + 1) * (m + 1) - a[i]));
            }
        }
        sort(vars.begin(), vars.end());
        long long res = 0;
        for (long long i = 0; i < n / 2 - num; i++) {
            res += vars[i];
        }
        cout << res << endl;
    }
    return 0;
}