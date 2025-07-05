#include <bits/stdc++.h>
using namespace std;

// Checker for small base exponentiation
void check_small_base_invariant(long long w) {
    if (w <= 3) {
        cerr << "Warning: Performance bottleneck due to small base w!" << endl;
        abort();
    }
}

// Checker for large search space
void check_large_search_space(long long w, long long m) {
    if (w <= 3 && m > 1e8) {
        cerr << "Warning: Large search space due to small w and large m!" << endl;
        abort();
    }
}

// Checker for high iteration count
void check_high_iteration_count(long long w) {
    if (w <= 3) {
        cerr << "Warning: High iteration count likely due to small base w!" << endl;
        abort();
    }
}

int main() {
    long long w, m;
    cin >> w >> m;
    
    // Insert checks after reading inputs
    check_small_base_invariant(w);
    check_large_search_space(w, m);
    check_high_iteration_count(w);
    
    if (w == 2) {
        cout << "YES";
        return 0;
    }
    
    vector<pair<long long, long long>> x;
    long long lim = 1;
    while ((lim <= m) and (lim <= (1e18 / w))) lim *= w;
    if (lim <= (1e18 / w)) lim *= w;
    
    for (long long mask = 0; mask <= (1ll << 30); mask++) {
        long long val = 0;
        bool flg = true;
        for (long long j = 0; j <= 30; j++) {
            if ((mask & (1ll << j)) != 0) {
                long long ex = pow(w, j);
                if (val > lim - ex) {
                    flg = false;
                    break;
                }
                val += ex;
            }
        }
        if (flg == false) break;
        x.push_back({val, mask});
    }
    sort(x.begin(), x.end());
    
    for (long long y = 0; y <= (1ll << 30); y++) {
        long long yval = 0;
        bool flg = true;
        for (long long j = 0; j <= 30; j++) {
            if ((y & (1ll << j)) != 0) {
                long long ex = pow(w, j);
                if (yval > m) {
                    flg = false;
                    break;
                }
                yval += ex;
            }
        }
        if (flg == false) break;
        auto it = lower_bound(x.begin(), x.end(), make_pair(m + yval, -1ll));
        if (it == x.end()) continue;
        if ((*it).first != m + yval) continue;
        if (((*it).second & y) != 0) continue;
        
        cout << "YES";
        return 0;
    }
    
    cout << "NO";
    return 0;
}