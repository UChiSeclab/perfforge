#include <bits/stdc++.h>
using namespace std;

// Checker for high number of iterations with nested loops
void check_iteration_invariant(int n) {
    if (n >= 4900) { // Threshold close to the upper constraint for n
        cerr << "Warning: Performance bottleneck condition triggered - excessive iterations with large n!" << endl;
        abort();
    }
}

// Checker for complex conditional structures within iterations
void check_conditional_invariant(int m) {
    if (m >= 19000) { // Threshold close to the upper constraint for m
        cerr << "Warning: Performance bottleneck condition triggered - complex conditional structures with large m!" << endl;
        abort();
    }
}

// Checker for handling of temporary structures
void check_temp_structure_invariant(int n, const vector<vector<long long>>& station) {
    for (const auto& st : station) {
        if (st.size() > 1000 && n >= 4900) { // Arbitrary threshold for station size
            cerr << "Warning: Performance bottleneck condition triggered - excessive operations on temporary structures!" << endl;
            abort();
        }
    }
}

int n, m;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    
    // Insert performance checkers
    check_iteration_invariant(n);
    check_conditional_invariant(m);

    vector<vector<long long> > station(n, vector<long long>(0));
    for (long long i = 0; i < m; i++) {
        long long a, b;
        cin >> a >> b;
        a--;
        b--;
        if (b > a) {
            station[a].push_back(b - a);
        } else {
            station[a].push_back(n - (a - b));
        }
    }
    
    // Check the size of temporary structures
    check_temp_structure_invariant(n, station);

    long long ms = 0;
    for (long long i = 0; i < n; i++) {
        ms = max((long long)station[i].size(), ms);
        sort(station[i].begin(), station[i].end());
    }
    for (long long i = 0; i < n; i++) {
        long long torem = max(0ll, ms - 2);
        while (station[i].size() && torem > 0) {
            torem--;
            station[i].pop_back();
        }
    }
    for (long long s = 0; s < n; s++) {
        vector<vector<long long> > temp = station;
        long long curdis = 0;
        long long dis = 0;
        for (long long i = s; i < s + 3 * n; i++) {
            if (temp[i % n].size()) {
                dis = max(curdis + temp[i % n].back(), dis);
                temp[i % n].pop_back();
            }
            curdis++;
        }
        cout << dis + max(ms - 2, 0ll) * n << ' ';
    }
    cout << '\n';
}