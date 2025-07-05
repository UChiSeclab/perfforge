#include <bits/stdc++.h>
using namespace std;

const int N = 10;
const int inf = 1 << 29;
int d[N][N];

int loop(function<bool()> ok, function<void()> increment, function<void()> work) {
    return ok() ? work(), increment(), loop(ok, increment, work) : 0;
}

void check_triple_loop_complexity(int n) {
    if (n >= 9) {  // Assuming n close to its upper bound as a trigger
        cerr << "Warning: Performance bottleneck condition triggered - high complexity in triple nested loop!" << endl;
        abort();
    }
}

void check_sparse_connection(int d[N][N], int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (d[i][j] > 90) {  // Threshold for large weights
                cerr << "Warning: Performance bottleneck condition triggered - large edge weights may cause inefficiency!" << endl;
                abort();
            }
        }
    }
}

void check_dense_graph_effects(int n) {
    if (n > 8) {  // Assumes a dense graph with nearly maximum vertices
        cerr << "Warning: Performance bottleneck condition triggered - dense graph with large n!" << endl;
        abort();
    }
}

int main() {
    int n;
    scanf("%d", &n);

    // Checkers placed after reading the input size
    check_triple_loop_complexity(n);
    check_dense_graph_effects(n);

    {
        int i = 0;
        loop([&]() -> bool { return i < n; }, [&]() { ++i; },
             [&]() {
                 int j = 0;
                 loop([&]() -> bool { return j < n; }, [&]() { ++j; },
                      [&]() { scanf("%d", d[i] + j); });
             });
    }

    // Check after input has been read
    check_sparse_connection(d, n);

    {
        int k = 0;
        loop([&]() -> bool { return k < n; }, [&]() { ++k; },
             [&]() {
                 int i = 0;
                 loop([&]() -> bool { return i < n; }, [&]() { ++i; },
                      [&]() {
                          int j = 0;
                          loop([&]() -> bool { return j < n; }, [&]() { ++j; },
                               [&]() { d[i][j] = min(d[i][j], d[i][k] + d[k][j]); });
                      });
             });
    }

    int ans = 0;
    {
        int i = 0;
        loop([&]() -> bool { return i < n; }, [&]() { ++i; },
             [&]() {
                 int j = 0;
                 loop([&]() -> bool { return j < n; }, [&]() { ++j; },
                      [&]() { ans = max(ans, d[i][j]); });
             });
    }

    printf("%d\n", ans);
    return 0;
}