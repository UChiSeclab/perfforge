#include <bits/stdc++.h>
using namespace std;

int n, p[1000001 + 1], t[1000001 + 1], d[1000001 + 1], maxi;

// Check for high maximum position
void check_max_position_invariant(int maxi) {
    if (maxi > 900000) {
        cerr << "Warning: Performance bottleneck condition triggered due to high maximum position!" << endl;
        abort();
    }
}

// Check for high power levels
void check_power_level_invariant(int n, const int* p) {
    int highPowerCount = 0;
    for (int i = 0; i <= 1000000; ++i) {
        if (p[i] > 900000) {
            highPowerCount++;
        }
    }
    if (highPowerCount > n / 2) {
        cerr << "Warning: Performance bottleneck condition triggered due to high power levels!" << endl;
        abort();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    
    cin >> n;
    for (int i = 0, a, b; i < n; i++) {
        cin >> a >> b;
        p[a] = b;
        maxi = max(maxi, a);
    }

    // Place checkers after inputs are read, before main computational loops
    check_max_position_invariant(maxi);
    check_power_level_invariant(n, p);

    t[0] = p[0] != 0;
    for (int i = 1; i <= maxi; i++) {
        t[i] = t[i - 1] + (p[i] != 0);
    }
    d[0] = 0;
    for (int i = 1; i <= maxi; i++) {
        if (p[i]) {
            d[i] = t[i - 1];
            if (i - p[i] - 1 >= 0) {
                d[i] -= t[i - p[i] - 1];
                d[i] += d[i - p[i] - 1];
            }
        } else {
            if (i > 0) d[i] = d[i - 1];
        }
    }
    int mini = INT_MAX;
    for (int i = 0; i <= maxi + 1; i++) {
        mini = min(mini, d[i - 1] + t[maxi] - t[i - 1]);
    }
    cout << mini << "\n";
    return 0;
}