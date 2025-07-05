#include <bits/stdc++.h>
using namespace std;

int n, m;

// Checker functions for performance bottlenecks

void check_large_m_invariant(int m) {
    if (m > 500000) { // A threshold slightly below the maximum constraint to detect potential slowdowns
        cerr << "Warning: Performance bottleneck condition triggered due to large m!" << endl;
        abort();
    }
}

void check_large_range_invariant(int mx1, int mx2) {
    if (max(mx1, mx2) > 1500000) { // Threshold chosen to catch large ranges leading to slow execution
        cerr << "Warning: Performance bottleneck condition triggered due to large range of potential tower heights!" << endl;
        abort();
    }
}

int main() {
    scanf("%d %d", &n, &m);

    // Perform initial checks after reading inputs
    check_large_m_invariant(m);

    int mx1 = n * 2, mx2 = m * 3;
    map<int, int> mp;

    // Populate map for two-block towers
    for (int i = 2; i <= n * 2; i += 2) {
        mp[i]++;
    }

    // Populate map for three-block towers
    for (int j = 3; j <= m * 3; j += 3) {
        mp[j]++;
    }

    // Check the range before entering the loop
    check_large_range_invariant(mx1, mx2);

    // Resolve duplicate heights
    for (int i = 1; i <= max(mx1, mx2); i++) {
        if (mp[i] > 1) {
            if (mx1 + 2 < mx2 + 3) {
                mx1 += 2;
                mp[mx1]++;
            } else {
                mx2 += 3;
                mp[mx2]++;
            }
        }
    }

    printf("%d\n", max(mx1, mx2));
    return 0;
}