#include <bits/stdc++.h>
using namespace std;

bool visited[100005 + 1];
vector<long long int> adj[100005 + 1];
long long int level[100005 + 1];
long long int ans = 0;

void initialize() {
    for (long long int i = 0; i <= 100005; i++) {
        visited[i] = false;
    }
}

// Function to check if initialization is optimized
void check_initialization_invariant(int n, int maxSize) {
    if (n > maxSize) {
        cerr << "Warning: initialization_invariant triggered - unoptimized array size" << endl;
        abort();
    }
}

// Function to check recursion depth or excessive branching
void check_dfs_invariant(int recursiveCalls, int threshold) {
    if (recursiveCalls > threshold) {
        cerr << "Warning: dfs_invariant triggered - excessive recursion depth or branching factor" << endl;
        abort();
    }
}

// Function to check for excessive graph components
void check_component_invariant(int components, int threshold) {
    if (components > threshold) {
        cerr << "Warning: component_invariant triggered - more than expected graph components" << endl;
        abort();
    }
}

void dfs(long long int i, int& recursiveCalls) {
    visited[i] = true;
    recursiveCalls++;
    for (auto it : adj[i]) {
        if (visited[it] == false) {
            dfs(it, recursiveCalls);
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    long long int n, m, x, y;
    cin >> n >> m;

    if (m != n - 1) {
        cout << "no" << endl;
        return 0;
    }

    // Check initialization invariant
    check_initialization_invariant(n, 1000);

    for (long long int i = 1; i <= m; i++) {
        cin >> x >> y;
        adj[y].push_back(x);
        adj[x].push_back(y);
    }

    long long int c = 0;
    initialize();

    for (long long int i = 1; i <= n; i++) {
        if (visited[i] == false) {
            int recursiveCalls = 0;
            dfs(i, recursiveCalls);

            // Check DFS invariant for deep recursion
            check_dfs_invariant(recursiveCalls, 100); // arbitrary threshold for demonstration

            c++;
            if (c > 1) {
                cout << "no" << endl;
                return 0;
            }
        }
    }

    // Check component invariant
    check_component_invariant(c, 1);

    cout << "yes" << endl;
}