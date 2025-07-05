#include <bits/stdc++.h>
using namespace std;

void file() {}
void fast() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(NULL);
}

int com(double a, double b) {
    if (abs(a - b) <= 1e-6)
        return 0;
    else if (a > b)
        return 1;
    else
        return 2;
}

int valid(vector<long long>& v1, double num, long long k) {
    double pos = 0, neg = 0;
    for (int i = 0; i < (int)(v1.size()); i++) {
        if (com(v1[i], num) == 1)
            pos += (v1[i] - num);
        else if (com(v1[i], num) == 2)
            neg += (num - v1[i]) * 100 / (100 - k);
    }
    return com(neg, pos);
}

// Phase 3 - Invariant check functions
void check_iterations_invariant(size_t loopIterations, size_t threshold) {
    if (loopIterations > threshold) {
        cerr << "Warning: Performance bottleneck due to high number of iterations in energy redistribution!" << endl;
        abort();
    }
}

void check_comparisons_invariant(size_t comparisonCount, size_t threshold) {
    if (comparisonCount > threshold) {
        cerr << "Warning: Performance bottleneck due to excessive comparisons in binary search!" << endl;
        abort();
    }
}

void check_energy_values_invariant(const vector<long long>& energies, long long maxEnergyValue) {
    for (const auto& energy : energies) {
        if (energy > maxEnergyValue) {
            cerr << "Warning: Performance bottleneck due to large energy values causing complex calculations!" << endl;
            abort();
        }
    }
}

int main() {
    file();
    fast();
    
    long long n, k;
    cin >> n >> k;
    vector<long long> v1(n);
    for (int i = 0; i < n; i++) cin >> v1[i];

    // Check for large energy values
    check_energy_values_invariant(v1, 1000); // Max energy value threshold based on problem constraints

    double start = 0, end = 1e12, mid, ans = -1;
    size_t totalComparisons = 0; // Track the number of comparisons
    
    for (int i = 0; i < 1000; i++) {
        if (com(start, end) == 1) break;
        mid = (start + end) / 2.0;
        
        // Count comparisons in binary search
        totalComparisons++;
        
        if (valid(v1, mid, k) == 2)
            start = mid;
        else {
            end = mid;
            ans = mid;
        }
    }

    // Check for excessive comparisons in binary search
    check_comparisons_invariant(totalComparisons, 150000);  // Example threshold

    cout << fixed << setprecision(9);
    cout << ans << "\n";
    return 0;
}