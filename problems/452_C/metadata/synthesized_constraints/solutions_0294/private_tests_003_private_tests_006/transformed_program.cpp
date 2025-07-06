#include <bits/stdc++.h>
using namespace std;

// Checker functions as defined above
void check_large_input_invariant(int n, int m) {
    if (n > 800 && m > 800) {
        cerr << "Warning: Performance bottleneck condition triggered due to large n and m!" << endl;
        abort();
    }
}

void check_combination_invariant(int k) {
    if (k > 800) {
        cerr << "Warning: Performance bottleneck condition triggered due to extensive combination calculations!" << endl;
        abort();
    }
}

void check_nested_loop_operations(int vectorSize) {
    if (vectorSize > 1000) {
        cerr << "Warning: Performance bottleneck condition triggered due to large vector operations!" << endl;
        abort();
    }
}

void check_sorting_invariant(int vectorSize) {
    if (vectorSize > 1000) {
        cerr << "Warning: Performance bottleneck condition triggered due to large sorting operations!" << endl;
        abort();
    }
}

void nCr(int n, int k, vector<long double> &foo2, vector<long double> &ta7t) {
    // Check for extensive combination calculations
    check_combination_invariant(k);

    for (int i = (int)(1), _m = (int)(k + 1); i < _m; ++i) 
        ta7t.push_back(i);
    for (int i = (int)(n), _m = (int)(n - k + 1); i >= _m; --i) 
        foo2.push_back(i);

    // Check for large vector operations after filling
    check_nested_loop_operations(foo2.size());
}

long double solve(int n, int m, int m2) {
    vector<long double> foo2, ta7t;

    nCr(n * m - m, n - m2, foo2, ta7t);
    nCr(n * m, n, ta7t, foo2);
    nCr(m, m2, foo2, ta7t);

    foo2.push_back(m2), foo2.push_back(m2);
    ta7t.push_back(n);

    // Check for large sorting overhead
    check_sorting_invariant(foo2.size());
    check_sorting_invariant(ta7t.size());

    sort(foo2.rbegin(), foo2.rend()), sort(ta7t.rbegin(), ta7t.rend());
    int common = min((int)foo2.size(), (int)ta7t.size());
    long double res = 1;
    for (int i = (int)(0), _m = (int)(common); i < _m; ++i)
        res *= foo2[i] / ta7t[i];
    for (int i = (int)(common), _m = (int)(foo2.size()); i < _m; ++i)
        res *= foo2[i];
    for (int i = (int)(common), _m = (int)(ta7t.size()); i < _m; ++i)
        res /= ta7t[i];
    return res;
}

int main() {
    int n, m;
    while (cin >> n >> m) {
        // Check for large input sizes
        check_large_input_invariant(n, m);

        long double res = 0;
        for (int m2 = (int)(1), _m = (int)(min(n, m) + 1); m2 < _m; ++m2)
            res += solve(n, m, m2);
        cout.precision(8);
        cout << fixed << res << endl;
    }
    return 0;
}