#include <bits/stdc++.h>
using namespace std;

// Checker functions based on performance-characterizing invariants
void check_large_accumulators_invariant(int n) {
    if (n > 5000) {
        cerr << "Warning: Performance bottleneck condition triggered - large number of accumulators!" << endl;
        abort();
    }
}

void check_energy_variance_invariant(const vector<double>& v) {
    double max_energy = *max_element(v.begin(), v.end());
    double min_energy = *min_element(v.begin(), v.end());
    if ((max_energy - min_energy) > 800) {
        cerr << "Warning: Performance bottleneck condition triggered - high variance in initial energy levels!" << endl;
        abort();
    }
}

void check_high_loss_percentage_invariant(int k) {
    if (k > 75) {
        cerr << "Warning: Performance bottleneck condition triggered - high percentage of energy loss!" << endl;
        abort();
    }
}

bool teste(vector<double> v, double meio, int k) {
    int source = 1;
    for (int i = 0; i < v.size(); i++) {
        double qt = ((meio - v[i]) * 100) / k;
        while (qt > 0) {
            if (source == v.size()) return false;
            if (v[source] > meio) {
                double aux = min({qt, v[source] - meio});
                qt -= aux;
                v[source] -= aux;
            }
            if (qt > 0) source++;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;

    // Perform checks based on invariants
    check_large_accumulators_invariant(n);
    check_high_loss_percentage_invariant(k);

    k = 100 - k;
    vector<double> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    // Perform variance check after reading energy levels
    check_energy_variance_invariant(v);

    sort(v.begin(), v.end());
    double l = 0, r = 1e8, meio, res;
    for (int i = 0; i < 1000; i++) {
        meio = (l + r) / 2;
        if (teste(v, meio, k)) {
            res = meio;
            l = meio;
        } else
            r = meio;
    }
    cout << fixed << setprecision(9) << res << '\n';
    return 0;
}