#include <bits/stdc++.h>
template <typename T>
using MaxHeap = std::priority_queue<T>;
template <typename T>
using MinHeap = std::priority_queue<T, std::vector<T>, std::greater<T>>;
template <typename T>
inline bool chmax(T &a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
template <typename T>
inline bool chmin(T &a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
template <typename T>
std::vector<T> vec(int len, T elem) {
  return std::vector<T>(len, elem);
}
template <typename T>
void vdeb(std::vector<T> &da) {
  for (int i = 0; i < da.size(); i++) {
    if (i == da.size() - 1)
      std::cout << da[i];
    else
      std::cout << da[i] << ' ';
  }
  std::cout << std::endl;
}
template <typename T>
void vdeb(std::vector<std::vector<T>> &da) {
  for (int i = 0; i < da.size(); i++) vdeb(da[i]);
  std::cout << std::endl;
}
using namespace std;
long long pow(long long n, long long p, long long k) {
  if (!k) return 1;
  long long a = pow(n, p, k >> 1);
  a = a * a % p;
  if (k & 1) a = a * n % p;
  return a;
}
void euclid(long long &a, long long &b, long long p) {
  if (a == 1) {
    a = 1;
  } else {
    long long A = b, B = a % b;
    euclid(A, B, p);
    b = (A - (p + a / b) % p * B % p + p) % p;
    a = B;
  }
}
long long rev(long long n, long long p) { return pow(n, p, p - 2); }
long long bino(long long n, long long m, long long p) {
  long long ans = 1, div = 1;
  for (int i = 0; i < m; i++) {
    ans = (n - i) * ans % p;
    div = div * (i + 1) % p;
  }
  return ans * rev(div, p) % p;
}
struct modint {
  long long num;
  long long p;
  modint() {
    num = 0;
    p = 998244353;
  }
  modint(int x) {
    p = 998244353;
    num = (long long)x % p;
  }
  modint(long long x) {
    p = 998244353;
    num = x % p;
  }
  modint operator+(const modint &other) {
    modint ret;
    ret.p = p;
    ret.num = (num + other.num) % p;
    return ret;
  }
  modint operator+(const long long &other) {
    modint ret;
    ret.p = p;
    ret.num = (num + (other % p)) % p;
    return ret;
  }
  modint operator-(const modint &other) {
    modint ret;
    ret.p = p;
    ret.num = (num - other.num + p) % p;
    return ret;
  }
  modint operator-(const long long &other) {
    modint ret;
    ret.p = p;
    ret.num = (num - (other % p) + p) % p;
    return ret;
  }
  modint operator*(const modint &other) {
    modint ret;
    ret.p = p;
    ret.num = (num * other.num) % p;
    return ret;
  }
  modint operator*(const long long &other) {
    modint ret;
    ret.p = p;
    ret.num = (num * (other % p)) % p;
    return ret;
  }
  modint operator/(const modint &other) {
    modint ret;
    ret.p = p;
    ret.num = (num * rev(other.num, p)) % p;
    return ret;
  }
  modint operator/(const long long &other) {
    modint ret;
    ret.p = p;
    ret.num = (num * rev(other % p, p)) % p;
    return ret;
  }
  void operator+=(const long long &other) { num = (num + other) % p; }
  void operator+=(const modint &other) { num = (num + other.num) % p; }
  void operator-=(const long long &other) { num = (num - other + p) % p; }
  void operator-=(const modint &other) { num = (num - other.num + p) % p; }
  void operator*=(const long long &other) { num = (num * other) % p; }
  void operator*=(const modint &other) { num = (num * other.num) % p; }
};
std::ostream &operator<<(std::ostream &os, const modint &x) {
  std::cout << x.num;
  return os;
}
template <typename T>
struct matrix {
  int size;
  vector<vector<T>> table;
  matrix(int n) {
    size = n;
    table = vector<vector<T>>(n, vector<T>(n));
  }
  matrix<T> operator*(const matrix<T> &othor) {
    matrix<T> ret(size);
    for (int i = 0; i < size; i++) {
      for (int j = 0; j < size; j++) {
        for (int k = 0; k < size; k++) {
          ret.table[i][j] += table[i][k] * othor.table[k][j];
        }
      }
    }
    return ret;
  }
  matrix<T> operator+(const matrix<T> &other) {
    matrix<T> ret(size);
    for (int i = 0; i < size; i++) {
      for (int j = 0; j < size; j++) {
        ret[i][j] = table[i][j] + other.table[i][j];
      }
    }
    return ret;
  }
  matrix<T> operator-(const matrix<T> &other) {
    matrix<T> ret(size);
    for (int i = 0; i < size; i++) {
      for (int j = 0; j < size; j++) {
        ret[i][j] = table[i][j] - other.table[i][j];
      }
    }
    return ret;
  }
  T trace(T num) {
    T ret = num;
    for (int i = 0; i < size; i++) {
      ret += table[i][i];
    }
    return ret;
  }
  T all_sum() {
    T ret = table[0][0];
    for (int i = 1; i < size; i++) {
      ret += table[0][i];
    }
    for (int i = 1; i < size; i++) {
      for (int j = 0; j < size; j++) {
        ret += table[i][j];
      }
    }
    return ret;
  }
};
template <typename T>
T power(T x, long long y) {
  if (y == 1) return x;
  if (y % 2) return x * power(x, y - 1);
  T tmp = power(x, y / 2);
  return tmp * tmp;
}
int main() {
  long long n, m, l, r;
  cin >> n >> m >> l >> r;
  if (n * m % 2) {
    cout << power(modint(r - l + 1), n * m) << endl;
    return 0;
  }
  l--;
  modint odd(0), even(0);
  odd += (r + 1) / 2;
  odd -= (l + 1) / 2;
  even += r / 2;
  even -= l / 2;
  matrix<modint> ma(2);
  ma.table[0][0] = even;
  ma.table[0][1] = odd;
  ma.table[1][1] = even;
  ma.table[1][0] = odd;
  ma = power(ma, n * m - 1);
  modint ans;
  ans = ma.table[0][1] * odd + ma.table[0][0] * even;
  cout << ans << endl;
}
