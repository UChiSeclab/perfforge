#include <bits/stdc++.h>
using namespace std;

// Insert the checker functions
void check_large_n_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - large n value causing deep and broad recursion!" << endl;
        abort();
    }
}

void check_large_m_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - large m value leading to deep recursion depth!" << endl;
        abort();
    }
}

void check_combination_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - large n and m causing combinatorial explosion!" << endl;
        abort();
    }
}

// Main program starts here
const long long INF = 1000000000;
struct edge {
    long long to, cost;
    edge(int a, int b) : to(a), cost(b) {}
};
long long n, m;
long long mod = 1000000007;
long long dp[15][1005][1005];

long long dfs(long long pos, long long sta, long long stb) {
    if (sta > stb) return 0;
    if (pos >= m) return 1;
    if (dp[pos][sta][stb]) return dp[pos][sta][stb];
    long long re = dfs(pos + 1, sta, stb);
    re += dfs(pos, sta, stb - 1) + dfs(pos, sta + 1, stb) -
          dfs(pos, sta + 1, stb - 1) + mod;
    re %= mod;
    dp[pos][sta][stb] = re;
    return re;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    
    // Perform performance checks
    check_large_n_invariant(n > 800); // Check for large n values
    check_large_m_invariant(m >= 9); // Check for large m values
    check_combination_invariant(n > 600 && m >= 8); // Check for combination of large n and m

    cout << dfs(0, 1, n) << endl;
}