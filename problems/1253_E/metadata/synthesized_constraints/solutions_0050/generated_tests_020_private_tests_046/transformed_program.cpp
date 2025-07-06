#include <bits/stdc++.h>
using namespace std;
const int XMAX = 1e5;
const int NMAX = 80;
const int inf = 1e7;
int n, m;
int dp[XMAX + 5];
vector<pair<int, int> > v[XMAX + 5];
int aib[XMAX + 5];

void update(int pos, int val) {
  pos++;
  for (; pos; pos -= (-pos) & pos) {
    aib[pos] = min(aib[pos], val);
  }
}

int query(int pos) {
  pos++;
  int ans = inf;
  for (; pos <= m; pos += (-pos) & pos) {
    ans = min(ans, aib[pos]);
  }
  return ans;
}

// Check for dense antenna distribution
void check_dense_antenna_distribution(int denseCount) {
    if (denseCount > 50) { // arbitrary threshold based on n <= 80
        cerr << "Warning: Dense antenna distribution detected!" << endl;
        abort();
    }
}

// Check for large coverage requirements
void check_large_coverage_requirement(int coveredLength, int m) {
    if (coveredLength > m * 0.8) { // threshold based on coverage being 80% of m
        cerr << "Warning: Large coverage requirement detected!" << endl;
        abort();
    }
}

// Check for minimal initial coverage
void check_minimal_initial_coverage(int zeroCoverageCount, int n) {
    if (zeroCoverageCount > n * 0.75) { // threshold based on 75% of antennas having zero coverage
        cerr << "Warning: Minimal initial coverage detected!" << endl;
        abort();
    }
}

int main() {
  scanf("%d %d", &n, &m);
  
  int zeroCoverageCount = 0;
  int denseClusterCount = 0;
  int totalCoverLength = 0;

  for (int i = 1; i <= m; i++) {
    aib[i] = inf;
  }
  for (int i = 1; i <= n; i++) {
    int x, s;
    scanf("%d %d", &x, &s);
    if (s == 0) zeroCoverageCount++;
    
    // Calculate total initial coverage
    totalCoverLength += 2 * s + 1;

    for (int j = 0; j <= m && (x - j > 0 || x + j <= m); j++) {
      v[min(x + j, m)].push_back({max(0, x - j - 1), max(0, j - s)});
    }
  }
  
  // Before processing, check the invariants
  check_dense_antenna_distribution(n);
  check_large_coverage_requirement(totalCoverLength, m);
  check_minimal_initial_coverage(zeroCoverageCount, n);

  dp[0] = 0;
  update(0, 0);
  for (int i = 1; i <= m; i++) {
    dp[i] = inf;
    for (auto it : v[i]) {
      dp[i] = min(dp[i], query(it.first) + it.second);
    }
    update(i, dp[i]);
  }
  printf("%d\n", dp[m]);
  return 0;
}