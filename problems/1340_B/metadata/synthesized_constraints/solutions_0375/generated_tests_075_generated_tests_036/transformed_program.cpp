#include <bits/stdc++.h>
using namespace std;
long long MOD = 1e9 + 7;
const long long maxn = 2e3 + 5;
long long numreq[maxn][10];
bool dp[maxn][maxn];
string temp[] = {"1110111", "0010010", "1011101", "1011011", "0111010",
                 "1101011", "1101111", "1010010", "1111111", "1111011"};

long long diff(string &s, long long id) {
  long long ans = 0;
  for (long long i = 0; i < 7; ++i) {
    if (temp[id][i] == '0' and s[i] == '1') return -1;
    if (temp[id][i] != s[i]) ans++;
  }
  return ans;
}

void check_excessive_state_transitions(int n, int totalPossibleTransitions) {
    if (totalPossibleTransitions > n * 15) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive state transitions!" << endl;
        abort();
    }
}

void check_high_branching_factor(int branchingFactor) {
    if (branchingFactor > 20) {
        cerr << "Warning: Performance bottleneck condition triggered - high branching factor!" << endl;
        abort();
    }
}

void check_large_search_space(int activeSegments, int possibleTransformations) {
    if (activeSegments > 6 && possibleTransformations > 20) {
        cerr << "Warning: Performance bottleneck condition triggered - large search space!" << endl;
        abort();
    }
}

bool f() {
  long long n, k;
  cin >> n >> k;
  for (long long i = 0; i < n; ++i) {
    for (long long j = 0; j < 10; ++j) {
      numreq[i][j] = -1;
    }
  }
  for (long long i = 0; i < n; ++i) {
    string s;
    cin >> s;
    for (long long j = 0; j < 10; ++j) {
      numreq[i][j] = diff(s, j);
    }
  }

  // Check for excessive state transitions
  int totalPossibleTransitions = 0;
  for (long long i = 0; i < n; ++i) {
    for (long long j = 0; j < 10; ++j) {
      if (numreq[i][j] != -1) {
        totalPossibleTransitions++;
      }
    }
  }
  check_excessive_state_transitions(n, totalPossibleTransitions);

  for (long long i = n - 1; i >= 0; i--) {
    if (i == n - 1) {
      for (long long j = 0; j < 10; ++j) {
        if (numreq[i][j] != -1) dp[i][numreq[i][j]] = 1;
      }
    } else {
      for (long long j = 0; j < 10; ++j) {
        if (numreq[i][j] == -1) continue;
        long long curr = numreq[i][j];
        int branchingFactor = 0;
        for (long long kk = 0; kk + curr < maxn; ++kk) {
          if (dp[i + 1][kk]) {
            dp[i][kk + curr] = 1;
            branchingFactor++;
          }
        }
        // Check for high branching factor
        check_high_branching_factor(branchingFactor);
      }
    }
  }

  if (!dp[0][k]) {
    return 0;
  }

  for (long long i = 0; i < n - 1; ++i) {
    for (long long j = 9; j >= 0; j--) {
      if (numreq[i][j] == -1 or numreq[i][j] > k) continue;
      if (dp[i + 1][k - numreq[i][j]]) {
        cout << j;
        k -= numreq[i][j];
        break;
      }
    }
  }
  for (long long j = 9; j >= 0; j--) {
    if (numreq[n - 1][j] == k) {
      cout << j << '\n';
      return 1;
    }
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  long long t = 1;
  while (t--) {
    if (!f()) {
      cout << -1 << '\n';
    }
  }
  return 0;
}