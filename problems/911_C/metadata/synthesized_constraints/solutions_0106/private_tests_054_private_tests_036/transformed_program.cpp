#include <bits/stdc++.h>
using namespace std;

void check_high_iteration_and_set_operations(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - high iteration and set operations!" << endl;
        abort();
    }
}

void check_difficulty_in_achieving_coverage(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - difficulty in achieving full coverage!" << endl;
        abort();
    }
}

void check_dense_period_coverage_requirements(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - dense period coverage requirements!" << endl;
        abort();
    }
}

struct $ {
    $() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
    }
} $;

const int N = 200005;

int main() {
    int k1, k2, k3;
    cin >> k1 >> k2 >> k3;
    
    // Check for potential bottlenecks based on common factors or similar periods
    check_high_iteration_and_set_operations(__gcd(k1, k2) > 1 || __gcd(k2, k3) > 1 || __gcd(k1, k3) > 1);

    for (int x1 = 0; x1 < 20; x1++) {
        for (int x2 = 0; x2 < 20; x2++) {
            for (int x3 = 0; x3 < 20; x3++) {
                set<int> s;
                int m = max({x1, x2, x3});
                for (int i = x1; i <= 200; i += k1) {
                    if (i >= m) s.insert(i);
                }
                for (int i = x2; i <= 200; i += k2) {
                    if (i >= m) s.insert(i);
                }
                for (int i = x3; i <= 200; i += k3) {
                    if (i >= m) s.insert(i);
                }
                check_difficulty_in_achieving_coverage(s.size() < 200 - m + 1);
                if (s.size() == 200 - m + 1) {
                    cout << "YES" << endl;
                    return 0;
                }
            }
        }
    }
    
    // Check if periods are dense and close in value
    check_dense_period_coverage_requirements(max({k1, k2, k3}) < 10);
    
    cout << "NO" << endl;
    return 0;
}