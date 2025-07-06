#include <bits/stdc++.h>
using namespace std;

// Checker functions for performance invariants
void check_high_price_invariant(int K) {
    if (K > 450) { // Arbitrarily chosen threshold close to the maximum constraint
        cerr << "Warning: high_price_invariant triggered - K is large, increasing loop iterations!" << endl;
        abort();
    }
}

void check_large_dp_space_invariant(int N, int K) {
    if (N * K > 200000) { // Threshold for combined input size leading to large DP space
        cerr << "Warning: large_dp_space_invariant triggered - Large DP state space due to high N and K!" << endl;
        abort();
    }
}

void check_frequent_updates_invariant(int K) {
    if (K > 450) { // Check before entering the heavy loop structure
        cerr << "Warning: frequent_updates_invariant triggered - High K causing frequent DP updates!" << endl;
        abort();
    }
}

vector<vector<vector<bool>>> dpArr;

int main(int argc, char const *argv[]) {
    int N, K;
    cin >> N >> K;

    // Insert checks after reading inputs
    check_high_price_invariant(K);
    check_large_dp_space_invariant(N, K);

    vector<int> coin(N + 1);
    dpArr = vector<vector<vector<bool>>>(N + 1);

    for (int i = 1; i <= N; ++i) {
        cin >> coin[i];
    }

    for (int i = 0; i < N + 1; ++i) {
        dpArr[i] = vector<vector<bool>>(K + 1, vector<bool>(K + 1, false));
        dpArr[i][0][0] = true;
    }

    // Insert check before entering the heavy loop structure
    check_frequent_updates_invariant(K);

    for (int i = 1; i < N + 1; ++i) {
        for (int k = 0; k < K + 1; ++k) {
            for (int x = 0; x <= k; ++x) {
                dpArr[i][k][x] = dpArr[i - 1][k][x];
                if (k >= coin[i]) {
                    dpArr[i][k][x] = dpArr[i][k][x] || dpArr[i - 1][k - coin[i]][x];
                    if (x >= coin[i]) {
                        dpArr[i][k][x] = dpArr[i][k][x] || dpArr[i - 1][k - coin[i]][x - coin[i]];
                    }
                }
            }
        }
    }

    set<int> A;
    for (int x = 0; x < K + 1; ++x) {
        if (dpArr[N][K][x]) A.insert(x);
    }

    cout << A.size() << endl;
    for (set<int>::iterator i = A.begin(); i != A.end(); ++i) {
        cout << *i << ' ';
    }
    cout << endl;
    return 0;
}