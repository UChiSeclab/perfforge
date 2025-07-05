#include <bits/stdc++.h>
using namespace std;
const int INF = 1000 * 1000 * 1000 + 1000;

void check_iteration_invariant(int n) {
    if (n > 45) {
        cerr << "Warning: iteration_invariant triggered - excessive nested loop iterations" << endl;
        abort();
    }
}

void check_array_construction_invariant(int n) {
    if (n > 45) {
        cerr << "Warning: array_construction_invariant triggered - repeated vector construction" << endl;
        abort();
    }
}

void check_sorting_invariant(int n) {
    if (n > 45) {
        cerr << "Warning: sorting_invariant triggered - excessive sorting operations" << endl;
        abort();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    // Check invariants
    check_iteration_invariant(n);
    check_array_construction_invariant(n);
    check_sorting_invariant(n);

    n *= 2;
    int mas[n];
    for (int i = 0; i < n; i++) cin >> mas[i];
    sort(mas, mas + n);
    int best = INF;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            vector<int> v;
            for (int k = 0; k < n; k++) {
                if (k != i && k != j) v.push_back(mas[k]);
            }
            sort(v.begin(), v.end());
            int sum = 0;
            for (int k = 0; k < (int)v.size(); k += 2) {
                int x = v[k + 1] - v[k];
                sum += x;
            }
            best = min(best, sum);
        }
    }
    cout << best;
    return 0;
}