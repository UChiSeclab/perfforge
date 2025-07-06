#include <bits/stdc++.h>
using namespace std;
const int N = 205;
int n, k, dp[N][N][N];
string s, t;

// Function to check large state space exploration
void check_recursion_state_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered due to large state space being explored!" << endl;
        abort();
    }
}

// Function to check for excessive overlapping subproblems
void check_memoization_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered due to excessive overlapping subproblems!" << endl;
        abort();
    }
}

// Function to check for homogeneous input string and target
void check_homogeneity_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered due to homogeneous input string and target!" << endl;
        abort();
    }
}

int solve(int ind, int rem, int prev) {
    check_recursion_state_invariant(rem > n / 2 && t[0] == t[1]);  // Check for excessive state space exploration
    if (ind == n) return 0;
    int &ret = dp[ind][rem][prev];
    if (~ret) return ret;
    
    int c1 = 0, c2 = 0, c3 = 0;
    c1 = solve(ind + 1, rem, prev + (s[ind] == t[0]));
    if (s[ind] == t[1]) c1 += prev;
    if (rem > 0) {
        c2 = solve(ind + 1, rem - 1, prev + 1);
        if (t[0] == t[1]) c2 += prev;
        c3 = solve(ind + 1, rem - 1, prev);
        c3 += prev;
    }
    ret = max({c1, c2, c3});
    return ret;
}

int main() {
    memset(dp, -1, sizeof dp);
    cin >> n >> k >> s >> t;
    
    check_homogeneity_invariant(t[0] == t[1] && count(s.begin(), s.end(), s[0]) == n);  // Check for homogeneous string and target
    
    cout << solve(0, k, 0);
    
    return 0;
}