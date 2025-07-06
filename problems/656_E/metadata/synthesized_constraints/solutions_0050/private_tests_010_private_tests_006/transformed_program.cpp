#include <bits/stdc++.h>
using namespace std;

// Checker function for high N value
void check_iteration_invariant(int N) {
    if (N > 9) {  // Since the maximum N is 10, check when N is close to the limit.
        cerr << "Warning: Performance bottleneck triggered due to high N value!" << endl;
        abort();
    }
}

// Checker function for high edge weights
void check_edge_weight_invariant(const vector<vector<int>>& dis, int N) {
    int updateCount = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (dis[i][j] > 50) {  // Arbitrary threshold for high weights.
                updateCount++;
            }
        }
    }
    if (updateCount > (N * N) / 2) {  // If more than half are high weights.
        cerr << "Warning: Performance bottleneck triggered due to high edge weights!" << endl;
        abort();
    }
}

void SolveA() {
    long long r, a;
    cin >> a;
    r = 1 << a;
    cout << r << endl;
}

void EF(bool v, function<void()> f0) {
    v ? f0() : [] {}();
}

void _Eor(int n, int idx, function<void(int i)> f) {
    EF(idx < n, [&]() {
        f(idx);
        _Eor(n, idx + 1, f);
    });
}

void Eor(int n, function<void(int i)> f) {
    _Eor(n, 0, f);
}

void SolveE() {
    int N;
    cin >> N;
    
    // Check for iteration invariant
    check_iteration_invariant(N);
    
    vector<vector<int>> dis(N, vector<int>(N));
    Eor(N * N, [&](int i) { cin >> dis[i / N][i % N]; });

    // Check for edge weight invariant after input
    check_edge_weight_invariant(dis, N);

    Eor(N, [&](int k) {
        Eor(N, [&](int i) {
            Eor(N, [&](int j) {
                EF(dis[i][k] + dis[k][j] < dis[i][j],
                   [&]() { dis[i][j] = dis[i][k] + dis[k][j]; });
            });
        });
    });
    
    int r = 0;
    Eor(N * N, [&](int v) {
        int i = v / N;
        int j = v % N;
        EF(dis[i][j] > r, [&]() { r = dis[i][j]; });
    });
    cout << r << endl;
}

int main() {
    SolveE();
    return 0;
}