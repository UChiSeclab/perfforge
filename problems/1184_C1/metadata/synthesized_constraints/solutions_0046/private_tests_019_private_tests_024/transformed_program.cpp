#include <bits/stdc++.h>
using namespace std;

void check_search_space_invariant(int i, int j, int k) {
    if (i > 1 && j > 1 && k > 1) {
        cerr << "Warning: Performance bottleneck condition triggered - large search space." << endl;
        abort();
    }
}

void check_complex_condition_invariant(int evalCount) {
    if (evalCount > 1000000) { // Threshold chosen based on problem constraints and performance.
        cerr << "Warning: Performance bottleneck condition triggered - excessive condition evaluations." << endl;
        abort();
    }
}

void check_data_structure_invariant(int n) {
    if (n > 8) { // n close to its upper constraint implies intensive data access.
        cerr << "Warning: Performance bottleneck condition triggered - intensive data structure access." << endl;
        abort();
    }
}

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<pair<int, int>> ar(4 * n + 1);
    for (int i = 0; i < 4 * n + 1; i++) cin >> ar[i].first >> ar[i].second;

    check_data_structure_invariant(n);

    int evalCount = 0; // Counter for condition evaluations

    for (int i = 0; i < 51; i++) {
        for (int j = 0; j < 51; j++) {
            for (int k = 0; k < 51; k++) {
                check_search_space_invariant(i, j, k);

                int cnt = 0;
                pair<int, int> te;
                for (int l = 0; l < 4 * n + 1; l++) {
                    evalCount++;
                    if (!(ar[l].first == i + k || ar[l].first == i || ar[l].second == j ||
                          ar[l].second == j + k) ||
                        ar[l].first > i + k || ar[l].second > j + k || ar[l].first < i ||
                        ar[l].second < j) {
                        cnt++, te = ar[l];
                    }
                }

                check_complex_condition_invariant(evalCount);

                if (cnt == 1) {
                    cout << te.first << " " << te.second << "\n";
                    return 0;
                }
            }
        }
    }
}