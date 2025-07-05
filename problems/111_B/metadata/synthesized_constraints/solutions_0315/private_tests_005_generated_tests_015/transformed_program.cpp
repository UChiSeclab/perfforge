#include <bits/stdc++.h>
using namespace std;

unordered_map<int, vector<int>> mp;

void check_high_divisor_count(int divisorCount) {
    if (divisorCount > 100) { // Assuming 100 as a broad threshold for high divisor count.
        cerr << "Warning: Performance bottleneck condition triggered due to high number of divisors!" << endl;
        abort();
    }
}

void check_frequent_access(int vectorSize) {
    if (vectorSize > 100) { // Assuming 100 as a threshold for large vector size.
        cerr << "Warning: Performance bottleneck condition triggered due to frequent access to large data structures!" << endl;
        abort();
    }
}

void check_large_y(int y, int queryIndex) {
    if (y > queryIndex / 2) { // Assuming if y is more than half the query index, it's large.
        cerr << "Warning: Performance bottleneck condition triggered due to large 'y' value!" << endl;
        abort();
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    for (int t = 1; t <= n; t++) {
        int x, y;
        cin >> x >> y;

        // Check for large y
        check_large_y(y, t);

        int cnt = 0;
        int divisorCount = 0; // To keep track of the number of divisors

        for (int j = 1; j * j <= x; j++) {
            if (x % j == 0) {
                divisorCount++;
                int ind = lower_bound(mp[j].begin(), mp[j].end(), t - y) - mp[j].begin();
                if (ind == mp[j].size()) cnt++;
                mp[j].push_back(t);

                // Check frequent access
                check_frequent_access(mp[j].size());

                if (j != x / j) {
                    divisorCount++;
                    ind = lower_bound(mp[x / j].begin(), mp[x / j].end(), t - y) - mp[x / j].begin();
                    if (ind == mp[x / j].size()) cnt++;
                    mp[x / j].push_back(t);

                    // Check frequent access
                    check_frequent_access(mp[x / j].size());
                }
            }
        }

        // Check for high number of divisors
        check_high_divisor_count(divisorCount);

        cout << cnt << '\n';
    }
    return 0;
}