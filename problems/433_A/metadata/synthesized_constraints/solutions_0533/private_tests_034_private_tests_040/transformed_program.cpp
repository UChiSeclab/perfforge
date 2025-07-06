#include <bits/stdc++.h>
#pragma comment(linker, "/stack:102400000,102400000")
using namespace std;

const int N = 20003;
int n, a, b, sum, dp[N];

void init() {
  a = b = sum = 0;
  memset(dp, 0, sizeof(dp));
}

void get_data() {
  int t;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &t);
    if (t == 100) {
      a++;
      sum++;
    } else {
      b++;
      sum += 2;
    }
  }
}

void check_200_gram_apples_invariant(int b) {
    if (b > 80) { // Threshold for large number of 200 gram apples
        cerr << "Warning: Large number of 200 gram apples may cause slow execution!" << endl;
        abort();
    }
}

void check_dp_utilization_invariant(int sum) {
    if (sum > 150) { // Threshold for high sum value
        cerr << "Warning: High sum value leading to extensive dp utilization!" << endl;
        abort();
    }
}

void check_weight_distribution_invariant(int a, int b) {
    if (a < 10 && b > 90) { // Threshold for weight distribution imbalance
        cerr << "Warning: Imbalanced weight distribution may cause slow execution!" << endl;
        abort();
    }
}

void solve() {
  int i, j;
  dp[0] = 1;
  
  check_200_gram_apples_invariant(b);
  check_dp_utilization_invariant(sum);
  check_weight_distribution_invariant(a, b);

  for (i = 0; i < a; ++i) {
    for (j = 0; j < N - 1; ++j) {
      if (dp[j]) dp[j + 1] = 1;
    }
  }
  for (i = 0; i < b; ++i) {
    for (j = 0; j < N - 2; ++j) {
      if (dp[j]) dp[j + 2] = 1;
    }
  }
  if (sum % 2 == 0 && dp[sum / 2])
    puts("YES");
  else
    puts("NO");
}

int main() {
  while (~scanf("%d", &n)) {
    init();
    get_data();
    solve();
  }
  return 0;
}