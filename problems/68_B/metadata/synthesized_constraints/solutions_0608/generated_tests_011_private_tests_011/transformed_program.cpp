#include <bits/stdc++.h>
using namespace std;

// Checker functions
void check_accumulator_count_invariant(int n) {
    if (n > 1000) {
        cerr << "Warning: High number of accumulators triggering performance bottleneck!" << endl;
        abort();
    }
}

void check_percent_loss_invariant(int k) {
    if (k > 70) {
        cerr << "Warning: High percent energy loss triggering performance bottleneck!" << endl;
        abort();
    }
}

void check_energy_variance_invariant(const double a[], int n) {
    double max_energy = *max_element(a, a + n);
    double min_energy = *min_element(a, a + n);
    if ((max_energy - min_energy) > 800) {
        cerr << "Warning: Large variance in initial energy levels triggering performance bottleneck!" << endl;
        abort();
    }
}

int n, k;

int ok(double x, double a[]) {
    double z1 = 0, z2 = 0;
    for (int i = 0; i < n; i++) {
        if (x - a[i] > 0) {
            z1 += x - a[i];
        }
        if (x - a[i] < 0) {
            double ans = 1 - (k * (double)1) / 100;
            z2 += (a[i] - x) * ans;
        }
    }
    return z1 <= z2;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    double a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Insert checkers after reading inputs
    check_accumulator_count_invariant(n); // Detects slowdown due to large n
    check_percent_loss_invariant(k);      // Detects slowdown due to high k
    check_energy_variance_invariant(a, n);// Detects slowdown due to large variance

    sort(a, a + n);
    double ans = 0, low = 0, high = 10000;
    int z = 0;
    
    while (low < high) {
        z++;
        double mid = (low + high) / 2;
        if (ok(mid, a)) {
            low = mid;
            ans = mid;
        } else {
            high = mid;
        }
        if (z == 999) {
            break;
        }
    }
    cout << setprecision(12) << ans;
}