#include <bits/stdc++.h>
using namespace std;

// Checker functions for performance invariants
void check_frequent_parsing(const std::string& suffix) {
    int zero_count = 0;
    for (char c : suffix) {
        if (c == '0') zero_count++;
        else break;
    }
    if (zero_count > 5) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive zeroes in suffix" << endl;
        abort();
    }
}

void check_deep_recursion(int recursion_depth, int max_limit) {
    if (recursion_depth > max_limit) {
        cerr << "Warning: Performance bottleneck condition triggered - deep recursion" << endl;
        abort();
    }
}

void check_candidate_generation(int candidate_count) {
    if (candidate_count > 10000) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive candidate generation" << endl;
        abort();
    }
}

long long parse_int(const string& s) {
    long long res = 0;
    for (char c : s) res = 10 * res + (c - '0');
    return res;
}

string stringify(long long i) {
    char buf[32], *p = &buf[32];
    *--p = '\0';
    while (i > 0) *--p = '0' + i % 10, i /= 10;
    return string(p);
}

long long next_candidate(const string& suffix, int& state) {
    static int candidate_count = 0; // Track candidate generations
    check_frequent_parsing(suffix); // Check for parsing bottlenecks

    if (state == 0) {
        switch (suffix.size()) {
            case 0:
                state = 1989;
                break;
            case 1:
                state = 198;
                break;
            case 2:
                state = 19;
                break;
            default:
                state = 1;
                break;
        }
        if (suffix[0] != '0') {
            long long x = parse_int(suffix);
            if (x >= 1989) return x;
        }
    }
    for (;;) {
        long long x = parse_int(stringify(state) + suffix);
        ++state;
        candidate_count++;
        check_candidate_generation(candidate_count); // Check for candidate generation bottlenecks
        if (x >= 1989) return x;
    }
}

string abbreviation(long long i, int depth = 0) {
    check_deep_recursion(depth, 100); // Check for recursion depth

    string s = stringify(i);
    for (int n = 1; n <= s.size(); ++n) {
        string t = s.substr(s.size() - n);
        int state = 0;
        for (;;) {
            long long j = next_candidate(t, state);
            if (i == j) return t;
            if (abbreviation(j, depth + 1) == t) break;
        }
    }
    return "";
}

long long solve(string s) {
    int state = 0;
    for (;;) {
        long long i = next_candidate(s, state);
        if (abbreviation(i) == s) return i;
    }
    return -1;
}

int main() {
    int cases = 0;
    cin >> cases;
    for (int c = 0; c < cases; ++c) {
        string s;
        cin >> s;
        cout << solve(s.substr(4)) << '\n';
    }
}