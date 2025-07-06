#include <bits/stdc++.h>
using namespace std;

// Function to check for high number of stations
void check_path_finding_invariant(int n) {
    if (n >= 90) {
        cerr << "Warning: Performance bottleneck condition triggered - high number of stations!" << endl;
        abort();
    }
}

// Function to check for excessive recalculations
void check_recalculation_invariant(int recalculations, int threshold = 10000) {
    if (recalculations > threshold) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive recalculations!" << endl;
        abort();
    }
}

// Function to check for inefficient nested loops
void check_looping_structure_invariant(int n) {
    if (n >= 90) {
        cerr << "Warning: Performance bottleneck condition triggered - inefficient nested loops!" << endl;
        abort();
    }
}

bool can(int& n, int& d, vector<int>& a, vector<int>& x, vector<int>& y, int t) {
    vector<int> maxTime(n, -1);
    maxTime[0] = t;
    int recalculations = 0; // Track number of recalculations
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            if (maxTime[i] < 0) continue;
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                maxTime[j] = max(maxTime[j], maxTime[i] - d * (abs(x[i] - x[j]) + abs(y[i] - y[j])) + a[j]);
                recalculations++;
            }
        }
    }
    check_recalculation_invariant(recalculations); // Check recalculations after loops
    return (maxTime[n - 1] >= 0);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, d;
    cin >> n >> d;
    
    check_path_finding_invariant(n); // Check number of stations early in the program

    vector<int> a(n);
    for (int i = 1; i + 1 < n; i++) cin >> a[i];
    vector<int> x(n), y(n);
    for (int i = 0; i < n; i++) cin >> x[i] >> y[i];

    int lo = 0, hi = int(2e9), mi;
    while (lo <= hi) {
        mi = (lo + hi) / 2;
        if (!can(n, d, a, x, y, mi))
            lo = mi + 1;
        else
            hi = mi - 1;
    }

    cout << lo << "\n";
    return 0;
}