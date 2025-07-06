#include <bits/stdc++.h>
using namespace std;

int f[10];
vector<int> sol;
int dp[10][1000001];
bool vis[10][1000001];

// Function to check variance in digit costs
void check_variance_invariant(const vector<int>& costs) {
    int minCost = *min_element(costs.begin(), costs.end());
    int maxCost = *max_element(costs.begin(), costs.end());

    if ((maxCost - minCost) > 50000) { // Threshold is arbitrary but reflects a large variance
        cerr << "Warning: Performance bottleneck condition triggered due to large variance in digit paint costs!" << endl;
        abort();
    }
}

int calc(int i, int v) {
  if (v < 0) return -(1 << 29);
  if (!i) return 0;
  if (vis[i][v] == false) {
    vis[i][v] = true;
    dp[i][v] = max(calc(i - 1, v), 1 + calc(i, v - f[i]));
  }
  return dp[i][v];
}

void print(int i, int v) {
  if (v < 0) return;
  if (!i) return;
  if (dp[i][v] == 1 + calc(i, v - f[i])) {
    printf("%d", i);
    print(i, v - f[i]);
  } else
    print(i - 1, v);
}

int main() {
  int v;
  cin >> v;
  vector<int> costs(9);
  for (int i = 1; i <= 9; ++i) {
    cin >> f[i];
    costs[i - 1] = f[i];
  }

  // Insert check for variance in digit paint costs before heavy computations
  check_variance_invariant(costs);

  int x = calc(9, v);
  if (x > 0)
    print(9, v);
  else
    printf("-1");
  return 0;
}