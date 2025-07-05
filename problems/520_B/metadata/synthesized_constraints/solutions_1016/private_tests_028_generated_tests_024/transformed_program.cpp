#include <bits/stdc++.h>
using namespace std;

int dist[60010];
int n, m, inf;

// Checker functions for performance invariants
void check_inefficient_bellman_process(int n, int m) {
    if (m > n && m > n * log2(m)) {
        cerr << "Warning: Inefficient Bellman process triggered! Large disparity between m and n." << endl;
        abort();
    }
}

void check_unnecessary_full_range_exploration(int n, int m) {
    if (m > 2 * n) {
        cerr << "Warning: Unnecessary full range exploration detected!" << endl;
        abort();
    }
}

void check_quadratic_complexity(int n, int m) {
    if (m > 1000 && n < m / 100) {
        cerr << "Warning: Quadratic complexity path likely triggered due to large m and small n." << endl;
        abort();
    }
}

void bellman(int s) {
    int size = 2 * m;
    for (int i = 0; i < size; i++) dist[i] = inf;
    dist[s] = 0;
    for (int i = 0; i < size - 1; i++) {
        for (int j = 1; j < size; j++) {
            if (dist[j] + 1 < dist[j * 2]) dist[j * 2] = dist[j] + 1;
            if (dist[j] + 1 < dist[j - 1]) dist[j - 1] = dist[j] + 1;
        }
    }
}

int main() {
    cin >> n >> m;

    // Check for performance bottlenecks
    check_inefficient_bellman_process(n, m);
    check_unnecessary_full_range_exploration(n, m);
    check_quadratic_complexity(n, m);

    if (n > m) {
        cout << n - m << endl;
        return 0;
    }

    unsigned int t = -1;
    inf = 1 << 30;
    bellman(n);
    cout << dist[m] << endl;

    return 0;
}