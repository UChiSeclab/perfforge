#include <bits/stdc++.h>
using namespace std;

// Checker function to detect potential slowdown due to high divisor count
void check_high_divisor_count(long long x, int divisor_count) {
    if (divisor_count > 50) {  // Arbitrary threshold for high divisor count
        cerr << "Warning: High divisor count for x = " << x << " may slow down performance!" << endl;
        abort();
    }
}

// Checker function to detect frequent map operations
void check_frequent_map_operations(const unordered_map<long long, vector<long long>>& mp) {
    for (const auto& entry : mp) {
        if (entry.second.size() > 50) {  // Arbitrary threshold for frequent operations on map
            cerr << "Warning: Frequent map operations for key = " << entry.first << " may slow down performance!" << endl;
            abort();
        }
    }
}

// Checker function for large values of x
void check_large_value_of_x(long long x) {
    if (x > 100000) {  // Given constraint, but large enough to merit a check
        cerr << "Warning: Large value x = " << x << " may lead to performance issues!" << endl;
        abort();
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
    cin >> n;

    for (long long t = 1; t <= n; t++) {
        long long x, y;
        cin >> x >> y;

        check_large_value_of_x(x);  // Check for large value of x

        long long cnt = 0;
        int divisor_count = 0;  // Track divisor count

        for (long long j = 1; j * j <= x; j++) {
            if (x % j == 0) {
                long long ind = lower_bound(mp[j].begin(), mp[j].end(), t - y) - mp[j].begin();
                if (ind == mp[j].size()) cnt++;
                mp[j].push_back(t);
                divisor_count++;  // Increment divisor count

                if (j != x / j) {
                    ind = lower_bound(mp[x / j].begin(), mp[x / j].end(), t - y) - mp[x / j].begin();
                    if (ind == mp[x / j].size()) cnt++;
                    mp[x / j].push_back(t);
                    divisor_count++;  // Increment divisor count
                }
            }
        }

        check_high_divisor_count(x, divisor_count);  // Check for high divisor count
        check_frequent_map_operations(mp);  // Check for frequent map operations

        cout << cnt << '\n';
    }

    return 0;
}