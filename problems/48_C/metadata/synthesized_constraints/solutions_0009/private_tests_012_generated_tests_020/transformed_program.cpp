#include <bits/stdc++.h>
using namespace std;

int inp[10000];
double inp2[10000];
int n;

// Checkers for performance bottlenecks
void check_nested_loops_invariant(int iteration_count, int n) {
    if (iteration_count > 10 * n) {
        cerr << "Warning: Performance bottleneck due to excessive nested loop iterations!" << endl;
        abort();
    }
}

void check_binary_search_invariant(int binary_search_iterations) {
    if (binary_search_iterations > 1000) {
        cerr << "Warning: Performance bottleneck due to excessive binary search iterations!" << endl;
        abort();
    }
}

void check_outer_loop_invariant(int range_size) {
    if (range_size > 2000) {
        cerr << "Warning: Performance bottleneck due to excessive outer loop iterations!" << endl;
        abort();
    }
}

void check_floating_point_precision(double precision) {
    if (precision < 1e-10) {
        cerr << "Warning: Performance bottleneck due to excessive floating point precision required!" << endl;
        abort();
    }
}

int gn(double al) {
    double rem = al;
    double curs = 0.0;
    int iteration_count = 0;
    for (int i = 0; i < n; i++) {
        double k = inp2[i];
        rem -= (k - curs) * 10.0;
        if (rem < 0.0) return -1;
        if (rem >= 9.99999999999) return 1000000001;
        rem += al;
        curs = k;
        iteration_count++;
    }
    check_nested_loops_invariant(iteration_count, n); // Check nested loop iterations
    return inp[n - 1] + (int)floor(rem / 10);
}

bool fn() {
    double lft = 10.0, rgt = 100000001.0, md = 10.0;
    int binary_search_iterations = 0;
    while (fabs(rgt - lft) > 1e-7) {
        md = (lft + rgt) / 2.0;
        int el = gn(md);
        if (el == inp[n]) return true;
        if (el < inp[n])
            lft = md;
        else
            rgt = md;
        binary_search_iterations++;
    }
    check_binary_search_invariant(binary_search_iterations); // Check binary search iterations
    check_floating_point_precision(fabs(rgt - lft)); // Check floating-point precision
    return false;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> inp2[i];
        inp[i] = int(inp2[i] + .1);
    }
    int d = inp[0];
    if (n > 1) d = inp[n - 1] - inp[n - 2];
    int ct = 0, ans;
    int range_size = d + 1006 - max(d - 1000, 1);
    check_outer_loop_invariant(range_size); // Check outer loop range size
    for (int i = max(d - 1000, 1); i < d + 1006; i++) {
        inp[n] = inp[n - 1] + i;
        if (fn()) {
            ct++;
            ans = inp[n];
        }
    }
    assert(ct != 0);
    if (ct == 1) {
        cout << "unique\n";
        cout << ans << endl;
    } else {
        cout << "not unique\n";
    }
    return 0;
}