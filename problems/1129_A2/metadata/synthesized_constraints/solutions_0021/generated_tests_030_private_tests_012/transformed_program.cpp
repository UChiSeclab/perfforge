#include <bits/stdc++.h>
using namespace std;

int dist(int a, int b, int n) {
    if (a <= b) return b - a;
    return b + n - a;
}

// Checker functions
void check_distance_calculations_invariant(int n, int m) {
    if (m > n * 5) { // Arbitrary threshold: many candies relative to stations
        cerr << "Warning: Performance bottleneck condition triggered - Excessive distance calculations!" << endl;
        abort();
    }
}

void check_nested_loop_invariant(int n) {
    if (n > 3000) { // Threshold based on upper bound, considering n^2 operations
        cerr << "Warning: Performance bottleneck condition triggered - High iteration count in nested loops!" << endl;
        abort();
    }
}

void check_frequent_conditional_invariant(int numOfCandies, int numOfStations) {
    if (numOfCandies > numOfStations * 10) { // Estimating condition frequency
        cerr << "Warning: Performance bottleneck condition triggered - Frequent conditional evaluations!" << endl;
        abort();
    }
}

int main() {
    int n, m, i, a, b;
    cin >> n >> m;

    // Insert checkers after input
    check_distance_calculations_invariant(n, m);
    check_nested_loop_invariant(n);
    check_frequent_conditional_invariant(m, n);

    int mini[n], nume[n];
    for (i = 0; i < n; i++) {
        mini[i] = n + 3;
        nume[i] = 0;
    }

    for (i = 0; i < m; i++) {
        cin >> a >> b;
        a--;
        b--;
        nume[a]++;
        if (dist(a, b, n) < mini[a]) mini[a] = dist(a, b, n);
    }

    for (i = 0; i < n; i++) {
        a = 0;
        for (b = 0; b < n; b++) {
            if ((n * (nume[b] - 1) + mini[b] + dist(i, b, n) > a) && (nume[b] != 0)) {
                a = n * (nume[b] - 1) + mini[b] + dist(i, b, n);
            }
        }
        cout << a << " ";
    }
    return 0;
}