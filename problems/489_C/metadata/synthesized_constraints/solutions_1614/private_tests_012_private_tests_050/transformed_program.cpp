#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 7;
int factors[maxn];
long long mod = 998244353;
string p1, p2;
long long dp[105][905];

// Checker functions
void check_large_sum_invariant(int m, int s) {
    if (s > m * 9) {
        cerr << "Warning: Performance bottleneck condition triggered - large sum compared to length!" << endl;
        abort();
    }
}

void check_recursion_invariant(int m, int s, int current_level) {
    if (current_level > m || s > m * 9) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive recursion branching!" << endl;
        abort();
    }
}

void check_memoization_invariant(int m, int current_s, long long dp_value) {
    if (current_s >= 0 && current_s <= m * 9 && dp_value == -1) {
        cerr << "Warning: Memoization not effective - repeated calculations detected!" << endl;
        abort();
    }
}

void check_recursive_exploration_invariant(int m, int s) {
    if (s > m * 9) {
        cerr << "Warning: Performance bottleneck condition triggered - recursive exploration inefficient!" << endl;
        abort();
    }
}

long long solve(long long S, long long s, long long n, string num) {
    // Check recursion invariant
    check_recursion_invariant(n, S, s);
    
    if (s == n) {
        if (S == 0) {
            p1 = num;
            return dp[s][S] = 1;
        }
        return dp[s][S] = 0;
    }
    if (dp[s][S] != -1) return dp[s][S];
    check_memoization_invariant(n, S, dp[s][S]);
    for (int i = 0; i <= 9; i++) {
        if (S - i >= 0)
            if (solve(S - i, s + 1, n, num + to_string(i)) == 1) return dp[s][S] = 1;
    }
    return dp[s][S] = 0;
}

long long solve2(long long S, long long s, long long n, string num) {
    // Check recursion invariant
    check_recursion_invariant(n, S, s);

    if (s == n) {
        if (S == 0) {
            p2 = num;
            return dp[s][S] = 1;
        }
        return dp[s][S] = 0;
    }
    if (dp[s][S] != -1) return dp[s][S];
    check_memoization_invariant(n, S, dp[s][S]);
    for (int i = 9; i >= 0; i--) {
        if (S - i >= 0)
            if (solve2(S - i, s + 1, n, num + to_string(i)) == 1) return dp[s][S] = 1;
    }
    return dp[s][S] = 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long m, s;
    cin >> m >> s;

    // Check large sum invariant
    check_large_sum_invariant(m, s);
    check_recursive_exploration_invariant(m, s);

    if (s == 0) {
        if (m == 1)
            cout << "0 0";
        else
            cout << "-1 -1";
        return 0;
    }

    p1 = "";
    p2 = "";
    memset(dp, -1, sizeof(dp));
    for (int i = 1; i <= 9; i++) {
        if (solve(m - i, 1, m, to_string(i))) break;
    }
    memset(dp, -1, sizeof(dp));
    for (int i = 9; i >= 1; i--) {
        if (solve2(m - i, 1, m, to_string(i))) break;
    }
    if (p1 == "" || p2 == "")
        cout << -1 << " " << -1;
    else
        cout << p1 << " " << p2;
    cout << "\n";

    return 0;
}