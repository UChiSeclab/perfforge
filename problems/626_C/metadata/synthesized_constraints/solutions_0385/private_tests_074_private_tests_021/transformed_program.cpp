#include <bits/stdc++.h>
using namespace std;

// Checker for high frequency of adjustments among students using three-block pieces
void check_high_frequency_adjustments(long long m, long long ans2) {
    if (m > 10000 && ans2 > 10000) { // Thresholds are arbitrary and based on observation
        cerr << "Warning: High frequency of adjustments detected!" << endl;
        abort();
    }
}

// Checker for imbalance between two-block and three-block users
void check_imbalance(long long n, long long m) {
    if (m > n * 10) { // Arbitrary threshold to indicate imbalance
        cerr << "Warning: Imbalance in number of users detected!" << endl;
        abort();
    }
}

// Checker for exhaustion of available heights
void check_exhaustion_of_heights(long long ans2, long long limit) {
    if (ans2 > limit) { // Arbitrary limit based on observation
        cerr << "Warning: Exhaustion of available heights detected!" << endl;
        abort();
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin >> n >> m;

    // Insert checker for imbalance immediately after reading input
    check_imbalance(n, m);

    ans1 = 0;
    ans2 = 0;
    mp[0] = 1;

    while (n != 0 && m != 0) {
        long long b1 = ans1, b2 = ans2;
        while (mp[ans1] == 1) ans1 += 2;
        while (mp[ans2] == 1) ans2 += 3;

        // Insert check for high frequency of adjustments during calculation
        check_high_frequency_adjustments(m, ans2);

        if (ans1 < ans2) {
            mp[ans1] = 1, n--, ans2 = b2;
        } else if (ans1 == ans2) {
            if (n <= m) {
                mp[ans2] = 1, m--, ans1 = b1;
            } else {
                mp[ans1] = 1, n--, ans2 = b2;
            }
        } else {
            mp[ans2] = 1, m--, ans1 = b1;
        }
    }
    
    while (n != 0) {
        while (mp[ans1] == 1) ans1 += 2;
        mp[ans1] = 1;
        n--;
    }
    
    while (m != 0) {
        check_exhaustion_of_heights(ans2, 100000); // Check before updating ans2
        while (mp[ans2] == 1) ans2 += 3;
        mp[ans2] = 1;
        m--;
    }

    cout << max(ans1, ans2);
    return 0;
}