#include <bits/stdc++.h>
using namespace std;

// Checkers for performance invariants

// Checks if recursion depth exceeds a reasonable limit
void check_recursion_invariant(int currentDepth, int maxDepth) {
    if (currentDepth > maxDepth) {
        cerr << "Warning: Performance bottleneck condition triggered - recursion depth too high!" << endl;
        abort();
    }
}

// Checks if the string length is too long for efficient processing
void check_string_length_invariant(const string& s, int maxLength) {
    if (s.length() > maxLength) {
        cerr << "Warning: Performance bottleneck condition triggered - string length too long for efficient processing!" << endl;
        abort();
    }
}

// Checks if the number of non-zero digits could lead to exponential computation
void check_exponential_growth_invariant(const string& s, int threshold) {
    int nonZeroCount = count_if(s.begin(), s.end(), [](char c){ return c != '0'; });
    if (nonZeroCount > threshold) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive non-zero digits leading to exponential computation!" << endl;
        abort();
    }
}

long long solve(string s, int depth = 0) {
    // Check recursion depth
    check_recursion_invariant(depth, 20);  // Arbitrary threshold for recursion depth
    // Check if the string is too long
    check_string_length_invariant(s, 9);  // As per the problem, the string should not exceed 9 digits

    if (count(s.begin(), s.end(), '0') == s.size()) {
        if (s == "0")
            return 1990;
        else if (s == "00")
            return 2000;
        else if (s == "000")
            return 3000;
        else {
            long long v;
            s = '1' + s;
            sscanf(s.c_str(), "%lld", &v);
            return v;
        }
    }
    long long value;
    sscanf(s.c_str(), "%lld", &value);
    long long p10 = 1;
    for (int i = 0; i < (int)s.size(); ++i) p10 *= 10;
    long long m = 1989;
    for (string sub = s.substr(1, s.size() - 1); !sub.empty();
         sub = sub.substr(1, sub.size() - 1)) {
        // Increment depth for recursion
        m = max(m, 1 + solve(sub, depth + 1));
    }
    if (m <= value) return value;
    long long k = (m - value + p10 - 1) / p10;
    return value + k * p10;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        string s;
        scanf(" IAO'");
        cin >> s;
        // Check for exponential growth condition
        check_exponential_growth_invariant(s, 5);  // Threshold for non-zero digits
        cout << solve(s) << "\n";
    }
    return 0;
}