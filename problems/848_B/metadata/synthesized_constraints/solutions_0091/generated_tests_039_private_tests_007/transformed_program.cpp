#include <bits/stdc++.h>
using namespace std;

// Threshold values based on reasonable assumptions for this problem
const int SORTING_THRESHOLD = 1000; // Example threshold for sorting range
const int MX_THRESHOLD = 1000; // Example threshold for mx
const int VECTOR_OP_THRESHOLD = 1000; // Example threshold for vector operation size

vector<pair<int, int> > px[200010], py[200010];
const int N = 1e5 + 1;
pair<int, int> ans[200010], P[200010];

// Function to check sorting invariant
void check_sorting_invariant(int range, int threshold) {
    if (range > threshold) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive sorting range!" << endl;
        abort();
    }
}

// Function to check index range invariant
void check_index_range_invariant(int mx, int threshold) {
    if (mx > threshold) {
        cerr << "Warning: Performance bottleneck condition triggered - large mx leading to excessive operations!" << endl;
        abort();
    }
}

// Function to check vector operations invariant
void check_vector_operations_invariant(int px_size, int py_size, int threshold) {
    if (px_size > threshold || py_size > threshold) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive operations on vectors!" << endl;
        abort();
    }
}

int main() {
    int n, w, h;
    cin >> n >> w >> h;
    int mx = 0;
    for (int i = 1; i <= n; i++) {
        int g, p, t;
        scanf("%d %d %d", &g, &p, &t);
        if (g == 1)
            px[p - t + N].push_back(pair<int, int>(p, i));
        else
            py[p - t + N].push_back(pair<int, int>(p, i));
        mx = max(mx, p - t + N);
    }

    // Check the index range invariant
    check_index_range_invariant(mx, MX_THRESHOLD);

    for (int i = 1; i <= mx; i++) {
        // Check sorting invariant before sorting
        if (!px[i].empty()) {
            check_sorting_invariant(px[i].size(), SORTING_THRESHOLD);
            sort(px[i].begin(), px[i].end());
        }
        if (!py[i].empty()) {
            check_sorting_invariant(py[i].size(), SORTING_THRESHOLD);
            sort(py[i].begin(), py[i].end());
        }
    }

    for (int i = 1; i <= mx; i++) {
        int nn = 0;
        for (auto p : px[i]) {
            P[++nn] = pair<int, int>(p.first, h);
        }
        for (int j = py[i].size() - 1; j >= 0; j--)
            P[++nn] = pair<int, int>(w, py[i][j].first);

        // Check vector operations invariant
        check_vector_operations_invariant(px[i].size(), py[i].size(), VECTOR_OP_THRESHOLD);

        for (int j = px[i].size() - 1; j >= 0; j--) {
            int id = px[i][j].second;
            ans[id] = P[nn--];
        }
        for (auto p : py[i]) {
            int id = p.second;
            ans[id] = P[nn--];
        }
    }
    for (int i = 1; i <= n; i++) printf("%d %d\n", ans[i].first, ans[i].second);
    return 0;
}