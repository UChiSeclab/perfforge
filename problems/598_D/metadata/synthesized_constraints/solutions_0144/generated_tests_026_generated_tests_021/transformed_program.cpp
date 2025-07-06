#include <bits/stdc++.h>
using namespace std;

int n, m, k, arr_x[] = {1, -1, 0, 0}, arr_y[] = {0, 0, 1, -1}, cevap[1005][1005];
char arr[1005][1005];
bool visited[1005][1005], vis[1005][1005];
int dfs_call_count = 0;
int esitle_call_count = 0;
set<pair<int, int>> visited_queries;

bool check(int x, int y) {
    if (x < 0 || x >= n) return false;
    if (y < 0 || y >= m) return false;
    return true;
}

void check_dfs_invariant() {
    if (dfs_call_count > 10000) {  // Example threshold; adjust based on expected patterns
        cerr << "Warning: dfs_invariant triggered - excessive DFS calls" << endl;
        abort();
    }
}

void check_esitle_invariant() {
    if (esitle_call_count > 5000) {  // Example threshold; adjust for real-world patterns
        cerr << "Warning: esitle_invariant triggered - excessive state propagation" << endl;
        abort();
    }
}

void check_request_density(int x, int y) {
    auto result = visited_queries.insert({x, y});
    if (!result.second) {  // If insertion failed, it means this query was repeated
        cerr << "Warning: density_invariant triggered - repeated queries to same region" << endl;
        abort();
    }
}

int dfs(int x, int y) {
    dfs_call_count++;
    check_dfs_invariant();

    visited[x][y] = true;
    for (int i = 0; i < 4; i++) {
        int cur_x = x + arr_x[i], cur_y = y + arr_y[i];
        if (check(cur_x, cur_y) && arr[cur_x][cur_y] == '.' && visited[cur_x][cur_y] == false) {
            cevap[x][y] += dfs(cur_x, cur_y);
        } else if (check(cur_x, cur_y) && arr[cur_x][cur_y] == '*') {
            cevap[x][y]++;
        }
    }
    return cevap[x][y];
}

void esitle(int x, int y, int xx, int yy) {
    esitle_call_count++;
    check_esitle_invariant();

    vis[x][y] = true;
    cevap[x][y] = cevap[xx][yy];
    for (int i = 0; i < 4; i++) {
        int cur_x = arr_x[i] + x, cur_y = arr_y[i] + y;
        if (check(cur_x, cur_y) && arr[cur_x][cur_y] == '.' && vis[cur_x][cur_y] == false)
            esitle(cur_x, cur_y, xx, yy);
    }
}

int main() {
    vector<pair<int, int>> vec;
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == '.') vec.push_back({i, j});
        }
    }
    for (int i = 0; i < vec.size(); i++) {
        int x = vec[i].first, y = vec[i].second;
        if (visited[x][y] == false) {
            dfs(x, y);
            esitle(x, y, x, y);
        }
    }
    while (k--) {
        int x, y;
        cin >> x >> y;
        check_request_density(--x, --y);
        cout << cevap[x][y] << endl;
    }
    return 0;
}