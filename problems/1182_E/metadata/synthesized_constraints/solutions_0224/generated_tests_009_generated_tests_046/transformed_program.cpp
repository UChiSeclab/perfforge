#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
long long n;
int f[4], c;
map<int, int> primeTable[5];
vector<int> primes;

// Checkers for performance invariants
void check_high_factorization_overhead(const vector<int>& primes) {
    if (primes.size() > 1000) {
        cerr << "Warning: High factorization overhead due to numerous unique primes!" << endl;
        abort();
    }
}

void check_large_unique_primes(const vector<int>& primes) {
    if (primes.size() > 100) {
        cerr << "Warning: Large set of unique primes detected!" << endl;
        abort();
    }
}

void check_matrix_exponentiation_complexity(const matrix& trans) {
    int complexity_metric = trans.mat[1][1]; // Simplified proxy for complexity
    if (complexity_metric > 10000) {
        cerr << "Warning: Complex matrix exponentiation detected!" << endl;
        abort();
    }
}

int quick_pow(int bas, long long tim) {
  tim %= (mod - 1);
  int ret = 1;
  while (tim) {
    if (tim & 1) ret = 1LL * ret * bas % mod;
    bas = 1LL * bas * bas % mod;
    tim >>= 1;
  }
  return ret;
}

struct matrix {
  int mat[5][5];
  void clear() { memset(mat, 0, sizeof(mat)); }
  int *operator[](const int &rhs) { return mat[rhs]; }
  matrix operator*(const matrix &rhs) {
    matrix ret;
    ret.clear();
    for (int i = 1; i <= 4; i++)
      for (int j = 1; j <= 4; j++)
        for (int k = 1; k <= 4; k++)
          ret[i][j] =
              (1LL * ret[i][j] + 1LL * mat[i][k] * rhs.mat[k][j] % (mod - 1)) %
              (mod - 1);
    return ret;
  }
  matrix operator^(const long long &rhs) {
    long long tim = rhs;
    matrix ret, bas = *this;
    ret.clear();
    for (int i = 1; i <= 4; i++) ret[i][i] = 1;
    while (tim) {
      if (tim & 1LL) ret = ret * bas;
      bas = bas * bas;
      tim >>= 1LL;
    }
    return ret;
  }
} trans, A;

void factorize(int x, int org) {
  for (int i = 2; 1LL * i * i <= x; i++) {
    if (x % i == 0) primes.push_back(i);
    while (x % i == 0) primeTable[org][i]++, x /= i;
  }
  if (x != 1) primes.push_back(x), primeTable[org][x]++;
  sort(primes.begin(), primes.end());
  primes.erase(unique(primes.begin(), primes.end()), primes.end());
}

int main() {
  trans[1][1] = trans[2][1] = trans[3][1] = 1;
  trans[1][2] = trans[2][3] = trans[3][4] = 1;
  scanf("%lld%d%d%d%d", &n, &f[1], &f[2], &f[3], &c);
  
  // Check performance-related invariants
  check_high_factorization_overhead(primes);
  check_large_unique_primes(primes);

  trans = trans ^ (n - 3);
  check_matrix_exponentiation_complexity(trans);

  int ans = 1;
  for (int i = 1; i <= 3; i++) {
    factorize(f[i], i);
    for (int d = 1; d <= i; d++) factorize(c, i);
  }
  for (int i = 0, siz = primes.size(); i < siz; i++) {
    A.clear();
    for (int j = 1; j <= 3; j++)
      A[1][4 - j] = (0LL + A[1][4 - j] + primeTable[j][primes[i]]) % (mod - 1);
    A = A * trans;
    ans = 1LL * ans * quick_pow(primes[i], A[1][1]) % mod;
  }
  printf("%lld\n", 1LL * ans * quick_pow(quick_pow(c, mod - 2), n) % mod);
  return 0;
}