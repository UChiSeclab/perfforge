#include <bits/stdc++.h>
const int maxn = 1e5 + 10;
using namespace std;

// Checker function to detect near-target starting values
void check_near_target_starting_values(int n, int m) {
    if (n < m && abs(n - m) <= 10) { // Assuming "close" is within a small range like 10
        cerr << "Warning: Near-target starting value might cause excessive operations!" << endl;
        abort();
    }
}

// Checker function for exploratory operations
void check_exploratory_operations(int n, int m) {
    if (n < m && n > m / 2) {  // Large n, but less than m
        cerr << "Warning: Exploratory operations due to large starting number!" << endl;
        abort();
    }
}

// Checker function for high initial numbers
void check_high_initial_numbers(int n, int m) {
    if (n > 5000 && n < m && abs(n - m) < 100) { // Large n with a small difference
        cerr << "Warning: High initial number causing large search space!" << endl;
        abort();
    }
}

struct node {
  int x, num;
} ne, pos;

int bfs() {
  queue<node> q;
  map<int, int> mp;
  mp[n] = 1;
  ne.x = n;
  ne.num = 0;
  q.push(ne);
  while (!q.empty()) {
    pos = q.front();
    q.pop();
    if (pos.x == m) return pos.num;
    ne.num = pos.num + 1;
    ne.x = pos.x * 2;
    if (ne.x <= maxn && mp[ne.x] == 0) {
      mp[ne.x] = 1;
      q.push(ne);
    }
    ne.x = pos.x - 1;
    if (ne.x >= 0 && mp[ne.x] == 0) {
      mp[ne.x] = 1;
      q.push(ne);
    }
  }
  return 0;
}

int main() {
  int ans;
  while (~scanf("%d%d", &n, &m)) {

    // Insert checks before performing the BFS
    check_near_target_starting_values(n, m);
    check_exploratory_operations(n, m);
    check_high_initial_numbers(n, m);

    ans = bfs();
    cout << ans << endl;
  }
  return 0;
}