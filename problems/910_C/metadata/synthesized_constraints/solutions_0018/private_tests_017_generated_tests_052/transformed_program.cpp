#include <bits/stdc++.h>
using namespace std;
const int POW[] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};
int n;
int ans = 1000000000;
int ad[15];
char c[15];
bool vis[15];
bool n0[15];
string s[1005];

void cal_ad() {
    memset(ad, 0, sizeof(ad));
    for (int i = 1; i <= n; i++) {
        for (int j = s[i].size() - 1, k = 0; j >= 0; j--, k++) {
            ad[s[i][j] - 'a'] += POW[k];
        }
    }
}

void dfs(int col, int sum) {
    check_dfs_invariant(col, 10 - col); // Check for high recursion depth or branching factor
    if (col == 10) {
        ans = min(ans, sum);
        return;
    }
    for (int i = 0; i < 10; i++) {
        if (!vis[i]) {
            vis[i] = true;
            dfs(col + 1, sum + ad[i] * col);
            vis[i] = false;
        }
    }
}

void cal_n0() {
    memset(n0, false, sizeof(n0));
    unordered_set<char> uniqueLeadingChars;
    for (int i = 1; i <= n; i++) {
        n0[s[i][0] - 'a'] = true;
        uniqueLeadingChars.insert(s[i][0]);
    }
    check_leading_zero_invariant(uniqueLeadingChars.size()); // Check for too many unique leading characters
}

void read() {
    unordered_map<char, int> charFrequency;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        for (char c : s[i]) {
            charFrequency[c]++;
        }
    }
    int maxCharFrequency = 0;
    for (auto &entry : charFrequency) {
        maxCharFrequency = max(maxCharFrequency, entry.second);
    }
    check_unbalanced_input_invariant(maxCharFrequency); // Check for unbalanced character distribution
}

void solve() {
    cal_ad();
    cal_n0();
    memset(vis, false, sizeof(vis));
    for (int i = 0; i < 10; i++) {
        if (!n0[i]) {
            vis[i] = true;
            dfs(1, 0);
            vis[i] = false;
        }
    }
}

void print() { cout << ans << endl; }

int main() {
    read();
    solve();
    print();
}