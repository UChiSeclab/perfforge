#include <bits/stdc++.h>
using namespace std;

string txt, pat;
string con(int x) {
    static int conversionCalls = 0; // Counter for string conversions
    conversionCalls++;
    check_conversion_invariant(conversionCalls);

    stringstream ss;
    ss << x;
    return ss.str();
}

int sv_sub[1000005][10];
int F[1000005];

void fail() {
    int i = 0, j = -1;
    F[0] = -1;
    while (i < pat.size()) {
        while (j >= 0 && pat[i] != pat[j]) j = F[j];
        i++, j++;
        F[i] = j;
    }
}

vector<int> sv2;

bool chk(int sz, vector<int> sv) {
    static int nestedChecks = 0; // Counter for nested loop checks
    nestedChecks++;
    check_nested_check_invariant(nestedChecks);

    string sz_s = con(sz);
    for (char c : sz_s) sv[c - '0']--;
    int cnt = 0;
    for (int i = 0; i < 10; i++) cnt += sv[i];
    if (cnt != sz) return 0;
    for (int i = 0; i <= 9; i++)
        if (sv[i] < 0) return 0;
    for (int i = 0; i <= 9; i++)
        if (sv[i] < sv2[i]) return 0;
    for (int i = 1; i <= 9; i++)
        if (sv[i]) return 1;
    return 0;
}

vector<int> sv;

void get_txt(int sz) {
    string sz_s = con(sz);
    for (char c : sz_s) sv[c - '0']--;
}

bool chk(int idx, int add, int match) {
    static int matchOperations = 0; // Counter for match operations
    matchOperations++;
    check_string_matching_invariant(matchOperations, pat.size());

    auto tmp_sv = sv;
    if (!idx && !add) return 0;
    if (!tmp_sv[add]) return 0;
    tmp_sv[add]--;
    while (match >= 0 && add != (pat[match] - '0')) match = F[match];
    match++;
    for (int i = 0; i < 10; i++)
        if (tmp_sv[i] < sv_sub[match][i]) return 0;
    return 1;
}

int main() {
    cin >> txt >> pat;
    if (txt.size() == 2) {
        if (txt[0] == '1')
            txt.erase(txt.begin());
        else
            txt.erase(txt.begin() + 1);
        cout << txt << '\n';
        return 0;
    }

    sv.assign(10, 0);
    sv2.assign(10, 0);
    for (char c : txt) sv[c - '0']++;
    for (char c : pat) sv2[c - '0']++;

    int i = 1;
    for (int i = pat.size() - 1; i >= 0; i--)
        for (int j = 0; j < 10; j++)
            sv_sub[i][j] = sv_sub[i + 1][j] + (j == (pat[i] - '0'));

    int iterationCount = 0; // Counter for iterations

    for (;; i++) {
        check_iteration_growth_invariant(iterationCount);
        iterationCount++;
        if (chk(i, sv)) break;
    }

    int sz = i;
    get_txt(sz);
    string ans = "";
    int f = 0;
    i = 0;
    fail();

    while (i < sz) {
        for (int j = (i == 0); j < 10; j++) {
            if (chk(i, j, f)) {
                ans.push_back(j + '0');
                sv[j]--;
                break;
            }
        }
        while (f >= 0 && ans[i] != pat[f]) f = F[f];
        i++, f++;
        if (f == pat.size()) break;
    }

    static int modifications = 0; // Counter for modifications

    for (int i = 0; i < 10; i++) {
        check_modification_invariant(modifications);
        while (sv[i]--) {
            modifications++;
            ans.push_back('0' + i);
        }
    }

    cout << ans << '\n';
    return 0;
}

// Add the checker function implementations here
void check_conversion_invariant(int conversionCalls) {
    if (conversionCalls > 50) {
        cerr << "Warning: Performance bottleneck condition triggered due to excessive string conversions!" << endl;
        abort();
    }
}

void check_nested_check_invariant(int nestedChecks) {
    if (nestedChecks > 1000) {
        cerr << "Warning: Performance bottleneck condition triggered due to excessive checks in nested loops!" << endl;
        abort();
    }
}

void check_string_matching_invariant(int matchOperations, int patSize) {
    if (matchOperations > 100 && patSize > 5) {
        cerr << "Warning: Performance bottleneck condition triggered due to high-frequency string matching!" << endl;
        abort();
    }
}

void check_modification_invariant(int modifications) {
    if (modifications > 500) {
        cerr << "Warning: Performance bottleneck condition triggered due to frequent modifications to data structures!" << endl;
        abort();
    }
}

void check_iteration_growth_invariant(int iterations) {
    if (iterations > 100) {
        cerr << "Warning: Performance bottleneck condition triggered due to exponential growth of iterations!" << endl;
        abort();
    }
}