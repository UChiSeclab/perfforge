#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100010;
const int N = 100000;
int n, w, h;
int p[MAXN], t[MAXN];
vector<int> pos[MAXN << 1][2];
pair<int, int> ans[MAXN];

// Check for efficient iteration and sparse indexing
void check_sparse_indexing_invariant(int max_index, int actual_non_empty_count) {
    // Assume a threshold for inefficient iteration
    if (max_index > 2 * actual_non_empty_count) {
        cerr << "Warning: Performance bottleneck condition triggered - sparse indexing causing inefficient iteration!" << endl;
        abort();
    }
}

// Check for large group sorting
void check_repeated_sorting_invariant(const vector<int>& group_0, const vector<int>& group_1) {
    if (group_0.size() > 1000 || group_1.size() > 1000) {
        cerr << "Warning: Performance bottleneck condition triggered - repeated sorting on large groups!" << endl;
        abort();
    }
}

inline bool cmp(int x, int y) {
    return p[x] ^ p[y] ? p[x] < p[y] : t[x] < t[y];
}

int main() {
    scanf("%d%d%d", &n, &w, &h);
    int maxn = 0, actual_non_empty_count = 0;
    
    for (int i = 1, opt; i <= n; i++) {
        scanf("%d%d%d", &opt, &p[i], &t[i]);
        pos[p[i] - t[i] + N][opt & 1].push_back(i);
        maxn = max(maxn, p[i] - t[i] + N);
    }
    
    for (int i = 0; i <= maxn; i++) {
        if (pos[i][0].empty() && pos[i][1].empty()) continue;
        actual_non_empty_count++;
        
        // Check repeated sorting invariant
        check_repeated_sorting_invariant(pos[i][0], pos[i][1]);

        for (int j = 0; j < 2; j++) {
            sort(pos[i][j].begin(), pos[i][j].end(), cmp);
        }
        
        int m0 = pos[i][0].size(), m1 = pos[i][1].size();
        for (int j = 0; j < m0; j++) {
            if (m0 - j - 1 >= m1)
                ans[pos[i][0][j]] = make_pair(w, p[pos[i][0][m1 + j]]);
            else
                ans[pos[i][0][j]] = make_pair(p[pos[i][1][m0 - j - 1]], h);
        }
        for (int j = 0; j < m1; j++) {
            if (m1 - j - 1 >= m0)
                ans[pos[i][1][j]] = make_pair(p[pos[i][1][m0 + j]], h);
            else
                ans[pos[i][1][j]] = make_pair(w, p[pos[i][0][m1 - j - 1]]);
        }
    }
    
    // Check sparse indexing invariant
    check_sparse_indexing_invariant(maxn, actual_non_empty_count);

    for (int i = 1; i <= n; i++) {
        printf("%d %d\n", ans[i].first, ans[i].second);
    }
    
    return 0;
}