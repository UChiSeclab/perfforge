#include <bits/stdc++.h>
using namespace std;

long long int n, k, l;
vector<vector<long long int> > adj;
vector<bool> visited;
long long int d[100006] = {INT_MAX};
long long int MOD = 1000000007;
long long int level[100006];
long long int dis2[100006];
long long int degree[100006] = {0};

void check_bfs_traversal(int bfsCount, int n) {
    if (bfsCount > n * 2) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive BFS traversal!" << endl;
        abort();
    }
}

void check_k_value(long long k, long long n) {
    if (k > n / 2) {
        cerr << "Warning: Performance bottleneck condition triggered - large k value!" << endl;
        abort();
    }
}

void check_high_degree(const vector<long long>& degree, int n) {
    int highDegreeCount = 0;
    for (int i = 1; i <= n; ++i) {
        if (degree[i] > 3) {
            highDegreeCount++;
        }
    }
    if (highDegreeCount > n / 10) {
        cerr << "Warning: Performance bottleneck condition triggered - many high-degree vertices!" << endl;
        abort();
    }
}

long long int distance(long long int x) {
    long long int last = x;
    for (long long int j = 1; j <= n; j++) d[j] = INT_MAX;
    queue<long long int> q;
    q.push(x);
    d[x] = 0;
    long long int node = x;
    int bfsCount = 0; // Tracking BFS operations
    while (!q.empty()) {
        node = q.front();
        q.pop();
        bfsCount++;
        for (auto it : adj[node]) {
            if (d[it] > (d[node] + 1)) {
                d[it] = d[node] + 1;
                q.push(it);
            }
        }
    }
    check_bfs_traversal(bfsCount, n); // Check BFS traversal bottleneck
    return node;
}

void get_farthest2(int node) {
    int i;
    for (i = 0; i <= 100001; i++) {
        dis2[i] = MOD;
    }
    dis2[node] = 0;
    queue<int> q;
    q.push(node);
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (auto it : adj[x]) {
            if (dis2[it] > (dis2[x] + 1)) {
                dis2[it] = dis2[x] + 1;
                q.push(it);
            }
        }
    }
}

int main() {
    for (long long int i = 0; i <= 100001; i++) {
        level[i] = MOD;
        degree[i] = 0;
    }
    long long int i, a, b;
    cin >> n >> k;

    check_k_value(k, n); // Check k value bottleneck

    if (n == 1) {
        cout << "No" << endl;
        return 0;
    }
    adj.resize(n + 1);
    long long int center = 0;
    for (i = 1; i < n; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        degree[a]++;
        degree[b]++;
    }

    check_high_degree(degree, n); // Check high degree bottleneck

    long long int x = distance(1);
    long long int y = distance(x);
    get_farthest2(y);
    
    long long int ans = 1;
    if ((d[y] % 2 == 1) || k > n || (dis2[x] % 2 == 1)) {
        cout << "No" << endl;
        return 0;
    }
    for (i = 1; i <= n; i++)
        if ((d[i] == dis2[i]) && (adj[i].size() >= 3) && (d[i] == (d[y] / 2))) {
            center = i;
            break;
        }
    if (center == 0) {
        cout << "No" << endl;
        return 0;
    }
    queue<int> qu;
    long long int centre = center;
    qu.push(centre);
    level[centre] = 1;
    while (!qu.empty()) {
        int xx = qu.front();
        qu.pop();
        if (xx == centre && degree[xx] < 3) {
            cout << "No";
            return 0;
        } else if ((degree[xx] < 4) && (level[xx] <= k) && (xx != centre)) {
            cout << "No";
            return 0;
        } else if (level[xx] > k && degree[xx] != 1) {
            cout << "No";
            return 0;
        }
        for (auto it : adj[xx]) {
            if (level[it] > level[xx] + 1) {
                level[it] = level[xx] + 1;
                qu.push(it);
            }
        }
    }
    cout << "Yes" << endl;
    return 0;
}