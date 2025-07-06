#include <bits/stdc++.h>
using namespace std;
int N, M;
int A[12], B[12];
int MA[12];
int MB[12];

// Checker function implementations
void check_pair_size_invariant(int N, int M) {
    if (N == 12 && M == 12) {
        cerr << "Warning: pair_size_invariant triggered - maximum pairs may cause slow performance" << endl;
        abort();
    }
}

void check_loop_optimization_invariant(const int MA[], const int MB[], int N, int M) {
    int zeroMA = 0, zeroMB = 0;
    for (int i = 0; i < N; ++i) if (MA[i] == 0) ++zeroMA;
    for (int i = 0; i < M; ++i) if (MB[i] == 0) ++zeroMB;
    if (zeroMA + zeroMB < (N + M) / 2) {
        cerr << "Warning: loop_optimization_invariant triggered - ineffective pruning in loops" << endl;
        abort();
    }
}

void check_large_iteration_invariant(int N, int M) {
    if (N > 6 && M > 6) {
        cerr << "Warning: large_iteration_invariant triggered - large iteration may lead to inefficiency" << endl;
        abort();
    }
}

void solve() {
    int i, j, k, l, r, x, y;
    string s;
    cin >> N >> M;

    // Check pair size invariant after reading inputs
    check_pair_size_invariant(N, M);

    for (i = 0; i < N; i++) {
        cin >> x >> y;
        A[i] = (1 << x) | (1 << y);
    }
    for (i = 0; i < M; i++) {
        cin >> x >> y;
        B[i] = (1 << x) | (1 << y);
    }
    vector<int> CA[12], CB[12];
    int a[2] = {}, b[2] = {};
    
    for (i = 0; i < N; i++)
        for (j = 0; j < M; j++)
            if (__builtin_popcount(A[i] & B[j]) == 1) MA[i] |= 1 << j;
    for (i = 0; i < M; i++)
        for (j = 0; j < N; j++)
            if (__builtin_popcount(B[i] & A[j]) == 1) MB[i] |= 1 << j;

    // Check loop optimization invariant before major loop
    check_loop_optimization_invariant(MA, MB, N, M);

    // Check large iteration loop invariant before entering the loop
    check_large_iteration_invariant(N, M);

    for (i = 0; i < 1200; i++) {
        for (x = 0; x < N; x++)
            if (MA[x] == 0)
                for (y = 0; y < M; y++) MB[y] &= ~(1 << x);
        for (x = 0; x < M; x++)
            if (MB[x] == 0)
                for (y = 0; y < N; y++) MA[y] &= ~(1 << x);
    }

    int cand = 0;
    int cantsure = 0;
    for (i = 0; i < N; i++) {
        int mc = 0;
        for (j = 0; j < M; j++)
            if ((MA[i] & (1 << j)) && (MB[j] & (1 << i))) {
                cand |= A[i] & B[j];
                mc |= A[i] & B[j];
            }
        if (__builtin_popcount(mc) > 1) return (void)printf("-1\n");
    }
    for (j = 0; j < M; j++) {
        int mc = 0;
        for (i = 0; i < N; i++)
            if ((MA[i] & (1 << j)) && (MB[j] & (1 << i))) {
                cand |= A[i] & B[j];
                mc |= A[i] & B[j];
            }
        if (__builtin_popcount(mc) > 1) return (void)printf("-1\n");
    }
    if (__builtin_popcount(cand) > 1) {
        (void)printf("0\n");
    } else if (__builtin_popcount(cand) == 1) {
        for (x = 0; x < 10; x++)
            if (cand & (1 << x)) cout << x << endl;
    } else {
        (void)printf("-1\n");
    }
}

int main(int argc, char** argv) {
    string s;
    int i;
    if (argc == 1) ios::sync_with_stdio(false), cin.tie(0);
    for (i = 0; i < (argc - 1); i++) s += argv[i + 1], s += '\n';
    for (i = 0; i < s.size(); i++) ungetc(s[s.size() - 1 - i], stdin);
    cout.tie(0);
    solve();
    return 0;
}