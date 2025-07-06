#include <bits/stdc++.h>
using namespace std;
const int N = 26;
string s, target;
int vis[N][2][15], id = 1;
int f[15];
bool dp[N][2][15];

// Checker functions
void check_recursion_depth_invariant(int depth, int threshold) {
    if (depth > threshold) {
        cerr << "Warning: Performance bottleneck condition triggered - recursive depth too high!" << endl;
        abort();
    }
}

void check_solve_invariant(int callCount, int threshold) {
    if (callCount > threshold) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive calls to solve function!" << endl;
        abort();
    }
}

void check_input_pattern_invariant(const string& input) {
    int consecutiveZeros = 0;
    for (char c : input) {
        if (c == '0') {
            consecutiveZeros++;
        } else {
            consecutiveZeros = 0;
        }
        if (consecutiveZeros > 5) {
            cerr << "Warning: Performance bottleneck condition triggered - excessive consecutive zeros in input!" << endl;
            abort();
        }
    }
}

// Recursive function with depth check
int get(char x, int ind, char y, int depth = 0) {
    check_recursion_depth_invariant(depth, 10); // Threshold for recursion depth
    if (x == y) return ind + 1;
    if (ind) return get(x, f[ind - 1], target[f[ind - 1]], depth + 1);
    return 0;
}

// Solve function with call count check
bool solve(int ind, bool l, int j, int& callCount) {
    callCount++;
    check_solve_invariant(callCount, 1000); // Threshold for number of calls
    if (ind == (int)s.size()) return (j + 1 == target.size()) && l;
    int &v = vis[ind][l][j];
    bool &ret = dp[ind][l][j];
    if (v == id) return ret;
    ret = 0;
    v = id;
    for (char i = '0'; i <= '9'; i++) {
        if (i < s[ind] && !l) continue;
        ret |= solve(ind + 1, l | (i > s[ind]), get(i, j, target[j]), callCount);
    }
    return ret;
}

void build(int ind, bool l, int j, string &t) {
    if (ind == s.size()) return;
    for (char i = '0'; i <= '9'; i++) {
        if (i < s[ind] && !l) continue;
        if (solve(ind + 1, l | (i > s[ind]), get(i, j, target[j]), *(new int(0)))) {
            t += i;
            build(ind + 1, l | (i > s[ind]), get(i, j, target[j]), t);
            break;
        }
    }
}

void build(string &t) {
    int j = 0;
    f[0] = 0;
    for (int i = 1; i < t.size(); ++i) {
        while (j > 0 && t[i] != t[j]) j = f[j - 1];
        if (t[i] == t[j]) ++j;
        f[i] = j;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while (s.size() < 20) s += "0";
    s += "1988";
    string T = s;
    int n;
    cin >> n;
    while (n--) {
        string t;
        cin >> t;
        check_input_pattern_invariant(t); // Check input pattern before processing
        target = " ";
        s = T;
        int i = t.size() - 1;
        while (t[i] >= '0' && t[i] <= '9') {
            target = t[i] + target;
            build(target);
            i--;
            id++;
            int solveCallCount = 0;
            solve(0, 0, 0, solveCallCount);
            string f = "";
            build(0, 0, 0, f);
            s = f;
        }
        i = 0;
        while (i < s.size() && s[i] == '0') i++;
        cout << s.substr(i) << '\n';
    }
    return 0;
}