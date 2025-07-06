#include <bits/stdc++.h>
using namespace std;

struct node {
    int t, candies, prevcolour, preveaten, pos;
    node() {}
    node(int t, int candies, int prevcolour, int preveaten, int pos)
        : t(t), candies(candies), prevcolour(prevcolour), pos(pos), preveaten(preveaten) {}
    const bool operator<(const node &nd) const {
        if (t == nd.t)
            return candies < nd.candies;
        else
            return t > nd.t;
    }
};

bool vis[1300][55][1300];

void check_high_search_space_invariant(int num_pq_operations) {
    if (num_pq_operations > 100000) {
        cerr << "Warning: Performance bottleneck condition triggered - High search space exploration!" << endl;
        abort();
    }
}

void check_dense_adj_list_invariant(int n, const vector<vector<int>>& adj) {
    int max_adj_size = 0;
    for (const auto& neighbors : adj) {
        max_adj_size = max(max_adj_size, static_cast<int>(neighbors.size()));
    }
    if (max_adj_size > n / 2) {
        cerr << "Warning: Performance bottleneck condition triggered - Dense adjacency list usage!" << endl;
        abort();
    }
}

void check_repeated_pq_adjustments(int pq_size) {
    if (pq_size > 1000) {
        cerr << "Warning: Performance bottleneck condition triggered - Repeated priority queue adjustments!" << endl;
        abort();
    }
}

void check_extensive_backtracking(int backtrack_count, int n) {
    if (backtrack_count > n * 10) {
        cerr << "Warning: Performance bottleneck condition triggered - Extensive backtracking!" << endl;
        abort();
    }
}

void cp() {
    int n, s, k;
    string colour;
    cin >> n >> s >> k;
    vector<int> arr(n);
    for (int &x : arr) cin >> x;
    cin >> colour;
    vector<vector<int>> adj(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[j] > arr[i] && colour[j] != colour[i]) adj[i].push_back(j);
        }
    }

    check_dense_adj_list_invariant(n, adj); // Check dense adjacency list

    long long int ans = -1;
    priority_queue<node> pq;
    int num_pq_operations = 0; // Track number of priority queue operations
    int backtrack_count = 0; // Track backtracking counts

    for (int i = 0; i < n; i++) {
        int d = abs(i - (s - 1));
        pq.push(node(d, arr[i], colour[i], arr[i], i));
        num_pq_operations++;
    }

    check_high_search_space_invariant(num_pq_operations); // Check high search space exploration

    while (!pq.empty()) {
        check_repeated_pq_adjustments(pq.size()); // Check repeated priority queue adjustments

        node u = pq.top();
        pq.pop();
        vis[u.candies][u.pos][u.t] = 1;
        
        if (u.candies >= k) {
            ans = u.t;
            break;
        }

        for (int i : adj[u.pos]) {
            node v = u;
            v.candies += arr[i];
            v.preveaten = arr[i];
            v.prevcolour = colour[i];
            v.t += abs(i - u.pos);
            v.pos = i;
            
            if (v.candies < 1300 && !vis[v.candies][v.pos][v.t]) {
                pq.push(v);
                vis[v.candies][v.pos][v.t] = 1;
                num_pq_operations++;
            } else {
                backtrack_count++;
            }
            
            check_extensive_backtracking(backtrack_count, n); // Check extensive backtracking
        }
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    t = 1;
    while (t--) {
        cp();
    }
    return 0;
}