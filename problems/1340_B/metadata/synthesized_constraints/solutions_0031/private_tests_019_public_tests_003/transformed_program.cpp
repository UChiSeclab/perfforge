#include <bits/stdc++.h>
using namespace std;

long long mod = 1000000007;
string all[] = {"1110111", "0010010", "1011101", "1011011", "0111010",
                "1101011", "1101111", "1010010", "1111111", "1111011"};
vector<string> v;
long long val[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
long long dp[2005][2005];

void check_recursion_and_branching_invariant(int n, int k) {
    if (n > 1500 && k > 1500) { // Threshold chosen based on problem constraints
        cerr << "Warning: Recursion and branching limit exceeded!" << endl;
        abort();
    }
}

void check_frequent_unsuccessful_attempts(int unsuccessfulAttempts, int threshold) {
    if (unsuccessfulAttempts > threshold) { // Example threshold for warning, adjust as necessary
        cerr << "Warning: Excessive unsuccessful attempts in check function!" << endl;
        abort();
    }
}

bool check(string &s, string &d, long long &count) {
    int unsuccessfulAttempts = 0; // Track unsuccessful attempts
    for (long long i = 0; i < 7; i++) {
        if (s[i] == '1' && d[i] == '0') {
            unsuccessfulAttempts++;
            return false;
        } else if (s[i] == '0' && d[i] == '1') {
            count++;
        }
    }
    check_frequent_unsuccessful_attempts(unsuccessfulAttempts, 100); // Arbitrary threshold
    return true;
}

bool f(long long ind, long long n, long long k, string &ans) {
    if (ind == n || k < 0) {
        if (k == 0) {
            return 1;
        }
        return 0;
    }
    if (dp[ind][k] != -1) {
        return dp[ind][k];
    }
    string s = v[ind];
    string p, q;
    int numAttempts = 0; // Track number of digit attempts
    for (long long i = 9; i >= 0; i--) {
        long long count = 0;
        if (check(s, all[i], count)) {
            ans += to_string(i);
            numAttempts++;
            if (f(ind + 1, n, k - count, ans)) {
                return dp[ind][k] = 1;
            }
            ans.pop_back();
        }
    }
    check_high_branching_invariant(numAttempts, 10); // Example threshold for branches
    return dp[ind][k] = 0;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    long long n, k;
    cin >> n >> k;
    check_recursion_and_branching_invariant(n, k); // Check recursion and branches based on input size
    string s;
    for (long long i = 0; i < n; i++) {
        cin >> s;
        v.push_back(s);
    }
    memset(dp, -1, sizeof(dp));
    string ans = "";
    if (f(0, n, k, ans)) {
        cout << ans;
    } else
        cout << -1;
}