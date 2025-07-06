#include <bits/stdc++.h>
using namespace std;

// Inserted checker functions
void check_high_connectivity_invariant(const vector<vector<int>>& dis, int N) {
    int similarWeightCount = 0;
    int maxEdges = N * (N - 1) / 2;
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            if (dis[i][j] == dis[0][1] && dis[i][j] != 0) {
                ++similarWeightCount;
            }
        }
    }
    if (similarWeightCount > maxEdges * 0.8) {
        cerr << "Warning: High connectivity invariant triggered!" << endl;
        abort();
    }
}

void check_few_updates_invariant(int updates, int evaluations, int N) {
    if (updates < evaluations * 0.1 && N == 10) {
        cerr << "Warning: Few updates invariant triggered!" << endl;
        abort();
    }
}

void check_sparse_updates_invariant(const vector<vector<int>>& dis, int N) {
    int longEdgeCount = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            if (dis[i][j] > 50) {
                ++longEdgeCount;
            }
        }
    }
    if (longEdgeCount > N && N == 10) {
        cerr << "Warning: Sparse updates invariant triggered!" << endl;
        abort();
    }
}

void SolveA() {
    long long r, a;
    cin >> a;
    r = 1 << a;
    cout << r << endl;
}

void IFIF(bool v, function<void()> f0) {
    v ? f0() : [] {}();
}

void _Eor(int n, int idx, function<void(int i)> f) {
    IFIF(idx < n, [&]() {
        f(idx);
        _Eor(n, idx + 1, f);
    });
}

void Eor(int n, function<void(int i)> f) { _Eor(n, 0, f); }

void SolveE() {
    int N;
    cin >> N;
    vector<vector<int>> dis(N, vector<int>(N));
    Eor(N * N, [&](int i) { cin >> dis[i / N][i % N]; });
    
    // Call the high connectivity invariant check after reading input
    check_high_connectivity_invariant(dis, N);
    
    int updates = 0;
    Eor(N, [&](int k) {
        Eor(N, [&](int i) {
            Eor(N, [&](int j) {
                IFIF(dis[i][k] + dis[k][j] < dis[i][j],
                     [&]() { dis[i][j] = dis[i][k] + dis[k][j]; ++updates; });
            });
        });
    });
    
    int evaluations = N * N * N;
    // Call the few updates invariant check after the nested loops
    check_few_updates_invariant(updates, evaluations, N);
    
    // Call the sparse updates invariant check
    check_sparse_updates_invariant(dis, N);
    
    int r = 0;
    Eor(N * N, [&](int v) {
        int i = v / N;
        int j = v % N;
        IFIF(dis[i][j] > r, [&]() { r = dis[i][j]; });
    });
    cout << r << endl;
}

int main() {
    SolveE();
    return 0;
}