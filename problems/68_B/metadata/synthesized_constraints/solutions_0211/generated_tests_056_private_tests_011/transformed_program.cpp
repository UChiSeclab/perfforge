#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 10004;
int a[MAX_N];

void check_input_size_and_variance(int n, vector<int>& a) {
    int max_energy = *max_element(a.begin(), a.end());
    int min_energy = *min_element(a.begin(), a.end());
    if (n > 9000 && (max_energy - min_energy) > 500) {
        cerr << "Warning: Performance bottleneck due to large input size and high energy variance!" << endl;
        abort();
    }
}

void check_energy_distribution(vector<int>& a) {
    int max_energy = *max_element(a.begin(), a.end());
    int count_below_half_max = count_if(a.begin(), a.end(), [&](int energy) { return energy < max_energy / 2; });
    if (count_below_half_max > a.size() / 2) {
        cerr << "Warning: High number of accumulators with low energy leading to slow execution!" << endl;
        abort();
    }
}

void check_loss_rate(int k) {
    if (k > 80) {
        cerr << "Warning: High energy loss rate causing potential performance degradation!" << endl;
        abort();
    }
}

void check_binary_search_iterations(int n, double pod, double sum) {
    if (pod > sum * 1.1 && n > 9000) {
        cerr << "Warning: Excessive binary search iterations due to pod exceeding sum!" << endl;
        abort();
    }
}

int main() {
    int n, k;
    double sum = 0;
    cin >> n >> k;
    vector<int> energy_levels(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        energy_levels[i] = a[i];
        sum += a[i];
    }

    check_input_size_and_variance(n, energy_levels); // Check for large input size and energy variance
    check_energy_distribution(energy_levels); // Check energy distribution variance
    check_loss_rate(k); // Check the loss rate invariant

    double left = 0;
    double right = 1e6;
    for (int i = 0; i < 10000; i++) {
        double middle = (left + right) / 2;
        double pod = middle * n;
        for (int i = 0; i < n; i++) {
            if (a[i] < middle) {
                pod += (middle - a[i]) * ((double)100 / (double)(100 - k) - (double)1);
            }
        }
        check_binary_search_iterations(n, pod, sum); // Check during binary search iterations
        if (pod > sum)
            right = middle;
        else
            left = middle;
    }
    cout << fixed << setprecision(10) << left;
    return 0;
}