#include <bits/stdc++.h>
using namespace std;

// Checker Functions
void check_large_range_iteration(int n) {
    if (n > 1500) {
        cerr << "Warning: Large range iteration may cause performance slowdown!" << endl;
        abort();
    }
}

void check_frequent_boolean_checks(int totalChecks, int threshold = 1000000) {
    if (totalChecks > threshold) {
        cerr << "Warning: Frequent checks on boolean arrays may cause performance slowdown!" << endl;
        abort();
    }
}

void check_nested_loop_iterations(int n, int pos, int threshold = 1500) {
    if (n > threshold && pos > threshold) {
        cerr << "Warning: Nested loop iterations may cause performance slowdown!" << endl;
        abort();
    }
}

void solve() {
    int n;
    cin >> n;
    check_large_range_iteration(n); // Check for large range iteration potential

    vector<int> v[101010];
    bool res[101010] = {false};

    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        v[abs(a)].push_back(i);
    }

    long long ans = 0;
    int totalChecks = 0; // Track total checks for boolean check invariant

    for (int i = 0; i <= 100005; ++i) {
        int allHave = 0;
        for (int j = 0; j < n; ++j) {
            ++totalChecks; // Increment check count
            if (res[j]) ++allHave;
        }
        
        for (int pos : v[i]) {
            check_nested_loop_iterations(n, pos); // Check nested loop iterations
            int invPositive = 0;
            for (int j = pos + 1; j < n; ++j) {
                ++totalChecks; // Increment check count
                if (res[j]) ++invPositive;
            }
            ans += min(invPositive, allHave - invPositive);
            res[pos] = true;
        }
    }
    check_frequent_boolean_checks(totalChecks); // Check frequent boolean array checks

    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cout << fixed;
    cout.precision(10);
    int t = 1;
    while (t--) solve();
    return 0;
}