#include <bits/stdc++.h>
using namespace std;

void fastStream() {
    cin.tie(0);
    std::ios_base::sync_with_stdio(0);
}

const int mod = 1000000000 + 7;
int K;
int C[1010];
int dp[1010][1010];
int tot;
const int MAX_ARG = 2200;
long long dp2[MAX_ARG][MAX_ARG];

void check_combination_computation(int a, int b) {
    if (a > 1000 || b > 1000) {
        cerr << "Warning: Performance bottleneck condition triggered - combination computation with large values!" << endl;
        abort();
    }
}

void check_recursive_state_space(int kind, int tot, int K) {
    if (kind < K && tot > 900) {
        cerr << "Warning: Performance bottleneck condition triggered - large recursive state space exploration!" << endl;
        abort();
    }
}

void check_color_transition_complexity(int currentColorCount, int nextColorCount) {
    if (currentColorCount > 800 && nextColorCount > 800) {
        cerr << "Warning: Performance bottleneck condition triggered - complex color transitions!" << endl;
        abort();
    }
}

long long comb(int a, int b) {
    check_combination_computation(a, b); // Check for large combination computation
    if (a < 0 || b < 0) return 0;
    if (a < b)
        return 0;
    else if (b == 0)
        return 1;
    else if (dp2[a][b] >= 0)
        return dp2[a][b];
    return dp2[a][b] = (comb(a - 1, b) + comb(a - 1, b - 1)) % mod;
}

int dfs(int kind, int pos, int sum) {
    if (dp[kind][pos] >= 0) return dp[kind][pos];
    long long res = 0;
    if (kind == K) {
        res = 1;
    } else if (pos == tot) {
        res = 0;
    } else {
        check_recursive_state_space(kind, tot, K); // Check for recursive state space
        if (pos + 1 >= C[kind] + sum) {
            const int A = pos + 1 - (C[kind] + sum) + C[kind] - 1;
            const int B = C[kind] - 1;
            res = (res + (comb(A, B) * dfs(kind + 1, pos + 1, sum + C[kind]))) % mod;
        }
        res = (res + dfs(kind, pos + 1, sum)) % mod;
    }
    return dp[kind][pos] = res;
}

int main() {
    memset(dp, -1, sizeof(dp));
    fastStream();
    cin >> K;
    for (int i = 0; i < K; i++) {
        cin >> C[i];
        tot += C[i];
    }
    
    for (int i = 0; i < K - 1; i++) {
        check_color_transition_complexity(C[i], C[i + 1]); // Check for complex color transition
    }
    
    memset(dp2, -1, sizeof(dp2));
    cout << dfs(0, 0, 0) << endl;
    return 0;
}