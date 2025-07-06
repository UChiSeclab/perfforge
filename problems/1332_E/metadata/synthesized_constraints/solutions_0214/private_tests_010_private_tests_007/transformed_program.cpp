#include <bits/stdc++.h>
using namespace std;

// Checker function for grid size
void check_large_grid_size(int n, int m) {
    if (n > 1000000 && m > 1000000) {
        cerr << "Warning: Performance bottleneck condition triggered - large grid size!" << endl;
        abort();
    }
}

// Checker function for recursive depth
void check_recursive_depth(int n, int m) {
    if ((n > 1000000 || m > 1000000) && (n % 2 == 1 || m % 2 == 1)) {
        cerr << "Warning: Performance bottleneck condition triggered - high recursion depth!" << endl;
        abort();
    }
}

// Checker function for unbounded problem size
void check_unbounded_problem_size(int n, int m) {
    if (n * m > 1000000000) {
        cerr << "Warning: Performance bottleneck condition triggered - unbounded problem size!" << endl;
        abort();
    }
}

void getdp(int n, unordered_map<int, long long>& col_odd,
           unordered_map<int, long long>& col_even) {
    if (col_odd.find(n) != col_odd.end()) return;
    if (n == 1) {
        col_even[n] = R / 2 - (L + 1) / 2 + 1;
        col_odd[n] = R - L + 1 - col_even[n];
        col_even[n] %= 998244353LL;
        col_odd[n] %= 998244353LL;
    } else {
        getdp(n / 2, col_odd, col_even);
        if (n % 2) getdp(n - n / 2, col_odd, col_even);
        col_odd[n] = ((col_odd[n / 2] * col_even[n - n / 2]) % 998244353LL +
                      (col_even[n / 2] * col_odd[n - n / 2]) % 998244353LL) %
                     998244353LL;
        col_even[n] = ((col_odd[n / 2] * col_odd[n - n / 2]) % 998244353LL +
                       (col_even[n / 2] * col_even[n - n / 2]) % 998244353LL) %
                      998244353LL;
    }
}

void getdp2(int m, unordered_map<int, long long>& odd,
            unordered_map<int, long long>& even) {
    if (odd.find(m) != odd.end()) return;
    getdp2(m / 2, odd, even);
    if (m % 2) getdp2(m - m / 2, odd, even);
    odd[m] = ((odd[m / 2] * even[m - m / 2]) % 998244353LL +
              (even[m / 2] * odd[m - m / 2]) % 998244353LL) %
             998244353LL;
    even[m] = ((odd[m / 2] * odd[m - m / 2]) % 998244353LL +
               (even[m / 2] * even[m - m / 2]) % 998244353LL) %
              998244353LL;
}

long long doit(long long n, long long m) {
    unordered_map<int, long long> col_odd, col_even;
    getdp(n, col_odd, col_even);
    unordered_map<int, long long> odd, even;
    odd[1] = col_odd[n];
    even[1] = col_even[n];
    getdp2(m, odd, even);
    return (m % 2 == 1 && n % 2 == 1) ? (even[m] + odd[m]) % 998244353LL
                                      : even[m];
}

int main(int argc, char* argv[]) {
    int n, m;
    scanf("%d%d", &n, &m);
    scanf("%lld%lld", &L, &R);

    // Insert checks after reading inputs
    check_large_grid_size(n, m);
    check_recursive_depth(n, m);
    check_unbounded_problem_size(n, m);

    printf("%lld\n", doit(n, m));
    return 0;
}