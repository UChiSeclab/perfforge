#include <bits/stdc++.h>
using namespace std;

unsigned long long int N, k;
string tgt;

// Checkers for performance invariants
void check_string_conversion_invariant(unsigned long long int n) {
    if (n > 100000000000000000ULL) { // Threshold chosen based on potential large execution
        cerr << "Warning: Performance bottleneck condition triggered - String conversion overhead!" << endl;
        abort();
    }
}

void check_recursive_depth_invariant(int depth) {
    if (depth > 10000) { // Assumed threshold for deep recursion
        cerr << "Warning: Performance bottleneck condition triggered - Deep recursion in function f!" << endl;
        abort();
    }
}

void check_binary_search_invariant(unsigned long long int l, unsigned long long int r) {
    if (r - l > 100000000000000000ULL) { // High range indicating extensive search
        cerr << "Warning: Performance bottleneck condition triggered - Extensive binary search iterations!" << endl;
        abort();
    }
}

string toStr(unsigned long long int x) {
    check_string_conversion_invariant(x); // Check for string conversion overhead
    string res = "";
    while (x) {
        res = (char)(x % 2 + '0') + res;
        x /= 2;
    }
    return res;
}

unsigned long long int f(string str, int depth = 0) {
    check_recursive_depth_invariant(depth); // Check for recursion depth
    string cmp = tgt.substr(0, str.length());
    unsigned long long int res;
    if (cmp == str) {
        res = (1ULL << (tgt.length() - str.length())) - 1;
        for (unsigned long long int i = str.length(); i < tgt.length(); i++) {
            if (tgt[i] == '1') {
                res += (1ULL << (tgt.length() - i - 1));
            }
        }
        res++;
        if (str[str.length() - 1] == '0') {
            str[str.length() - 1] = '1';
            res += f(str, depth + 1);
        }
    } else if (cmp > str) {
        res = (1ULL << (tgt.length() - str.length() + 1)) - 1;
        if (str[str.length() - 1] == '0') {
            str[str.length() - 1] = '1';
            res += f(str, depth + 1);
        }
    } else {
        res = (1ULL << (tgt.length() - str.length())) - 1;
        if (str[str.length() - 1] == '0') {
            str[str.length() - 1] = '1';
            res += f(str, depth + 1);
        }
    }
    return res;
}

unsigned long long int getPath(unsigned long long int x) {
    if (x > N)
        return 0;
    else
        return f(toStr(x));
}

signed main() {
    cin >> N >> k;
    tgt = toStr(N);
    
    unsigned long long int l = 1, r = (N + 10) / 2, m, a, b;

    while (l + 1 < r) {
        check_binary_search_invariant(l, r); // Check for binary search iterations
        m = (l + r) / 2;
        if (getPath(2 * m) >= k) {
            l = m;
        } else
            r = m;
    }
    a = 2 * l;

    l = 0, r = (N + 10) / 2;
    while (l + 1 < r) {
        check_binary_search_invariant(l, r); // Check for binary search iterations
        m = (l + r) / 2;
        if (getPath(2 * m + 1) >= k) {
            l = m;
        } else
            r = m;
    }
    b = 2 * l + 1;

    if (getPath(a) < k)
        cout << b << endl;
    else
        cout << max(a, b) << endl;
}