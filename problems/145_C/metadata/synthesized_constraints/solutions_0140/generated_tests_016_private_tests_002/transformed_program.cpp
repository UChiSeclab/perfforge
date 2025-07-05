#include <bits/stdc++.h>
using namespace std;
const int di[] = {-1, 0, 1, 0, -1, 1, 1, -1};
const int dj[] = {0, 1, 0, -1, -1, 1, -1, 1};
const long long MOD = 1e9 + 7;
const long long INF = 1e9;
const long double EPS = 1e-7;

void check_combination_invariant(long long others, int threshold) {
    if (others > threshold) {
        cerr << "Warning: combination_invariant triggered - too many non-lucky numbers affecting combinations!" << endl;
        abort();
    }
}

void check_lucky_subsequence_invariant(int distinctLuckyCount, int threshold) {
    if (distinctLuckyCount > threshold) {
        cerr << "Warning: lucky_subsequence_invariant triggered - too many distinct lucky numbers slowing down!" << endl;
        abort();
    }
}

long long fastPow(long long a, int p, int m) {
  if (p == 0) return 1;
  if (p % 2 == 1) return (a * fastPow(a, p - 1, m)) % m;
  long long c = fastPow(a, p / 2, m);
  return (c * c) % m;
}

vector<int> mem(1e5 + 5, -1);
long long fact(long long n) {
  if (n == 0) return 1;
  if (~mem[n]) return mem[n];
  return mem[n] = (n * fact(n - 1)) % MOD;
}

long long nCr(long long n, long long r) {
  if (!(n >= r)) return 0;
  long long ret = fact(n) * fastPow(fact(r), MOD - 2, MOD);
  ret %= MOD;
  ret *= fastPow(fact(n - r), MOD - 2, MOD);
  ret %= MOD;
  return ret;
}

bool lucky(int n) {
  while (n) {
    if (n % 10 != 4 && n % 10 != 7) return false;
    n /= 10;
  }
  return true;
}

vector<long long> cnt;
int main() {
  ios::sync_with_stdio(false), cin.tie(0);
  int n, k;
  cin >> n >> k;
  map<int, long long> cntm;
  long long others = n;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (lucky(x)) cntm[x]++, others--;
  }
  check_combination_invariant(others, 1e5); // Check for too many non-lucky numbers
  for (auto& i : cntm) cnt.push_back(i.second);
  check_lucky_subsequence_invariant(cnt.size(), 100); // Check for too many distinct lucky numbers
  if (k == 1)
    cout << n << endl;
  else {
    vector<vector<long long> > dp(2, vector<long long>(1e5 + 5));
    if (cnt.empty()) {
      dp[0][0] = 1;
    } else {
      dp[cnt.size() & 1][0] = 1;
      for (int i = (int)cnt.size() - 1; i >= 0; i--) {
        dp[i & 1][0] = 1;
        for (int j = 1; j <= k && j <= cnt.size() - i; j++) {
          dp[i & 1][j] = cnt[i] * dp[(i + 1) & 1][j - 1];
          dp[i & 1][j] %= MOD;
          dp[i & 1][j] += dp[(i + 1) & 1][j];
          dp[i & 1][j] %= MOD;
        }
      }
    }
    long long r = 0;
    for (int i = 0; i <= k; i++) {
      r += (nCr(others, i) * dp[0][k - i]) % MOD;
      r %= MOD;
    }
    cout << r << endl;
  }
  cin.ignore(), cin.get();
}