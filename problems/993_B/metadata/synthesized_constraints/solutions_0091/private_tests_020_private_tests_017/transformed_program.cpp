#include <bits/stdc++.h>
using namespace std;

// Checker function for high iteration count in nested loops
void check_high_iteration_count(int N, int M) {
    if (N >= 10 && M >= 10) {
        cerr << "Warning: Performance bottleneck due to high iteration count in nested loops!" << endl;
        abort();
    }
}

// Checker function for extensive bit manipulation
void check_bit_manipulation(int *MA, int *MB, int N, int M) {
    int activeBitsA = 0, activeBitsB = 0;
    for (int i = 0; i < N; ++i) {
        activeBitsA += __builtin_popcount(MA[i]);
    }
    for (int j = 0; j < M; ++j) {
        activeBitsB += __builtin_popcount(MB[j]);
    }
    if (activeBitsA > 10 * N || activeBitsB > 10 * M) {
        cerr << "Warning: Performance bottleneck due to extensive bit manipulation!" << endl;
        abort();
    }
}

// Checker function for redundant loop executions
void check_redundant_loop_executions(int iterationCount) {
    if (iterationCount > 1000) {
        cerr << "Warning: Performance bottleneck due to redundant loop executions!" << endl;
        abort();
    }
}

int N, M;
int A[12], B[12];
int MA[12];
int MB[12];

void solve() {
    int i, j, k, l, r, x, y;
    string s;
    cin >> N >> M;
    
    // Check for high iteration count in nested loops
    check_high_iteration_count(N, M);
    
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
    
    for (i = 0; i < N; i++) {
        int cand = 0;
        for (j = 0; j < M; j++) {
            if (A[i] == B[j]) continue;
            if (__builtin_popcount(A[i] & B[j]) == 1) {
                CA[i].push_back(j);
                MA[i] |= 1 << j;
            }
        }
    }
    for (i = 0; i < M; i++) {
        int cand = 0;
        for (j = 0; j < N; j++) {
            if (B[i] == A[j]) continue;
            if (__builtin_popcount(B[i] & A[j]) == 1) {
                CB[i].push_back(j);
                MB[i] |= 1 << j;
            }
        }
    }
    
    int num = 0;
    int ret = 0;
    int iterationCount = 0;
    for (i = 0; i < 1200; i++) {
        iterationCount++;
        for (x = 0; x < N; x++)
            if (MA[x] == 0) {
                for (y = 0; y < M; y++) MB[y] &= ~(1 << x);
            }
        for (x = 0; x < M; x++)
            if (MB[x] == 0) {
                for (y = 0; y < N; y++) MA[y] &= ~(1 << x);
            }
    }
    
    // Check for redundant loop executions
    check_redundant_loop_executions(iterationCount);
    
    // Check for extensive bit manipulation
    check_bit_manipulation(MA, MB, N, M);
    
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
    for (i = 0; i < (s.size()); i++) ungetc(s[s.size() - 1 - i], stdin);
    cout.tie(0);
    solve();
    return 0;
}