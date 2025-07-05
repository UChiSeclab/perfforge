#include <bits/stdc++.h>
using namespace std;

// Checker function for recursion depth and breadth
void check_recursive_depth_breadth(int x, int y, int m) {
    if (x > m && y > 10) {  // Arbitrary threshold for depth and breadth
        cerr << "Warning: Performance bottleneck condition triggered due to excessive recursion depth and breadth!" << endl;
        abort();
    }
}

// Checker function for memoization efficiency
void check_memoization_efficiency(int x, int y, const int* v) {
    if (v[x] && v[x] < y) {
        cerr << "Warning: Performance bottleneck condition triggered due to ineffective memoization!" << endl;
        abort();
    }
}

// Checker function for exponential growth of recursive calls
void check_exponential_growth(int x, int m) {
    if (x > 2 * m) {  // Arbitrary condition indicating potential exponential growth
        cerr << "Warning: Performance bottleneck condition triggered due to exponential growth of recursive calls!" << endl;
        abort();
    }
}

int n, m, v[300000];
int dfs(int x, int y) {
    check_recursive_depth_breadth(x, y, m);  // Checking depth and breadth invariant
    check_memoization_efficiency(x, y, v);   // Checking memoization efficiency

    if (x == m) {
        return y;
    } else if (x < 0 || x >= 30005 || v[x] && v[x] < y) {
        return 30005;
    }
    v[x] = y;
    check_exponential_growth(x, m);  // Checking for exponential growth of recursive calls
    return min(dfs(2 * x, y + 1), dfs(x - 1, y + 1));
}

int main(int argc, char** argv) {
    cin >> n >> m;
    cout << dfs(n, 0) << endl;
    return 0;
}