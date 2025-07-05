#include <bits/stdc++.h>
using namespace std;

void check_nested_loop_invariant(int iterationCount, int threshold) {
    if (iterationCount > threshold) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive nested loop iterations!" << endl;
        abort();
    }
}

void check_point_evaluation_invariant(int evaluations, int threshold) {
    if (evaluations > threshold) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive point evaluations!" << endl;
        abort();
    }
}

void solve() {
    int n;
    cin >> n;
    vector<pair<long long, long long>> v;
    for (int i = 1; i <= 4 * n + 1; i++) {
        int x, y;
        cin >> x >> y;
        v.push_back({x, y});
    }
    
    int iterationCount = 0; // Counter for nested loop iterations
    int evaluationCount = 0; // Counter for point evaluations

    for (int lx = 0; lx <= 50; lx++) {
        for (int ly = 0; ly <= 50; ly++) {
            for (int ux = lx + 1; ux <= 50; ux++) {
                for (int uy = ly + 1; uy <= 50; uy++) {
                    iterationCount++;
                    vector<pair<long long, long long>> res;
                    for (auto it : v) {
                        evaluationCount++;
                        if ((it.first == lx || it.first == ux) && it.second >= ly && it.second <= uy) {
                        } else if ((it.second == ly || it.second == uy) && it.first >= lx && it.first <= ux) {
                        } else {
                            res.push_back(it);
                        }
                    }
                    
                    // Check for excessive iterations and evaluations
                    check_nested_loop_invariant(iterationCount, 1000000); // Arbitrary large threshold
                    check_point_evaluation_invariant(evaluationCount, 5000000); // Arbitrary large threshold
                    
                    if (res.size() == 1) {
                        cout << res[0].first << " " << res[0].second << endl;
                        return;
                    }
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    while (t--) solve();
}