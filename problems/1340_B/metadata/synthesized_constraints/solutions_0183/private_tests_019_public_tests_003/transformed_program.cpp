#include <bits/stdc++.h>
using namespace std;

vector<string> lista;
vector<string> pingo = {"1110111", "0010010", "1011101", "1011011", "0111010",
                        "1101011", "1101111", "1010010", "1111111", "1111011"};
int dp[2005][2005];

// Check for recursive exploration
void check_recursive_exploration(int n, int k) {
    if (n > 1500 && k > 1500) {
        cerr << "Warning: Performance bottleneck triggered - recursive exploration may be extensive!" << endl;
        abort();
    }
}

// Check for excessive calls to the reachable function
void check_segment_reaching(int reachableCalls) {
    if (reachableCalls > 10000) {
        cerr << "Warning: Performance bottleneck triggered - excessive calls to reachable function!" << endl;
        abort();
    }
}

// Check for high branching factor in recursion
void check_branching_factor(int branchingEstimate) {
    if (branchingEstimate > 1000) {
        cerr << "Warning: Performance bottleneck triggered - high branching factor in recursion!" << endl;
        abort();
    }
}

// Check for potential combinatorial problem size
void check_combinatorial_size(int n, int k) {
    if (n > 1000 && k > n / 2) {
        cerr << "Warning: Performance bottleneck triggered - potential combinatorial problem size!" << endl;
        abort();
    }
}

int reachable(string s, int j) {
    string target = pingo[j];
    int ans = 0;
    for (int i = 0; i < 7; i++) {
        if (target[i] == '0' && s[i] == '1')
            return -1;
        else if (target[i] == '1' && s[i] == '0')
            ans++;
    }
    return ans;
}

bool doable(int pos, int k) {
    if (dp[pos][k] != -1)
        return dp[pos][k];
    else {
        bool ans = false;
        for (int j = 0; j <= 9; j++) {
            int val = reachable(lista[pos], j);
            if (val >= 0 && val <= k) {
                ans = ans || doable(pos + 1, k - val);
            }
        }
        dp[pos][k] = ans;
        return ans;
    }
}

int main() {
    memset(dp, -1, sizeof(dp));
    int n, kk;
    scanf("%d %d", &n, &kk);
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        lista.push_back(s);
    }
    
    // Position checkers at the setup phase
    check_recursive_exploration(n, kk);
    check_combinatorial_size(n, kk);

    dp[n][0] = 1;
    for (int i = 1; i < 2005; i++) {
        dp[n][i] = 0;
    }

    string ans;
    int reachableCalls = 0;
    for (int i = 0; i < n; i++) {
        string s = lista[i];
        int branchingFactor = 0;
        for (int j = 9; j >= 0; j--) {
            int val = reachable(s, j);
            reachableCalls++;
            if (val >= 0 && val <= kk && doable(i + 1, kk - val) != 0) {
                kk -= val;
                ans.push_back('0' + j);
                branchingFactor++;
                break;
            }
        }
        
        // Check for excessive branching within each digit
        check_branching_factor(branchingFactor);
    }

    // Final check for excessive calls
    check_segment_reaching(reachableCalls);

    if (ans.size() != n)
        puts("-1");
    else
        cout << ans << '\n';
    return 0;
}