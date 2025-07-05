#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;

// Checker functions for performance bottlenecks
void check_dfs_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: dfs_invariant triggered - high recursion depth or branching factor" << endl;
        abort();
    }
}

void check_permutation_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: permutation_invariant triggered - combinatorial explosion with high k" << endl;
        abort();
    }
}

void check_addition_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: addition_invariant triggered - excessive additions in loop" << endl;
        abort();
    }
}

int add(int a, int b) {
  a += b;
  if (a >= mod) {
    a -= mod;
  }
  return a;
}

int rest(int a, int b) {
  a -= b;
  if (a < 0) {
    a += mod;
  }
  return a;
}

int mult(int a, int b) { return ((long long)a * (long long)b) % mod; }

int bpow(int b, int exp) {
  if (exp == 0) {
    return 1;
  }
  if (exp == 1) {
    return b;
  }
  int ret = bpow(b, exp / 2);
  ret = mult(ret, ret);
  if (exp & 1) {
    ret = mult(ret, b);
  }
  return ret;
}

int sol;
int p[10];
bool mk[10];
vector<int> g[10];

void dfs(int u) {
  mk[u] = true;

  // Check if the DFS is creating too many recursive calls (high branching factor)
  check_dfs_invariant(g[u].size() > 10);

  for (int i = 0; i < g[u].size(); i++) {
    if (!mk[g[u][i]]) {
      dfs(g[u][i]);
    }
  }
}

int pw;

void solve(int step, int k) {
  if (step > k) {
    for (int i = 1; i <= k; i++) {
      g[i].clear();
      mk[i] = false;
    }
    for (int i = 1; i <= k; i++) {
      g[p[i]].push_back(i);
    }
    dfs(1);
    for (int i = 1; i <= k; i++) {
      if (!mk[i]) {
        return;
      }
    }

    // Check if excessive additions are happening
    check_addition_invariant(sol > 1000000);

    sol = add(sol, pw);
    return;
  }

  // Check for combinatorial explosion in permutations
  check_permutation_invariant(step > 8);

  for (int i = 1; i <= k; i++) {
    p[step] = i;
    solve(step + 1, k);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, k;
  cin >> n >> k;

  // Check if k is approaching the limit (combinatorial explosion risk)
  check_permutation_invariant(k > 8);

  pw = 1;
  for (int i = 1; i <= n - k; i++) {
    pw = mult(pw, n - k);
  }
  sol = 0;
  solve(1, k);
  cout << sol << '\n';
}