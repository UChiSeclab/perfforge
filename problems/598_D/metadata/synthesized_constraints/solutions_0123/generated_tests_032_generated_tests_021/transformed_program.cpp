#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> arr;
int n, m, k, last_number = 1;
unordered_map<int, int> ans;

bool inside(int y, int x) {
    return (y >= 0 && y < n && x >= 0 && x < m);
}

void check_dense_unexplored_regions(int overlap_count) {
    if (overlap_count > 10) {
        cerr << "Warning: Performance bottleneck due to dense unexplored regions triggered!" << endl;
        abort();
    }
}

void check_high_connectivity_areas(int explored_area_size) {
    if (explored_area_size > 50) {
        cerr << "Warning: Performance bottleneck due to high connectivity areas triggered!" << endl;
        abort();
    }
}

void check_redundant_starting_points(int starting_point_overlap_count) {
    if (starting_point_overlap_count > 30) {
        cerr << "Warning: Performance bottleneck due to redundant starting points triggered!" << endl;
        abort();
    }
}

int bfs(int y, int x) {
    int walls = 0, area_size = 0;
    queue<pair<int, int>> q;
    q.push({y, x});
    
    while (!q.empty()) {
        y = q.front().first, x = q.front().second;
        q.pop();
        
        if (arr[y][x] != -1) continue;
        
        arr[y][x] = last_number;
        area_size++; // Count the explored area
        
        for (int dr : {-1, 0, 1}) {
            for (int dc : {-1, 0, 1}) {
                if (abs(dr) == abs(dc)) continue;
                
                int new_row = y + dr;
                int new_col = x + dc;
                
                if (inside(new_row, new_col)) {
                    if (arr[new_row][new_col] == 0)
                        walls++;
                    else if (arr[new_row][new_col] == -1)
                        q.push({new_row, new_col});
                }
            }
        }
    }
    
    check_high_connectivity_areas(area_size);
    ans[last_number] = walls;
    last_number++;
    return walls;
}

int main() {
    cin >> n >> m >> k;
    arr = vector<vector<int>>(n, vector<int>(m, -1));
    
    for (int i = 0; i < n; i++) {
        string x;
        cin >> x;
        
        for (int j = 0; j < m; j++)
            if (x[j] == '*') arr[i][j] = 0;
    }

    vector<pair<int, int>> starting_positions;
    unordered_set<int> processed_positions;
    int overlap_count = 0;
    
    while (k--) {
        int y, x;
        cin >> y >> x;
        y--, x--;
        
        starting_positions.push_back({y, x});
        int arr_value = arr[y][x];
        
        if (ans.find(arr_value) != ans.end()) {
            cout << ans[arr_value] << endl;
            if (processed_positions.find(arr_value) != processed_positions.end()) {
                overlap_count++;
            }
            processed_positions.insert(arr_value);
        }
        else {
            cout << bfs(y, x) << endl;
        }
    }
    
    check_dense_unexplored_regions(overlap_count);
    check_redundant_starting_points(processed_positions.size());
    
    return 0;
}