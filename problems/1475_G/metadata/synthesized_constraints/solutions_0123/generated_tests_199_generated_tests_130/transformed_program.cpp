#include<bits/stdc++.h>
#define ull unsigned long long
#define ll int64_t 
#define f(i,s,e) for(i=s;i<e;++i)
#define endl << "\n"
#define sp << " "
#define INF INFINITY
#define mset(a,b) memset(a,b,sizeof(a))
#define mod 1000000007
#define mp(a,b) make_pair(a,b)
#define F first
#define S second
#define all(x) x.begin(),x.end()
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define PI acos(-1) 
#define pb(a) push_back(a)
#define pf(a) push_front(a)
#define eb(a) emplace_back(a)
#define print(x) for(auto it:x) cout<<it<<' '; cout<<"\n";

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
using namespace std;

// Performance checkers
void check_dfs_depth_invariant(int depthThreshold, int currentDepth) {
    if (currentDepth > depthThreshold) {
        cerr << "Warning: Performance bottleneck condition triggered due to high DFS depth!" << endl;
        abort();
    }
}

void check_adjacency_size_invariant(int adjacencySizeThreshold, int adjacencyListSize) {
    if (adjacencyListSize > adjacencySizeThreshold) {
        cerr << "Warning: Performance bottleneck condition triggered due to large adjacency list size!" << endl;
        abort();
    }
}

void check_max_value_invariant(int maxValueThreshold, int maxValue) {
    if (maxValue > maxValueThreshold) {
        cerr << "Warning: Performance bottleneck condition triggered due to large maximum element value!" << endl;
        abort();
    }
}

// Depth counter for DFS
int dfs_depth_counter = 0;

int dfs(vector <vector<int>>&adj, vector<bool>&visited, vector<int>&count, int node) {
    dfs_depth_counter++;  // Increase depth for each DFS call
    check_dfs_depth_invariant(100, dfs_depth_counter);  // Check DFS depth

    int i = 0;
    visited[node] = true;
    for(auto v : adj[node]) {
        if(visited[v])
            i = max(i, count[v]);
        else
            i = max(i, dfs(adj, visited, count, v));
    }
    count[node] += i;
    dfs_depth_counter--;  // Decrease depth after returning
    return count[node];
}

int main() {
    FAST_IO;
    int t;
    cin >> t;
    while(t--) {
        int i, j, k, n, m;
        cin >> n;
        vector<int> arr(n);
        set<int> s;
        m = 0;
        for(i = 0; i < n; i++) {
            cin >> arr[i];
            s.insert(arr[i]);
            m = max(m, arr[i]);
        }
        check_max_value_invariant(150000, m);  // Check max element value

        if(n == 1) {
            cout << "0\n";
            continue;
        }
        
        vector<int> count(m + 1, 0);
        f(i, 0, n)
            count[arr[i]]++;
        vector<vector<int>> adj(m + 1);

        for(auto it = s.begin(); it != s.end(); it++) {
            j = (*it);
            for(i = 1; i * i <= j; i++) {
                if(j % i != 0)
                    continue;
                if(count[i] && (j != i))
                    adj[j].pb(i);
                k = j / i;
                if(k != i && i != 1 && count[k])
                    adj[j].pb(k);
            }
            check_adjacency_size_invariant(50, adj[j].size());  // Check adjacency list size
        }
        
        vector<bool> visited(m + 1, false);
        f(i, 1, m + 1) {
            if(visited[i])
                continue;
            dfs(adj, visited, count, i);
        }
        
        j = 0;
        f(i, 1, m + 1)
            j = max(j, count[i]);
        cout << n - j endl;
    }
    return 0;
}