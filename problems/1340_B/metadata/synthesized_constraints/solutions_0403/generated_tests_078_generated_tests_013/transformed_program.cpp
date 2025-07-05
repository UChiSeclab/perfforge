#include <bits/stdc++.h>
using namespace std;

const long long inf = 1e15;
const int mod = 1e9 + 7;
const int maxn = 1e6 + 3;
int n, m, k;
int a[11];
int dp[2005][2005];
int check[1 << 7 + 1];
int arr[2005];
int f = 0;

// Utility functions for checking performance conditions
void check_recursion_depth(int currentDepth, int maxAllowedDepth) {
    if (currentDepth > maxAllowedDepth) {
        cerr << "Warning: Performance bottleneck condition triggered due to high recursion depth!" << endl;
        abort();
    }
}

void check_branching_factor(int branchingFactor, int maxAllowedFactor) {
    if (branchingFactor > maxAllowedFactor) {
        cerr << "Warning: Performance bottleneck condition triggered due to excessive branching!" << endl;
        abort();
    }
}

void check_digit_complexity(int complexity, int maxAllowedComplexity) {
    if (complexity > maxAllowedComplexity) {
        cerr << "Warning: Performance bottleneck condition triggered due to high digit complexity!" << endl;
        abort();
    }
}

// Convert binary string to decimal
int fun(int n) {
    int num = n;
    int dec_value = 0;
    int base = 1;
    int temp = num;
    while (temp) {
        int last_digit = temp % 10;
        temp = temp / 10;
        dec_value += last_digit * base;
        base = base * 2;
    }
    return dec_value;
}

// Recursive solving function with performance checks
string solve(int cur, int nn, int currentDepth) {
    check_recursion_depth(currentDepth, 50); // Check recursion depth

    if (f) return "";
    if (nn < 0) return "";
    if (nn == 0 && cur == n) {
        f = 1;
        return "";
    } else if (cur == n) {
        return "";
    }
    if (cur >= 0 && nn >= 0 && dp[cur][nn] == 0) {
        return "";
    }
    string res;
    int branchingFactor = 0; // Track branching factor

    for (int i = 9; i >= 0; i--) {
        string x = to_string(i);
        if ((cur >= 0) && (a[i] | arr[cur]) != a[i]) {
            continue;
        } else {
            if (a[i] - arr[cur] >= 0) {
                branchingFactor++;
                check_branching_factor(branchingFactor, 10); // Check branching factor
                res = solve(cur + 1, nn - check[(a[i] - arr[cur])], currentDepth + 1);
            }
        }
        if (f) {
            res = x + res;
            return res;
        }
    }
    if (f == 0) {
        dp[cur][nn] = 0;
    }
    return "";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    while (t--) {
        cin >> n >> k;
        a[0] = 119;
        a[1] = 18;
        a[2] = 93;
        a[3] = 91;
        a[4] = 58;
        a[5] = 107;
        a[6] = 111;
        a[7] = 82;
        a[8] = 127;
        a[9] = 123;

        for (int i = 0; i < n; i++) {
            int temp;
            cin >> temp;
            int x = fun(temp);
            arr[i] = x;
        }

        memset(dp, -1, sizeof(dp));
        for (int i = 0; i < (1 << 7); i++) {
            check[i] = __builtin_popcount(i);
        }

        int nn = k;
        string ans = solve(0, nn, 0); // Initial depth is 0

        if (ans.size() < n) {
            cout << "-1\n";
        } else {
            cout << ans << '\n';
        }
    }
}