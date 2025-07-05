#include <bits/stdc++.h>
using namespace std;

// Checker functions for performance bottlenecks
void check_recursive_depth_invariant(int m, int s) {
    if (m > 50 && s < 10) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive recursive depth due to large m and small s!" << endl;
        abort();
    }
}

void check_redundant_state_invariant(int m, int s) {
    if (m > 50 && s <= 5) {
        cerr << "Warning: Performance bottleneck condition triggered - redundant state exploration due to low sum!" << endl;
        abort();
    }
}

void check_memoization_inefficiency(int m, int s) {
    if (m > 75 && s <= 2) {
        cerr << "Warning: Performance bottleneck condition triggered - inefficient memoization with high m and low s!" << endl;
        abort();
    }
}

long long m = 0, s = 0;
string ans;
vector<map<long long, long long>> mp;

bool DP(long long m1, long long s1) {
    if (m1 == m) return s1 == s;
    if (mp[m1].find(s1) != mp[m1].end())
        return mp[m1][s1];
    else {
        if (m1 == 0) {
            for (long long i = 1; i < 10; i++) {
                if (DP(m1 + 1, s1 + i)) {
                    ans[m1] = '0' + i;
                    mp[m1][s1] = true;
                    return true;
                }
            }
            mp[m1][s1] = false;
            return false;
        } else {
            for (long long i = 0; i < 10; i++) {
                if (DP(m1 + 1, s1 + i)) {
                    ans[m1] = '0' + i;
                    mp[m1][s1] = true;
                    return true;
                }
            }
            mp[m1][s1] = false;
            return false;
        }
    }
}

bool DPmx(long long m1, long long s1) {
    if (m1 == m) return s1 == s;
    if (mp[m1].find(s1) != mp[m1].end())
        return mp[m1][s1];
    else {
        if (m1 == 0) {
            for (long long i = 9; i >= 1; i--) {
                if (DPmx(m1 + 1, s1 + i)) {
                    ans[m1] = '0' + i;
                    mp[m1][s1] = true;
                    return true;
                }
            }
            mp[m1][s1] = false;
            return false;
        } else {
            for (long long i = 9; i >= 0; i--) {
                if (DPmx(m1 + 1, s1 + i)) {
                    ans[m1] = '0' + i;
                    mp[m1][s1] = true;
                    return true;
                }
            }
            mp[m1][s1] = false;
            return false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    cin >> m >> s;

    // Place checkers after input to catch potential slowdowns
    check_recursive_depth_invariant(m, s);
    check_redundant_state_invariant(m, s);
    check_memoization_inefficiency(m, s);

    ans.resize(m);
    mp.clear();
    mp.resize(m + 1);
    if (m == 1) {
        if (s <= 9)
            cout << s << " " << s << "\n";
        else
            cout << "-1 -1"
                 << "\n";
        return 0;
    }
    if (DP(0, 0))
        cout << ans << " ";
    else
        cout << "-1"
             << " ";
    mp.clear();
    mp.resize(m + 1);
    if (DPmx(0, 0))
        cout << ans;
    else
        cout << "-1";
    return 0;
}