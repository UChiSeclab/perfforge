#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
int k, c[1010];
long long dp[1010][1010];

// Checker function for excessive recursive calls
void check_recursive_depth(int callCount) {
    if (callCount > 150000) { // Example threshold based on analysis
        cerr << "Warning: Performance bottleneck condition triggered - excessive recursive calls!" << endl;
        abort();
    }
}

// Checker function for inefficient dp usage
void check_dp_usage(int id, int ball) {
    if (id * ball > 500000) { // Example threshold based on analysis
        cerr << "Warning: Performance bottleneck condition triggered - inefficient dp usage!" << endl;
        abort();
    }
}

long long calc(int id, int ball) {
    check_dp_usage(id, ball);  // Check for inefficient dp usage
    
    if (id == 1)
        return 1;
    else if (ball == 0)
        return 1;
    long long& ans = dp[id][ball];
    if (ans == -1) {
        ans = (calc(id - 1, ball) % MOD + calc(id, ball - 1) % MOD) % MOD;
        
        static int callCount = 0;  // Static to persist across calls
        callCount++;
        check_recursive_depth(callCount);  // Check for excessive recursive calls
    }
    return ans;
}

int main(void) {
  cin >> k;
  for (int i = 0; i < k; i++) {
    cin >> c[i];
  }
  memset(dp, -1, sizeof(dp));
  long long ans = 1;
  int ball = 1;
  for (int i = 0; i < k; i++) {
    ans *= calc(ball, c[i] - 1);
    ans %= MOD;
    ball += c[i];
  }
  cout << ans << "\n";
  return 0;
}