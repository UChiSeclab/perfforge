#include <bits/stdc++.h>
using namespace std;

// Checker functions
void check_high_number_of_tasks(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - High number of tasks!" << endl;
        abort();
    }
}

void check_high_number_of_subtasks(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - High number of subtasks!" << endl;
        abort();
    }
}

void check_large_time_values(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - Time values too large relative to available time!" << endl;
        abort();
    }
}

void check_inefficient_dp_updates(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - Inefficient dynamic programming table updates!" << endl;
        abort();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    long long n, k, m;
    cin >> n >> k >> m;
    
    vector<long long> a(k);
    for (long long& v : a) cin >> v;
    
    // Sort and prepare the prefix sums
    sort(a.begin(), a.end());
    a.push_back(0);
    k++;
    a.insert(a.begin(), 0);
    for (int i = 1; i <= k; i++) a[i] += a[i - 1];
    
    // Check for potential bottlenecks before processing
    check_high_number_of_tasks(n > 40); // n approaching the upper limit
    check_high_number_of_subtasks(k > 40); // k approaching the upper limit
    check_large_time_values(*max_element(a.begin(), a.end()) > m / n); // large time values relative to budget
    
    vector<long long> dp((k + 1) * n, 1e18);
    dp[0] = 0;
    
    for (int i = 0; i < n; i++) {
        auto ndp = dp;
        for (int j = 0; j <= k; j++) {
            for (int l = dp.size() - 1 - j; l >= 0; l--) {
                ndp[l + j] = min(ndp[l + j], dp[l] + a[j]);
            }
        }
        dp = ndp;
    }
    
    cout << upper_bound(dp.begin(), dp.end(), m) - dp.begin() - 1 << endl;
}