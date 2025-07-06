#include <bits/stdc++.h>
using namespace std;

// Checker functions
void check_high_surplus_management(int n, int k, const vector<int>& a) {
    int high_surplus_count = count_if(a.begin(), a.end(), [](int energy) { return energy > 500; });
    if (high_surplus_count > 0.5 * n && k > 50) {
        cerr << "Warning: High surplus management condition triggered!" << endl;
        abort();
    }
}

void check_deficit_surplus_balance(int n, const vector<int>& a) {
    int balance_threshold = 200;
    int deficit_count = count_if(a.begin(), a.end(), [balance_threshold](int energy) { return energy < balance_threshold; });
    int surplus_count = count_if(a.begin(), a.end(), [balance_threshold](int energy) { return energy > balance_threshold; });
    if (deficit_count > 0.3 * n && surplus_count > 0.3 * n) {
        cerr << "Warning: Deficit and surplus balance condition triggered!" << endl;
        abort();
    }
}

void check_energy_distribution(int n, const vector<int>& a) {
    if (*max_element(a.begin(), a.end()) - *min_element(a.begin(), a.end()) > 700) {
        cerr << "Warning: Wide distribution of energy levels!" << endl;
        abort();
    }
}

void check_transfer_efficiency(int k) {
    if (k > 75) {
        cerr << "Warning: Low energy transfer efficiency triggered!" << endl;
        abort();
    }
}

int n, k, a[10001];
double f;

bool can(double x) {
    int L = 0, R = n - 1;
    double surplus = 0;
    while (L <= R) {
        double deficit = x - a[L++];
        if (deficit < 1e-9) return true;
        if (surplus > 0) {
            double transfer = min(surplus, deficit / f);
            deficit -= transfer * f;
            surplus -= transfer;
        }
        if (deficit < 1e-9) continue;
        while (L <= R) {
            surplus += a[R--] - x;
            if (surplus < 0) return false;
            double transfer = min(surplus, deficit / f);
            deficit -= transfer * f;
            surplus -= transfer;
            if (deficit < 1e-9) break;
        }
        if (deficit > 1e-9) return false;
    }
    return surplus >= -1e-9;
}

int main() {
    while (scanf("%d %d", &n, &k) != EOF) {
        for (int i = 0; i < n; i++) scanf("%d", &a[i]);
        
        // Convert array to vector for using with standard algorithms
        vector<int> energyLevels(a, a + n);

        // Check performance-characterizing invariants
        check_high_surplus_management(n, k, energyLevels);
        check_deficit_surplus_balance(n, energyLevels);
        check_energy_distribution(n, energyLevels);
        check_transfer_efficiency(k);

        sort(a, a + n);
        f = 1.0 - k / 100.0;
        double lo = 0, hi = 1e9;
        for (int i = 0; i < 1000; i++) {
            double mid = (lo + hi) / 2.0;
            if (can(mid))
                lo = mid;
            else
                hi = mid;
        }
        printf("%.12lf\n", (lo + hi) / 2.0);
    }
}