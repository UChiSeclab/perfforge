#include <bits/stdc++.h>
using namespace std;
const int MAXN = 312;
const long long MOD = 1e9 + 7;

long long fexp(long long b, long long e) {
  if (e == 0) return 1;
  if (e & 1LL) return (b * fexp(b, e - 1LL)) % MOD;
  long long a = fexp(b, e >> 1LL);
  return (a * a) % MOD;
}

long long fat[MAXN];
long long inv[MAXN];

long long comb(long long a, long long b) {
  long long ans = (fat[a] * inv[b]) % MOD;
  ans = (ans * inv[a - b]) % MOD;
  return ans;
}

long long n;
long long kpow[MAXN][2];
long long memo[MAXN][MAXN];

// Checker functions for performance invariants
void check_recursion_invariant(int recursionDepth, int n) {
    if (recursionDepth > n * 2) {
        cerr << "Warning: Recursion invariant triggered - potential deep recursion path!" << endl;
        abort();
    }
}

void check_combination_invariant(int row, int n) {
    if (row > n * 0.8) {
        cerr << "Warning: Combination invariant triggered - intensive combinatorial calculations!" << endl;
        abort();
    }
}

void check_modular_exponentiation_invariant(long long k) {
    if (k > 1e8) {
        cerr << "Warning: Modular exponentiation invariant triggered - large k value!" << endl;
        abort();
    }
}

long long solve(int col, int row) {
  // Add a recursion depth check
  static int recursionDepth = 0;
  recursionDepth++;
  check_recursion_invariant(recursionDepth, n);

  if (col == 0) return (row == 0);
  long long& p = memo[col][row];
  if (p + 1) return p;

  // Check combination invariant before combinatorial calculations
  check_combination_invariant(row, n);

  p = (kpow[n - row][0] * kpow[row][1]) % MOD;
  p *= solve(col - 1, row);
  p %= MOD;
  p -= kpow[n][1] * solve(col - 1, row);
  p %= MOD;
  p += MOD;
  p %= MOD;
  for (long long nxtRow = 0; nxtRow < row; ++nxtRow) {
    long long diff = row - nxtRow;
    long long curr = (kpow[n - row][0] * comb(row, nxtRow)) % MOD;
    curr = (curr * kpow[row - diff][1]) % MOD;
    curr = (curr * solve(col - 1, nxtRow)) % MOD;
    p += curr;
    p %= MOD;
  }

  recursionDepth--;
  return p %= MOD;
}

int main() {
  memset(memo, -1, sizeof memo);
  long long k;
  cin >> n >> k;

  // Check the modular exponentiation invariant after reading input
  check_modular_exponentiation_invariant(k);

  if (k == 1) {
    cout << 1 << endl;
    return 0;
  }
  
  kpow[0][0] = kpow[0][1] = 1;
  for (long long i = 1; i < MAXN; ++i) {
    kpow[i][0] = (k * kpow[i - 1][0]) % MOD;
    kpow[i][1] = ((k - 1LL) * kpow[i - 1][1]) % MOD;
  }
  
  fat[0] = inv[0] = 1;
  for (long long i = 1; i < MAXN; ++i) {
    fat[i] = (i * fat[i - 1]) % MOD;
    inv[i] = fexp(fat[i], MOD - 2);
  }
  
  cout << solve(n, n) << endl;
  return 0;
}