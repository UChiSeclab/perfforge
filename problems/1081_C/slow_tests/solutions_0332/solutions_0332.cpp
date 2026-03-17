#include <bits/stdc++.h>
using namespace std;
long long Gcd(long long a, long long b) {
  if (a % b == 0) return b;
  return Gcd(b, a % b);
}
long long Max(long long a, long long b) {
  if (a > b) return a;
  return b;
}
long long Min(long long a, long long b) {
  if (a < b) return a;
  return b;
}
long long gcdExtended(long long a, long long b, long long *x, long long *y) {
  if (a == 0) {
    *x = 0, *y = 1;
    return b;
  }
  long long x1, y1;
  long long gcd = gcdExtended(b % a, a, &x1, &y1);
  *x = y1 - (b / a) * x1;
  *y = x1;
  return gcd;
}
long long power(long long x, long long y, long long p) {
  long long res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
long long modInverse(long long a, long long m) {
  long long x, y;
  long long g = gcdExtended(a, m, &x, &y);
  if (g != 1)
    return -1;
  else {
    long long res = (x % m + m) % m;
    return res;
  }
}
vector<int> primeFactors(int n) {
  vector<int> v;
  while (n % 2 == 0) {
    v.push_back(2);
    n = n / 2;
  }
  for (int i = 3; i <= sqrt(n); i = i + 2) {
    while (n % i == 0) {
      v.push_back(i);
      n = n / i;
    }
  }
  if (n > 2) v.push_back(n);
  return v;
}
long long spf[100001];
void sieve() {
  spf[1] = 1;
  for (int i = 2; i < 100001; i++) spf[i] = i;
  for (int i = 4; i < 100001; i += 2) spf[i] = 2;
  for (int i = 3; i * i < 100001; i++) {
    if (spf[i] == i) {
      for (int j = i * i; j < 100001; j += i)
        if (spf[j] == j) spf[j] = i;
    }
  }
}
long long binarySearch(long long arr[], long long l, long long r, long long x) {
  if (r >= l) {
    long long mid = l + (r - l) / 2;
    if (arr[mid] == x) return mid;
    if (arr[mid] > x) return binarySearch(arr, l, mid - 1, x);
    return binarySearch(arr, mid + 1, r, x);
  }
  return -1;
}
const long long N = 100000;
long long n;
long long tree[2 * N];
void build(long long arr[]) {
  for (long long i = 0; i < n; i++) {
    tree[n + i] = arr[i];
  }
  for (long long i = n - 1; i > 0; --i) {
    tree[i] = tree[i << 1] + tree[i << 1 | 1];
  }
}
void updateTreeNode(long long p, long long value) {
  tree[p + n] = value;
  p = p + n;
  for (long long i = p; i > 1; i >>= 1) {
    tree[i >> 1] = tree[i] + tree[i ^ 1];
  }
}
long long query(long long l, long long r) {
  long long res = 0;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l & 1) {
      res += tree[l++];
    }
    if (r & 1) {
      res += tree[--r];
    }
  }
  return res;
}
void dfs(std::vector<long long> v[], long long s, bool visited[]) {
  visited[s] = true;
  for (long long i = 0; i < v[s].size(); ++i) {
    if (!visited[v[s][i]]) {
      dfs(v, v[s][i], visited);
    }
  }
}
long long C[2001][2000];
void binomialCoeff(long long n, long long k) {
  long long i, j;
  for (i = 0; i <= n; i++) {
    for (j = 0; j <= k; j++) {
      if (j == 0 || j == i)
        C[i][j] = 1;
      else
        C[i][j] =
            (C[i - 1][j - 1] % 998244353 + C[i - 1][j] % 998244353) % 998244353;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n, m, k;
  cin >> n >> m >> k;
  binomialCoeff(n, k);
  long long mminus1 = power(m - 1, k, 998244353);
  mminus1 %= 998244353;
  long long ans = 1;
  ans *= mminus1 % 998244353;
  ans = ((ans % 998244353) * (m)) % 998244353;
  ans = ((ans % 998244353) * (C[n - 1][k])) % 998244353;
  cout << ans << endl;
  return 0;
}
