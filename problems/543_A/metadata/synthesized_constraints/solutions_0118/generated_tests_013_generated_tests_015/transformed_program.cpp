#include <bits/stdc++.h>
using namespace std;
const int Nmax = 505;
int Mod;
int dp[Nmax][Nmax];
int S[Nmax][Nmax];
int A[Nmax];

// Checker functions for performance invariants
void check_bug_tolerance_invariant(int B, const std::vector<int>& A) {
    int lowBugRateCount = count_if(A.begin(), A.end(), [](int bugRate) { return bugRate < 5; }); // Example threshold
    if (B > 400 && lowBugRateCount > A.size() / 2) {
        cerr << "Warning: Performance bottleneck condition triggered due to high bug tolerance and many low bug rate programmers!" << endl;
        abort();
    }
}

void check_k_path_invariant(int B, int M, const std::vector<int>& A) {
    int minBugRate = *min_element(A.begin(), A.end());
    if (B > M * minBugRate) {
        cerr << "Warning: Performance bottleneck condition triggered due to extensive paths in nested loops!" << endl;
        abort();
    }
}

void check_programmer_diversity_invariant(int n, const std::vector<int>& A) {
    int uniqueBugRates = unordered_set<int>(A.begin(), A.end()).size();
    if (n > 300 && uniqueBugRates > n / 2) {
        cerr << "Warning: Performance bottleneck condition triggered due to diverse bug rates!" << endl;
        abort();
    }
}

void check_bug_margin_invariant(int M, int B) {
    if (M - B < 50) { // Example threshold
        cerr << "Warning: Performance bottleneck condition triggered due to small margin between M and B!" << endl;
        abort();
    }
}

int main() {
  ios::sync_with_stdio(false);
  int N, M, B;
  cin >> N >> M >> B >> Mod;
  
  vector<int> A(N + 1);
  for (int i = 1; i <= N; ++i) cin >> A[i];

  // Insert checks after reading inputs
  check_bug_tolerance_invariant(B, A);
  check_k_path_invariant(B, M, A);
  check_programmer_diversity_invariant(N, A);
  check_bug_margin_invariant(M, B);

  dp[0][0] = 1 % Mod;
  for (int i = 1; i <= N; ++i) {
    for (int j = 0; j <= M; ++j) {
      for (int k = 0; k <= B; ++k) {
        S[j][k] = dp[j][k];
        if (j > 0 && k >= A[i]) S[j][k] = (S[j][k] + S[j - 1][k - A[i]]) % Mod;
      }
    }
    for (int j = 1; j <= M; ++j) {
      for (int k = A[i]; k <= B; ++k) {
        dp[j][k] = (dp[j][k] + S[j - 1][k - A[i]]) % Mod;
      }
    }
  }
  
  int ans = 0;
  for (int i = 0; i <= B; ++i) ans = (ans + dp[M][i]) % Mod;
  cout << ans << '\n';
}