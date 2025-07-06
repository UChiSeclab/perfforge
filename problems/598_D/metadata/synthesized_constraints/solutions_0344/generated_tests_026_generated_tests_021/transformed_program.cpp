#include <bits/stdc++.h>
using namespace std;

// Check if the DFS is exploring a large connected region
void check_large_region_invariant(int regionSize, int threshold) {
    if (regionSize > threshold) {
        cerr << "Warning: Performance bottleneck condition triggered - large connected region!" << endl;
        abort();
    }
}

// Check if there are repeated queries on the same region
void check_repeated_queries_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - repeated queries on the same region!" << endl;
        abort();
    }
}

// Check if a starting position is surrounded by a dense wall configuration
void check_dense_wall_invariant(int wallCount, int threshold) {
    if (wallCount > threshold) {
        cerr << "Warning: Performance bottleneck condition triggered - dense wall configuration!" << endl;
        abort();
    }
}

void dfs(int x, int y, vector<vector<int> >& g, vector<vector<bool> >& used,
         int& ans, vector<int>& kek) {
    // Count the number of walls adjacent to the starting position
    int wallCount = 0;
    if (g[y][x + 1] == -1) ans++, wallCount++;
    if (g[y][x - 1] == -1) ans++, wallCount++;
    if (g[y + 1][x] == -1) ans++, wallCount++;
    if (g[y - 1][x] == -1) ans++, wallCount++;
    
    check_dense_wall_invariant(wallCount, 4); // Check if surrounded by too many walls

    used[y][x] = true;
    kek.push_back(y);
    kek.push_back(x);

    if (g[y][x + 1] == 0 && (!used[y][x + 1])) dfs(x + 1, y, g, used, ans, kek);
    if (g[y][x - 1] == 0 && (!used[y][x - 1])) dfs(x - 1, y, g, used, ans, kek);
    if (g[y + 1][x] == 0 && (!used[y + 1][x])) dfs(x, y + 1, g, used, ans, kek);
    if (g[y - 1][x] == 0 && (!used[y - 1][x])) dfs(x, y - 1, g, used, ans, kek);

    // Check if the region size explored in DFS is too large
    check_large_region_invariant(kek.size() / 2, 1000); // Assuming 1000 as an arbitrary threshold
}

int main() {
    int n, m, k, ans = 0;
    cin >> n >> m >> k;
    vector<vector<int> > g(n, vector<int>(m));
    vector<vector<bool> > used(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char ch;
            cin >> ch;
            if (ch == '.') {
                g[i][j] = 0;
            } else {
                g[i][j] = -1;
            }
        }
    }
    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> y >> x;
        x--;
        y--;
        // Check if the current starting position has already been calculated
        bool repeatedQuery = used[y][x];
        check_repeated_queries_invariant(repeatedQuery);

        if (!used[y][x]) {
            vector<int> kek;
            dfs(x, y, g, used, ans, kek);
            cout << ans << endl;
            for (int j = 1; j < kek.size(); j += 2) {
                g[kek[j - 1]][kek[j]] = ans;
            }
            kek.clear();
            ans = 0;
        } else {
            cout << g[y][x] << endl;
        }
    }
}