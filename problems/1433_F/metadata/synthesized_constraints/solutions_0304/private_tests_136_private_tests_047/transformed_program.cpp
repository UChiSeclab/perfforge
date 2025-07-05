#include <bits/stdc++.h>
using namespace std;

// Check if each row contains identical or very similar values
void check_identical_row_values(const vector<vector<long long>>& matrix) {
    for (const auto& row : matrix) {
        if (std::adjacent_find(row.begin(), row.end(), std::not_equal_to<>()) == row.end()) {
            cerr << "Warning: Performance bottleneck condition triggered - identical values in row!" << endl;
            abort();
        }
    }
}

// Check if number of columns is close to upper limit
void check_large_column_limit(long long m) {
    if (m >= 65) { // Threshold chosen close to the upper constraint (70)
        cerr << "Warning: Performance bottleneck condition triggered - large number of columns!" << endl;
        abort();
    }
}

// Check if full DP table exploration is required
void check_full_dp_exploration(long long k, const vector<vector<long long>>& matrix) {
    for (const auto& row : matrix) {
        std::unordered_set<long long> mods;
        long long row_sum = 0;
        for (long long value : row) {
            row_sum += value;
            mods.insert(value % k);
        }
        if (mods.size() == 1 && mods.count(0) == 0) { // All elements have same non-zero remainder
            cerr << "Warning: Performance bottleneck condition triggered - full DP exploration needed!" << endl;
            abort();
        }
    }
}

class pa3 {
 // Class definitions omitted for brevity
};

class pa4 {
 // Class definitions omitted for brevity
};

class pa2 {
 // Class definitions omitted for brevity
};

string itos(long long i) {
 // Function definition omitted for brevity
}

long long Gcd(long long v, long long b) {
 // Function definition omitted for brevity
}

long long mod;
long long extgcd(long long a, long long b, long long& x, long long& y) {
 // Function definition omitted for brevity
}

pair<long long, long long> operator+(const pair<long long, long long>& l,
                                     const pair<long long, long long>& r) {
 // Operator definition omitted for brevity
}

pair<long long, long long> operator-(const pair<long long, long long>& l,
                                     const pair<long long, long long>& r) {
 // Operator definition omitted for brevity
}

ostream& operator<<(ostream& os, const vector<long long>& VEC) {
 // Operator definition omitted for brevity
}

ostream& operator<<(ostream& os, const pair<long long, long long>& PAI) {
 // Operator definition omitted for brevity
}

ostream& operator<<(ostream& os, const pa3& PAI) {
 // Operator definition omitted for brevity
}

ostream& operator<<(ostream& os, const pa4& PAI) {
 // Operator definition omitted for brevity
}

ostream& operator<<(ostream& os,
                    const vector<pair<long long, long long> >& VEC) {
 // Operator definition omitted for brevity
}

long long beki(long long wa, long long rr, long long warukazu) {
 // Function definition omitted for brevity
}

long long pr[1100000];
long long inv[1100000];
long long comb(long long nn, long long rr) {
 // Function definition omitted for brevity
}

void gya(long long ert) {
 // Function definition omitted for brevity
}

long long dp[80][80][80];
long long dp2[80][80];

void solve() {
  long long n, m, k;
  cin >> n >> m >> k;

  vector<vector<long long>> matrix(n, vector<long long>(m));
  for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
          cin >> matrix[i][j];
      }
  }

  // Insert runtime checks
  check_identical_row_values(matrix);
  check_large_column_limit(m);
  check_full_dp_exploration(k, matrix);
  
  // Original dp2 initialization
  for (long long i = 0; i < 80; i++)
    for (long long j = 0; j < 80; j++) dp2[i][j] = -1;
  dp2[0][0] = 0;
  
  // Original solve logic
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < 80; j++)
      for (long long l = 0; l < 80; l++)
        for (long long e = 0; e < 80; e++) dp[l][j][e] = -1;
    dp[0][0][0] = 0;
    for (long long j = 0; j < m; j++) {
      long long y = matrix[i][j];
      for (long long l = 0; l <= m; l++)
        for (long long e = 0; e < k; e++)
          if (dp[j][l][e] >= 0) {
            dp[j + 1][l][e] = max(dp[j + 1][l][e], dp[j][l][e]);
            dp[j + 1][l + 1][(e + y) % k] =
                max(dp[j + 1][l + 1][(e + y) % k], dp[j][l][e] + y);
          }
    }
    vector<long long> a(k, -1);
    for (long long j = 0; j < k; j++)
      for (long long e = 0; e <= m / 2; e++) {
        a[j] = max(a[j], dp[m][e][j]);
      }
    for (long long j = 0; j < k; j++)
      if (dp2[i][j] >= 0) {
        for (long long l = 0; l < k; l++)
          if (a[l] >= 0) {
            dp2[i + 1][(j + l) % k] =
                max(dp2[i + 1][(j + l) % k], dp2[i][j] + a[l]);
          }
      }
  }
  cout << dp2[n][0] << endl;
}

signed main() {
  mod = 1000000007;
  cin.tie(0);
  ios::sync_with_stdio(false);
  long long n = 1;
  for (long long i = 0; i < n; i++) solve();
  return 0;
}