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

int valid(vector<int>& v1, double num, int k) {
    double pos = 0, neg = 0;
    for (int i = 0; i < (int)(v1.size()); i++) {
        if (com(v1[i], num) == 1)
            pos += (v1[i] - num);
        else if (com(v1[i], num) == 2)
            neg += (num - v1[i]) * 100 / (100 - k);
    }
    return com(neg, pos);
}

// Checkers
void check_accumulator_invariant(int n, int k) {
    if (n > 1000 && k < 30) {
        cerr << "Warning: Performance bottleneck condition triggered - large number of accumulators with low energy transfer percentage!" << endl;
        abort();
    }
}

void check_energy_distribution_invariant(const vector<int>& v1) {
    int max_energy = *max_element(v1.begin(), v1.end());
    int min_energy = *min_element(v1.begin(), v1.end());
    if (max_energy - min_energy > 500) {
        cerr << "Warning: Performance bottleneck condition triggered - high variance in energy distribution!" << endl;
        abort();
    }
}

void check_loss_percentage_invariant(int n, int k) {
    if (k > 70 && n > 500) {
        cerr << "Warning: Performance bottleneck condition triggered - high energy loss percentage with many accumulators!" << endl;
        abort();
    }
}

int main() {
    file();
    fast();

    double n, k;
    cin >> n >> k;
    
    vector<int> v1(n);
    for (int i = 0; i < n; i++) cin >> v1[i];

    // Insert checks after reading input
    check_accumulator_invariant(n, k); // Check for accumulator count vs. loss percentage
    check_energy_distribution_invariant(v1); // Check for energy distribution variance
    check_loss_percentage_invariant(n, k); // Check for high loss percentage with many accumulators

    double start = 0, end = INT_MAX, mid, ans = -1;
    for (int i = 0; i < 1000; i++) {
        mid = (start + end) / 2.0;
        if (valid(v1, mid, k) == 2)
            start = mid;
        else {
            end = mid;
            ans = mid;
        }
    }

    cout << fixed << setprecision(9);
    cout << ans << "\n";
    return 0;
}