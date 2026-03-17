#include <bits/stdc++.h>
using namespace std;
const int MAXN = 75;
int grid[MAXN][MAXN];
int dp[MAXN][MAXN][MAXN][MAXN];
int dp2[MAXN][MAXN];
int n, m, k;
int find_max(int row, int col, int rem, int mod) {
  if (col >= m || rem == 0) {
    if (mod == 0) return 0;
    return -1;
  } else if (dp[row][col][rem][mod] != -2) {
    return dp[row][col][rem][mod];
  } else {
    int option1 = find_max(row, col + 1, rem, mod);
    int new_mod = (mod + grid[row][col]) % k;
    int option2 = find_max(row, col + 1, rem - 1, new_mod);
    if (option2 != -1) {
      option2 += grid[row][col];
    }
    dp[row][col][rem][mod] = max(option1, option2);
    return dp[row][col][rem][mod];
  }
}
int find_ans(int row = 0, int rem = 0) {
  if (row == n) {
    if (rem == 0) return 0;
    return -1;
  } else if (dp2[row][rem] != -2) {
    return dp2[row][rem];
  } else {
    int max_ans = -1;
    for (int i = 0; i < k; ++i) {
      int new_rem = (i + rem) % k;
      int ans = find_max(row, 0, m / 2, i);
      int next_part = find_ans(row + 1, new_rem);
      if (ans == -1) continue;
      if (next_part == -1) continue;
      ans += next_part;
      max_ans = max(max_ans, ans);
    }
    dp2[row][rem] = max_ans;
    return max_ans;
  }
}
int main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(false);
  cin >> n >> m >> k;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      for (int l = 0; l < m; ++l) {
        for (int q = 0; q < k; ++q) {
          dp[i][j][l][q] = -2;
        }
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < k; ++j) {
      dp2[i][j] = -2;
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> grid[i][j];
    }
  }
  cout << find_ans();
  return 0;
}
