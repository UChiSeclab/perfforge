#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-9;
double a[10111], k;
int n;

// Checker functions
void check_accumulator_count_invariant(int n) {
    if (n > 1000) {  // Assuming a threshold for demonstration
        cerr << "Warning: Performance bottleneck - large number of accumulators!" << endl;
        abort();
    }
}

void check_energy_distribution_invariant() {
    double max_energy = *max_element(a, a + n);
    double min_energy = *min_element(a, a + n);
    if (max_energy - min_energy > 500) {  // Threshold for unbalanced distribution
        cerr << "Warning: Performance bottleneck - highly unbalanced energy distribution!" << endl;
        abort();
    }
}

void check_iteration_count_invariant(int iterationCount) {
    if (iterationCount > 5000) {  // Fixed number used in the original code
        cerr << "Warning: Performance bottleneck - excessive iteration count!" << endl;
        abort();
    }
}

// Function to check if it's possible to achieve 'x' energy level
bool pos(double x) {
    double s = 0.0;
    for (int i = 0; i < n; i++) {
        if (a[i] > x) {
            s -= (a[i] - x) * (100 - k) * 0.01;
        } else
            s += (x - a[i]);
    }
    if (s < 0)
        return true;
    else
        return false;
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[i];

    // Insert checks after input
    check_accumulator_count_invariant(n);
    check_energy_distribution_invariant();

    int cnt = 5000;
    check_iteration_count_invariant(cnt);  // Check fixed iteration count

    double lo = 0, hi = 1000.0, mid;
    while (cnt--) {
        mid = (lo + hi) / 2.0;
        if (pos(mid))
            lo = mid;
        else
            hi = mid;
    }
    printf("%.10f\n", hi);
    return 0;
}