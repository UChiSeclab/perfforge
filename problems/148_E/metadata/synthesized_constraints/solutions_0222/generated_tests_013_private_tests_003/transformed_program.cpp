#include <bits/stdc++.h>
using namespace std;

void scan(int &x) {
  register int c = getchar();
  x = 0;
  int neg = 0;
  for (; ((c < 48 || c > 57) && c != '-'); c = getchar());
  if (c == '-') {
    neg = 1;
    c = getchar();
  }
  for (; c > 47 && c < 58; c = getchar()) {
    x = (x << 1) + (x << 3) + c - 48;
  }
  if (neg) x = -x;
}

const int M = 101;
int dp[M][M], dp1[M][10001], s[M], a[M][M], mx[101][101], nn, mm;

// Function to check recursion depth and branching
void check_recursion_invariant(int s, int currentDepth) {
    if ((s > 50) && (currentDepth > 50)) {
        cerr << "Warning: High recursion depth or branching factor detected!" << endl;
        abort();
    }
}

// Function to check DP reset inefficiency
void check_dp_invariant(int m) {
    if (m > 5000) {
        cerr << "Warning: DP table reset often with large m!" << endl;
        abort();
    }
}

// Function to check high volume of recursive calls
void check_recursive_calls_invariant(int m) {
    if (m > 8000) {
        cerr << "Warning: Excessive recursive calls due to large m!" << endl;
        abort();
    }
}

int solve(int l, int r, int d) {
  check_recursion_invariant(s[nn], d);
  if (d > mm) return 0;
  if (l > r) return 0;
  if (l == r) {
    return a[nn][l];
  }
  int &ret = dp[l][r];
  if (ret != -1) return ret;
  ret = 0;
  ret += max(solve(l + 1, r, d + 1) + a[nn][l], solve(l, r - 1, d + 1) + a[nn][r]);
  return ret;
}

int main() {
  int n, m;
  cin >> n >> m;

  check_dp_invariant(m);  // Placing check after input reading
  check_recursive_calls_invariant(m);  // Placing check after input reading

  for (int i = 1; i <= n; i++) {
    scan(s[i]);
    for (int j = 0; j < s[i]; j++) {
      scan(a[i][j]);
    }
  }

  for (int i = 1; i <= n; i++) {
    nn = i;
    for (int j = 1; j <= s[i]; j++) {
      memset(dp, -1, sizeof dp);
      mm = j;
      mx[i][j] = solve(0, s[i] - 1, 1);
    }
  }

  memset(dp, -1, sizeof dp);
  dp1[0][0] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < s[i]; j++) {
      for (int k = 0; k <= m; k++) {
        if (dp1[i - 1][k] != -1) {
          if (k + j + 1 <= m)
            dp1[i][k + j + 1] = max(dp1[i][k + j + 1], dp1[i - 1][k] + mx[i][j + 1]);
          dp1[i][k] = max(dp1[i - 1][k], dp1[i][k]);
        }
      }
    }
  }
  
  printf("%d\n", dp1[n][m]);
  return 0;
}