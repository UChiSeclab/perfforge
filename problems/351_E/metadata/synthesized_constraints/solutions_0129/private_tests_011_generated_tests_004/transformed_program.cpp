#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e15;
const long long mod = 1000 * 1000 * 1000 + 7;
const int maxn = 2010;
long long DP[2][maxn];

// Function to check sorting complexity
void check_sort_complexity(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - high sorting operations!" << endl;
        abort();
    }
}

// Function to check grouping complexity
void check_grouping_complexity(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - large grouping by absolute values!" << endl;
        abort();
    }
}

// Function to check DP update complexity
void check_dp_update_complexity(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - costly DP table updates!" << endl;
        abort();
    }
}

int main() {
    int N;
    cin >> N;
    vector<int> P(N);
    vector<int> I(N);
    for (int i = 0; i < N; i++) {
        cin >> P[i];
        I[i] = i;
    }
    
    // Check sort complexity before the bubble sort
    check_sort_complexity(N > 1000); // Arbitrary threshold for triggering the sort check
    
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N - 1; j++) {
            if (abs(P[j]) > abs(P[j + 1])) {
                swap(P[j], P[j + 1]);
                swap(I[j], I[j + 1]);
            }
        }

    long long ans = 0;
    int pos = 0;
    while (pos < N) {
        int npos = pos;
        while (npos < N && abs(P[npos]) == abs(P[pos])) npos++;
        int M = npos - pos;

        // Check grouping complexity
        check_grouping_complexity(M > 500); // Arbitrary threshold for large group size

        vector<long long> L(M, 0);
        vector<long long> U(M, 0);
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < pos; j++) {
                if (I[j] < I[pos + i]) {
                    L[i]++;
                } else {
                    U[i]++;
                }
            }
        }
        fill(&DP[0][0], &DP[0][0] + 2 * maxn, inf);
        DP[0][0] = 0;

        // Check DP update complexity
        check_dp_update_complexity(M > 500); // Arbitrary threshold for DP update complexity

        for (int i = 0; i < M; i++) {
            int cur = i % 2;
            int nxt = 1 - cur;
            fill(&DP[nxt][0], &DP[nxt][0] + maxn, inf);
            for (int j = 0; j < i + 1; j++)
                if (DP[cur][j] < inf) {
                    DP[nxt][j] = min(DP[nxt][j], DP[cur][j] + L[i] + j);
                    DP[nxt][j + 1] = min(DP[nxt][j + 1], DP[cur][j] + U[i]);
                }
        }
        if (P[pos] != 0) {
            long long add = 1e12;
            for (int i = 0; i < M + 1; i++)
                add = min(add, DP[M % 2][i]);
            ans += add;
        }
        pos = npos;
    }
    cout << ans << endl;
}