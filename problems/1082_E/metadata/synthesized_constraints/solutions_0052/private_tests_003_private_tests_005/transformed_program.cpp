#include <bits/stdc++.h>
using namespace std;

int v[500010], st[500010], dr[500010], d[500010];
vector<int> poz[500010];

// Check for high maximum value iteration
void check_max_value_iteration_invariant(int maxx, const vector<int>& unique_values) {
    if (maxx > 2 * unique_values.size()) {
        cerr << "Warning: Performance bottleneck condition triggered - high max value iteration!" << endl;
        abort();
    }
}

// Check for sparse target element distribution
void check_sparse_target_distribution_invariant(int target_count, int n) {
    if (target_count < n / 10) { // Assuming a threshold where c is less than 10% of array
        cerr << "Warning: Performance bottleneck condition triggered - sparse target element distribution!" << endl;
        abort();
    }
}

// Check for inefficient population mapping
void check_population_mapping_invariant(const vector<int>& values, int n) {
    int non_existent_count = 0;
    for (int i = 1; i <= n; ++i) {
        if (values[i] == 0) {
            non_existent_count++;
        }
    }
    if (non_existent_count > n / 2) { // More than half of possible values are non-existent
        cerr << "Warning: Performance bottleneck condition triggered - inefficient population mapping!" << endl;
        abort();
    }
}

int main() {
    int n, c, maxx = 0;
    scanf("%d%d", &n, &c);
    
    set<int> unique_values;  // To keep track of unique values

    for (int i = 1; i <= n; i++) {
        scanf("%d", &v[i]);
        poz[v[i]].push_back(i);
        st[i] = st[i - 1];
        if (v[i] == c) st[i]++;
        maxx = max(maxx, v[i]);
        unique_values.insert(v[i]);
    }

    // Check invariants after input processing
    check_max_value_iteration_invariant(maxx, vector<int>(unique_values.begin(), unique_values.end()));
    check_sparse_target_distribution_invariant(st[n], n);
    check_population_mapping_invariant(v, n);

    for (int i = n; i >= 1; i--) {
        dr[i] = dr[i + 1];
        if (v[i] == c) dr[i]++;
    }

    int sol = dr[1];
    for (int i = 1; i <= maxx; i++) {
        if (i == c) continue;
        if (poz[i].size() == 0) continue;
        d[poz[i][0]] = st[poz[i][0]] + 1;
        sol = max(sol, d[poz[i][0]] + dr[poz[i][0] + 1]);
        for (int j = 1; j < poz[i].size(); j++) {
            int pozz = poz[i][j];
            d[pozz] = max(st[pozz] + 1, d[poz[i][j - 1]] + 1);
            sol = max(sol, d[pozz] + dr[pozz + 1]);
        }
    }
    printf("%d", sol);
    return 0;
}