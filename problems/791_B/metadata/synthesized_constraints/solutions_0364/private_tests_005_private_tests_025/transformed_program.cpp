#include <bits/stdc++.h>
using namespace std;

// Checker for high node count with no connections
void check_high_node_no_connection(bool condition) {
    if (condition) {
        cerr << "Warning: High node count with no connections!" << endl;
        abort();
    }
}

// Checker for repeated isolated node processing
void check_isolated_nodes(bool condition) {
    if (condition) {
        cerr << "Warning: Many isolated nodes leading to expensive DFS calls!" << endl;
        abort();
    }
}

// Checker for inefficient handling of sparse graphs
void check_sparse_graph(bool condition) {
    if (condition) {
        cerr << "Warning: Sparse graph causing inefficient processing!" << endl;
        abort();
    }
}

void dfs(map<int, vector<int>> &mp, int &s, vector<bool> &visited, long long int &c2, long long int &count) {
    stack<int> stack;
    stack.push(s);
    while (!stack.empty()) {
        s = stack.top();
        stack.pop();
        if (!visited[s]) {
            c2++;
            count += mp[s].size();
            visited[s] = true;
            for (int i = 0; i < mp[s].size(); i++) {
                if (!visited[mp[s][i]]) stack.push(mp[s][i]);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int i, n, m, j, x, y;
    scanf("%d%d", &n, &m);
    map<int, vector<int>> mp;
  
    for (i = 0; i < m; i++) {
        scanf("%d%d", &x, &y);
        mp[x].push_back(y);
        mp[y].push_back(x);
    }

    // Check for high node count with no connections
    check_high_node_no_connection(n > 100000 && m == 0);
  
    // Check for sparse graph situation
    check_sparse_graph(n > 100000 && m < n / 10);

    int f = 0;
    vector<bool> visited(n + 1, false);
    for (i = 1; i <= n; i++) {
        if (!visited[i]) {
            long long int c2 = 0, count = 0;
            dfs(mp, i, visited, c2, count);
            if (count != (c2 * (c2 - 1))) {
                puts("NO");
                f = 1;
                break;
            }
        }
    }
    if (f == 0) {
        puts("YES");
    }
    return 0;
}