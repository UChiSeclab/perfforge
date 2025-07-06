#include <bits/stdc++.h>
using namespace std;

// Function to check segment conversion complexity
void check_segment_conversion_invariant(int n, int k) {
    if (n > 1000 && k > 1000) {  // Assuming n > 1000 and k > 1000 causes excessive calls
        cerr << "Warning: Performance bottleneck due to excessive segment conversion calls!" << endl;
        abort();
    }
}

// Function to check nested loop performance
void check_nested_loop_invariant(int n, int k) {
    if (n > 1000 && k > 100) {  // Thresholds set where nested loops become expensive
        cerr << "Warning: Performance bottleneck due to nested loops!" << endl;
        abort();
    }
}

// Function to check dynamic programming table fill
void check_dp_table_invariant(int n, int k) {
    if (n * k > 1000000) {  // Threshold for high DP table states
        cerr << "Warning: Performance bottleneck due to large DP table states!" << endl;
        abort();
    }
}

int n, k;
vector<string> dig;
string number[10];
int convert(string s1, string s2) {
    int ans = 0;
    for (int i = 0; i < 7; i++) {
        if (s1[i] != s2[i]) {
            if (s1[i] == '0')
                ans++;
            else
                return -1;
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    
    // Place invariant checks after input
    check_segment_conversion_invariant(n, k);
    check_nested_loop_invariant(n, k);
    check_dp_table_invariant(n, k);
    
    dig.resize(n);
    number[0] = "1110111";
    number[1] = "0010010";
    number[2] = "1011101";
    number[3] = "1011011";
    number[4] = "0111010";
    number[5] = "1101011";
    number[6] = "1101111";
    number[7] = "1010010";
    number[8] = "1111111";
    number[9] = "1111011";
    for (int i = 0; i < n; cin >> dig[i++])
        ;
    vector<vector<bool>> dp(n, vector<bool>(k + 1));
    for (int i = 0; i <= 9; i++) {
        int cost = convert(dig[n - 1], number[i]);
        if (cost != -1 && cost <= k) dp[n - 1][cost] = true;
    }
    for (int i = n - 2; i >= 0; i--) {
        for (int j = 0; j <= k; j++) {
            for (int d = 0; d <= 9; d++) {
                int cost = convert(dig[i], number[d]);
                if (cost != -1 && j - cost >= 0 && dp[i + 1][j - cost]) {
                    dp[i][j] = true;
                }
            }
        }
    }
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        bool flag = 0;
        for (int d = 9; d >= 0; d--) {
            int cost = convert(dig[i], number[d]);
            if (cost != -1 && k >= cost && i != n - 1 && dp[i + 1][k - cost]) {
                flag = 1;
                ans[i] = d;
                k -= cost;
                break;
            }
            if (cost == k && i == n - 1) {
                ans[i] = d;
                flag = 1;
                k -= cost;
                break;
            }
        }
        if (!flag) {
            cout << "-1\n";
            return 0;
        }
    }
    for (int i = 0; i < n; i++) cout << ans[i];
    return 0;
}