#include <bits/stdc++.h>
using namespace std;

// Checker function for Invariant #1
void check_high_repair_vs_break(long long x, long long y, const multiset<long long>& v) {
    if (y > x && !v.empty()) {
        cerr << "Warning: Performance bottleneck condition triggered - repair value is greater than break value." << endl;
        abort();
    }
}

// Checker function for Invariant #2
void check_repeated_multiset_operations(const multiset<long long>& v) {
    if (v.size() > 50) { // Assuming if more than half the doors remain active, it's a bottleneck
        cerr << "Warning: Performance bottleneck condition triggered - large multiset operations." << endl;
        abort();
    }
}

// Checker function for Invariant #3
void check_balance_between_x_and_y(long long x, long long y) {
    if (x <= y) {
        cerr << "Warning: Performance bottleneck condition triggered - inefficient break vs. repair values." << endl;
        abort();
    }
}

signed main() {
    long long n;
    cin >> n;
    long long x, y;
    cin >> x >> y;
    multiset<long long> v;
    for (long long i = 0; i < n; i++) {
        long long xx;
        cin >> xx;
        if (xx <= x) {
            v.insert(xx);
        }
    }

    // Insert checks after reading inputs and initial filtering
    check_balance_between_x_and_y(x, y);
    check_high_repair_vs_break(x, y, v);

    if (x > y) {
        cout << n;
        return 0;
    }

    long long ans = 0;
    while (v.size() > 0) {
        auto it = v.end();
        it--;
        v.erase(it);
        ans++;

        // Check for repeated multiset operations
        check_repeated_multiset_operations(v);

        if (v.size() == 0) {
            break;
        }
        it = v.end();
        it--;
        if (*it + y <= x) {
            long long q = *it;
            v.erase(it);
            v.insert(q + y);
        } else {
            v.erase(it);
        }
    }
    cout << ans;
}