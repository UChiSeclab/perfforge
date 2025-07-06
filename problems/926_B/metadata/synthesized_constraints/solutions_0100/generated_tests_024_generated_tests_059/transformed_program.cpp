#include <bits/stdc++.h>
using namespace std;

// Helper function to check for large differences
void check_large_difference(long long len) {
    if (len > 10000) { // Arbitrary threshold
        cerr << "Warning: Performance bottleneck condition triggered - large coordinate difference!" << endl;
        abort();
    }
}

// Helper function to check for a high number of distinct divisors
void check_high_divisors_count(int divisorCount) {
    if (divisorCount > 100) { // Arbitrary threshold
        cerr << "Warning: Performance bottleneck condition triggered - high number of divisors!" << endl;
        abort();
    }
}

// Helper function to check for frequent map updates
void check_frequent_map_updates(int updateCount) {
    if (updateCount > 10000) { // Arbitrary threshold
        cerr << "Warning: Performance bottleneck condition triggered - frequent map updates!" << endl;
        abort();
    }
}

int main() {
    long long n;
    cin >> n;
    vector<long long> v(n);
    for (int i_ = 0; i_ < v.size(); i_++) {
        cin >> v[i_];
    };
    sort(v.begin(), v.end());
    map<long long, long long> cnt, can;
    for (int i = 0; i < n - 1; i++) {
        long long len = v[i + 1] - v[i];
        
        // Check for large differences
        check_large_difference(len);
        
        set<long long> divisors;
        for (long long x = 1; x * x <= len; x++) {
            if (len % x == 0) {
                long long a = len / x;
                long long b = x;
                divisors.insert(a);
                divisors.insert(b);
            }
        }
        
        // Check for high number of divisors
        check_high_divisors_count(divisors.size());
        
        int updateCount = 0;
        for (auto x : divisors) {
            long long now = len / x - 1;
            can[x]++;
            cnt[x] += now;
            updateCount++;
        }

        // Check for frequent map updates
        check_frequent_map_updates(updateCount);
    }
    long long answ = 1e18;
    for (auto i : can) {
        if (i.second == n - 1) {
            answ = min(answ, cnt[i.first]);
        }
    }
    cout << answ;
}