#include <bits/stdc++.h>
using namespace std;

// Checker for large maximum position value
void check_large_position_invariant(long long int max_right) {
    if (max_right > 900000) {
        cerr << "Warning: Performance bottleneck condition triggered - large maximum position value!" << endl;
        abort();
    }
}

// Checker for dense activation of beacons
void check_dense_activation_invariant(long long int n_actual_beacons, long long int n_effective_beacons) {
    if (static_cast<double>(n_effective_beacons) / n_actual_beacons > 0.8) {
        cerr << "Warning: Performance bottleneck condition triggered - dense activation of beacons!" << endl;
        abort();
    }
}

// Checker for excessive array operations
void check_array_operation_invariant(long long int max_right) {
    if (max_right > 900000) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive array operations!" << endl;
        abort();
    }
}

long long int no_of_ones_on_right[1000010];
long long int minimum_destroyed[1000010];
long long int power[1000010] = {0};

int main() {
    ios_base::sync_with_stdio(false);
    long long int n, a, b, max_right = 0, n_right, n_destroyed;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        power[a] = b;
        max_right = max(max_right, a);
    }

    // Check the large position and array operation invariants after computing max_right
    check_large_position_invariant(max_right);
    check_array_operation_invariant(max_right);

    n_right = 0;
    long long int n_effective_beacons = 0;
    for (int i = max_right; i >= 0; i--) {
        no_of_ones_on_right[i] = n_right;
        if (power[i] > 0) {
            n_right++;
            n_effective_beacons++;
        }
    }

    // Check dense activation invariant after counting effective beacons
    check_dense_activation_invariant(n, n_effective_beacons);

    minimum_destroyed[0] = 0;
    for (int i = 1; i <= max_right; i++) {
        if (power[i] > 0) {
            if (i - power[i] - 1 < 0) {
                minimum_destroyed[i] = n_right - no_of_ones_on_right[i] - 1;
            } else {
                minimum_destroyed[i] = 
                    (no_of_ones_on_right[max(0LL, i - power[i] - 1)] - no_of_ones_on_right[i] - 1) +
                    minimum_destroyed[max(0LL, i - power[i] - 1)];
            }
        } else {
            minimum_destroyed[i] = minimum_destroyed[i - 1];
        }
    }

    long long int ans = LONG_MAX;
    for (int i = 0; i <= max_right; i++) {
        ans = min(ans, minimum_destroyed[i] + no_of_ones_on_right[i]);
    }
    cout << ans << '\n';
    return 0;
}