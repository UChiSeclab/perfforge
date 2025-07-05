#include <bits/stdc++.h>
using namespace std;

int memo[(int)1e6 + 1000], a[(int)1e6 + 1000];

void check_loop_iteration_invariant(int max_position) {
    if (max_position >= 1000000) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive loop iterations due to max_position!" << endl;
        abort();
    }
}

void check_sparse_array_invariant(int beacon_positions[], int size) {
    int gap_threshold = 1000; // Arbitrary threshold for large gaps
    for (int i = 1; i < size; ++i) {
        if (beacon_positions[i] - beacon_positions[i - 1] > gap_threshold) {
            cerr << "Warning: Performance bottleneck condition triggered - large gaps between beacon positions!" << endl;
            abort();
        }
    }
}

void check_memoization_invariant(int beacon_positions[], int power_levels[], int size) {
    for (int i = 0; i < size; ++i) {
        if (power_levels[i] > 100000 && beacon_positions[i] > 500000) { // Arbitrary thresholds
            cerr << "Warning: Performance bottleneck condition triggered - inefficient memoization due to large power levels!" << endl;
            abort();
        }
    }
}

int main() {
    int n, to = 0;
    cin >> n;
    vector<int> beacon_positions(n);
    vector<int> power_levels(n);
    memset(a, -1, sizeof a);

    for (int i = 0; i < n; i++) {
        int tmp, power;
        cin >> tmp >> power;
        beacon_positions[i] = tmp;
        power_levels[i] = power;
        tmp++;
        a[tmp] = power;
        to = max(to, tmp);
    }

    // Insert checkers after reading inputs and computing `to`
    check_loop_iteration_invariant(to);
    check_sparse_array_invariant(beacon_positions.data(), n);
    check_memoization_invariant(beacon_positions.data(), power_levels.data(), n);

    for (int i = 1; i < to + 1; i++)
        if (a[i] == -1)
            memo[i] = memo[i - 1];
        else
            memo[i] = memo[(i - a[i] - 1 >= 0 ? i - a[i] - 1 : 0)] + 1;

    int mx = memo[to];
    for (int i = 1; i < to + 1; i++) {
        mx = max(mx, memo[i - 1] + 1);
    }
    cout << (mx == memo[to] ? n - mx : n + 1 - mx) << endl;
}