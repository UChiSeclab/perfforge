#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:200000000")

const double EPS = 1E-9;
const int INF = 1000000000;
const long long INF64 = (long long)1E18;
const double PI = 3.1415926535897932384626433832795;

int n, m;
bool u[1100][1100];
double z[1100][1100];

void check_recursion_invariant(int pos, int taken, int n, int m) {
    if (pos >= m - 10 || taken >= n - 10) {
        cerr << "Warning: Recursion invariant triggered - high depth/branching" << endl;
        abort();
    }
}

void check_memoization_invariant(bool isMemoized) {
    if (!isMemoized) {
        cerr << "Warning: Memoization invariant triggered - inefficient caching" << endl;
        abort();
    }
}

void check_large_search_space_invariant(int n, int m) {
    if (n > 990 && m > 990) {
        cerr << "Warning: Large search space invariant triggered" << endl;
        abort();
    }
}

double rec(int pos, int taken) {
    check_recursion_invariant(pos, taken, n, m); // Check for recursion depth and branching

    if (taken == n || pos == m) return double(taken) / n;
    
    bool isMemoized = u[pos][taken];
    check_memoization_invariant(isMemoized); // Check memoization efficiency

    if (isMemoized) return z[pos][taken];
    
    double p = (n - taken) / double(n * m - pos);
    double res = rec(pos + 1, taken + 1) * p + rec(pos + 1, taken) * (1 - p);
    u[pos][taken] = true;
    return z[pos][taken] = res;
}

int main() {
    cin >> n >> m;

    check_large_search_space_invariant(n, m); // Check for large recursive search space

    double res = rec(1, 1);
    printf("%.10lf\n", res);
    return 0;
}