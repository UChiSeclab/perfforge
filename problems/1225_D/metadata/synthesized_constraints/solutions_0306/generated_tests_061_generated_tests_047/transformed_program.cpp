#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5, mo = 1e9 + 7, mo2 = 998244353;
int n, k, a;
int c[N];
int p[N], ps;
vector<pair<int, int> > d[N];
long long ans, aa;
bool b[N];

void check_recursion_depth(int depth, int maxDepth) {
    if (depth > maxDepth) {
        cerr << "Warning: Performance bottleneck condition triggered due to high recursion depth!" << endl;
        abort();
    }
}

void check_factorization_complexity(int numFactors, int threshold) {
    if (numFactors > threshold) {
        cerr << "Warning: Performance bottleneck condition triggered due to complex factorization!" << endl;
        abort();
    }
}

void check_multiplicative_combinations(int combinations, int threshold) {
    if (combinations > threshold) {
        cerr << "Warning: Performance bottleneck condition triggered due to excessive multiplicative pair combinations!" << endl;
        abort();
    }
}

void check_prime_factorization(int factors, int powerThreshold) {
    if (factors > powerThreshold) {
        cerr << "Warning: Performance bottleneck condition triggered due to complex prime factorization with high powers!" << endl;
        abort();
    }
}

void go(long long s, int x, int sz, vector<pair<int, int> >& d) {
  check_recursion_depth(x, 100); // Check for high recursion depth

  if (x == sz) {
    long long s2 = aa / s;
    if (s <= 1e5 && s2 <= 1e5) {
      if (s == s2)
        ans += (long long)c[s] * (c[s] - 1);
      else
        ans += (long long)c[s] * c[s2];
    }
    return;
  }
  check_factorization_complexity(d[x].second, 10); // Check factorization complexity
  for (int i = 0, _e = d[x].second; i <= _e; ++i) {
    go(s, x + 1, sz, d);
    s *= d[x].first;
  }
}

int main() {
  cin >> n >> k;
  for (int i = 1, _e = n; i <= _e; ++i) scanf("%d", &a), c[a]++;
  int a = pow(1e10, 1. / k);
  for (; (long double)pow(a + 1, k) <= 1e10;) ++a;
  for (int i = 2, _e = a; i <= _e; ++i) {
    if (!b[i]) p[++ps] = i, d[i].push_back(pair<int, int>(i, 1));
    for (int j = 1, u; (u = i * p[j]) <= a; ++j) {
      b[u] = 1;
      if (i % p[j] == 0) {
        d[u] = d[i];
        d[u][d[u].size() - 1].second++;
        break;
      }
      d[u] = d[i];
      d[u].push_back(pair<int, int>(p[j], 1));
    }
  }

  for (int i = 1, _e = a; i <= _e; ++i) {
    aa = 1;
    for (int j = 1, _e = k; j <= _e; ++j) aa *= i;
    check_prime_factorization(d[i].size(), 10); // Check prime factorization complexity
    for (int j = 0, _e = d[i].size() - 1; j <= _e; ++j) d[i][j].second *= k;
    go(1, 0, d[i].size(), d[i]);
  }

  cout << ans / 2;
}