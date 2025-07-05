#include <bits/stdc++.h>
using namespace std;

int n, k;
long long dp[202][202][202];
string s, t;

void check_large_replacements_invariant(int n, int k) {
    if (k > n - 10) {  // Assuming "close to n" means within 10 characters
        cerr << "Warning: Large replacements invariant triggered - k is close to n" << endl;
        abort();
    }
}

void check_repeated_characters_invariant(const string &s, const string &t) {
    if (t[0] == t[1]) {
        int count_t0 = count(s.begin(), s.end(), t[0]);
        if (count_t0 > s.size() / 2) {  // Majority of string consists of t[0]
            cerr << "Warning: Repeated characters invariant triggered - s consists mainly of t[0]" << endl;
            abort();
        }
    }
}

void check_recursive_depth_invariant(int n, int k) {
    int max_recursion_depth = n + k;  // Approximate maximum depth
    if (max_recursion_depth > 180) {  // Threshold based on problem constraints
        cerr << "Warning: Recursive depth invariant triggered - potential high depth" << endl;
        abort();
    }
}

long long fun(int pos, int mov, long long ase) {
    if (pos < 0) {
        return 0;
    }
    if (dp[pos][mov][ase] != -1) {
        return dp[pos][mov][ase];
    }
    long long res = 0;
    if (s[pos] == t[0]) {
        if (t[0] == t[1]) {
            res = max(res, ase + fun(pos - 1, mov, ase + 1));
        } else {
            res = max(res, ase + fun(pos - 1, mov, ase));
        }
    }
    if (s[pos] == t[1]) {
        if (t[0] == t[1]) {
            res = max(res, ase + fun(pos - 1, mov, ase + 1));
        } else {
            res = max(res, fun(pos - 1, mov, ase + 1));
        }
    }
    if ((mov - 1) >= 0) {
        if (t[0] == t[1]) {
            res = max(res, ase + fun(pos - 1, mov - 1, ase + 1));
        }
        res = max(res, ase + fun(pos - 1, mov - 1, ase));
        res = max(res, fun(pos - 1, mov - 1, ase + 1));
        if (s[pos] == t[1]) {
            if (t[0] == t[1]) {
                res = max(res, ase + fun(pos - 1, mov, ase + 1));
            } else {
                res = max(res, fun(pos - 1, mov, ase + 1));
            }
        } else {
            res = max(res, fun(pos - 1, mov, ase));
        }
    } else {
        if (s[pos] == t[1]) {
            if (t[0] == t[1]) {
                res = max(res, ase + fun(pos - 1, mov, ase + 1));
            } else {
                res = max(res, fun(pos - 1, mov, ase + 1));
            }
        } else {
            res = max(res, fun(pos - 1, mov, ase));
        }
    }
    return dp[pos][mov][ase] = res;
}

int main() {
    while (cin >> n >> k) {
        cin >> s >> t;
        
        // Check invariants after reading inputs
        check_large_replacements_invariant(n, k);
        check_repeated_characters_invariant(s, t);
        check_recursive_depth_invariant(n, k);
        
        memset(dp, -1, sizeof dp);
        cout << fun(n - 1, k, 0) << endl;
    }
    return 0;
}