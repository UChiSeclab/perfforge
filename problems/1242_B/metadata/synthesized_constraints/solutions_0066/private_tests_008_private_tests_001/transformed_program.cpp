#include <bits/stdc++.h>
using namespace std;

struct UnionSet {
  vector<pair<int32_t, int32_t> > sets;
  void init(int32_t n) {
    for (int i = (0); i < (n); ++i) {
      sets.push_back({i, 0});
    }
  }
  int find(int32_t x) {
    if (sets[x].first == x)
      return x;
    else
      return sets[x].first = find(sets[x].first);
  }
  void union_both(int32_t x, int32_t y) {
    int32_t parentX = find(x), parentY = find(y);
    int32_t rankX = sets[parentX].second, rankY = sets[parentY].second;
    if (parentX == parentY)
      return;
    else if (rankX < rankY)
      sets[parentX].first = parentY;
    else
      sets[parentY].first = parentX;
    if (rankX == rankY) sets[parentX].second++;
  }
};

// Checkers for performance bottlenecks
void check_large_n_minimal_m(int n, int m) {
    if (n > 50000 && m < n / 10) {
        cerr << "Warning: Performance bottleneck due to large n with minimal edges of weight 1!" << endl;
        abort();
    }
}

void check_high_union_find_frequency(int union_find_calls, int threshold) {
    if (union_find_calls > threshold) {
        cerr << "Warning: Performance bottleneck due to high frequency of union-find operations!" << endl;
        abort();
    }
}

void check_ineffective_random_sampling(int random_sampling_iterations, int threshold) {
    if (random_sampling_iterations > threshold) {
        cerr << "Warning: Performance bottleneck due to ineffective random sampling!" << endl;
        abort();
    }
}

const int N = 100001;
vector<pair<int, int> > edges;
int d[N];
vector<int> adj[N];
int n, m;
int mm;
int union_find_calls = 0;  // Counter for union-find operations
int random_sampling_iterations = 0;  // Counter for random sampling iterations

vector<int> random_nodes(vector<int>& a) {
  vector<int> nums;
  int d = a.size();
  for (int i = (0); i < (mm); ++i) nums.push_back(rand() % (n - d));
  random_sampling_iterations++;  // Increment random sampling counter
  sort(nums.begin(), nums.end());
  int i = 0;
  int cur = 0;
  int cur_j = 0;
  a.push_back(n + 1);
  vector<int> nodes;
  for (auto j : nums) {
    while (cur + 1 + j - cur_j >= a[i]) {
      cur_j += a[i] - cur - 1;
      cur = a[i];
      i++;
    }
    nodes.push_back(cur + 1 + j - cur_j);
  }
  a.pop_back();
  return nodes;
}

int random_try() {
  UnionSet U;
  U.init(n + 1);
  for (int u = (1); u < (n + 1); ++u) {
    if (d[u] >= n - mm) {
      adj[u].push_back(n + 1);
      for (int i = (0); i < (d[u]); ++i) {
        for (int v = (adj[u][i] + 1); v < (adj[u][i + 1]); ++v)
          if (u != v) {
            U.union_both(u, v);
            union_find_calls++;  // Increment union-find operation counter
          }
      }
      for (int v = (1); v < (adj[u][0]); ++v) {
        U.union_both(u, v);
        union_find_calls++;  // Increment union-find operation counter
      }
      adj[u].pop_back();
    } else {
      for (auto v : random_nodes(adj[u])) {
        U.union_both(u, v);
        union_find_calls++;  // Increment union-find operation counter
      }
    }
  }

  int cost = 0;
  for (auto p : edges) {
    if (U.find(p.first) != U.find(p.second)) {
      cost++;
      U.union_both(p.first, p.second);
      union_find_calls++;  // Increment union-find operation counter
    }
  }
  
  // Check for performance bottlenecks after critical operations
  check_high_union_find_frequency(union_find_calls, 10000000);
  check_ineffective_random_sampling(random_sampling_iterations, 100000);

  return cost;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> m;
  fill(d, d + n + 1, 0);
  for (int i = (0); i < (m); ++i) {
    int u, v;
    cin >> u >> v;
    edges.push_back({u, v});
    d[u]++;
    d[v]++;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  for (int u = (1); u < (n + 1); ++u) {
    sort(adj[u].begin(), adj[u].end());
  }
  int cost = n + 1;
  mm = min(3000000 / (n + m), 200);
  
  // Check for large n with minimal edges before any expensive operations
  check_large_n_minimal_m(n, m);

  for (int i = (0); i < (3); ++i) {
    cost = min(random_try(), cost);
  }
  cout << cost << "\n";
}