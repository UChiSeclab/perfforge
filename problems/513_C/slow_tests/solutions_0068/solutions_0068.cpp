#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1);
const double eps = 1e-9;
const int inf = 2000000000;
const long long infLL = 9000000000000000000;
inline bool checkBit(long long n, int i) { return n & (1LL << i); }
inline long long setBit(long long n, int i) {
  return n | (1LL << i);
  ;
}
inline long long resetBit(long long n, int i) { return n & (~(1LL << i)); }
int dx[] = {0, 0, +1, -1};
int dy[] = {+1, -1, 0, 0};
inline bool EQ(double a, double b) { return fabs(a - b) < 1e-9; }
inline bool isLeapYear(long long year) {
  return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}
inline void normal(long long &a) {
  a %= 1000000007;
  (a < 0) && (a += 1000000007);
}
inline long long modMul(long long a, long long b) {
  a %= 1000000007, b %= 1000000007;
  normal(a), normal(b);
  return (a * b) % 1000000007;
}
inline long long modAdd(long long a, long long b) {
  a %= 1000000007, b %= 1000000007;
  normal(a), normal(b);
  return (a + b) % 1000000007;
}
inline long long modSub(long long a, long long b) {
  a %= 1000000007, b %= 1000000007;
  normal(a), normal(b);
  a -= b;
  normal(a);
  return a;
}
inline long long modPow(long long b, long long p) {
  long long r = 1;
  while (p) {
    if (p & 1) r = modMul(r, b);
    b = modMul(b, b);
    p >>= 1;
  }
  return r;
}
inline long long modInverse(long long a) { return modPow(a, 1000000007 - 2); }
inline long long modDiv(long long a, long long b) {
  return modMul(a, modInverse(b));
}
const int MX = 10100;
int vis[5][5][5], l[5], r[5], curnum, n;
double dp[5][5][5];
double func(int pos, int eNum, int bNum) {
  if (bNum > 1) return 0;
  if (pos == n) {
    if (eNum > 1 && !bNum) return 1;
    if (eNum && bNum) return 1;
    return 0;
  }
  if (vis[pos][eNum][bNum]) return dp[pos][eNum][bNum];
  vis[pos][eNum][bNum] = 0;
  double &ret = dp[pos][eNum][bNum];
  ret = 0;
  if (curnum >= l[pos] && curnum <= r[pos]) {
    double temp = (1.0 / (r[pos] - l[pos] + 1));
    temp *= func(pos + 1, eNum + 1, bNum);
    ret += temp;
  }
  if (r[pos] > curnum) {
    double temp = 1;
    if (l[pos] <= curnum) {
      temp *= (double)(r[pos] - curnum) / (double)(r[pos] - l[pos] + 1);
    }
    temp *= func(pos + 1, eNum, bNum + 1);
    ret += temp;
  }
  if (l[pos] < curnum) {
    double temp = 1;
    if (r[pos] >= curnum) {
      temp *= (double)(curnum - l[pos]) / (double)(r[pos] - l[pos] + 1);
    }
    temp *= func(pos + 1, eNum, bNum);
    ret += temp;
  }
  return ret;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  cout.unsetf(ios::floatfield);
  cout.precision(10);
  cout.setf(ios::fixed, ios::floatfield);
  ;
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> l[i] >> r[i];
  double ans = 0;
  for (int i = 1; i < MX; ++i) {
    curnum = i;
    ans += i * func(0, 0, 0);
    ;
    memset(vis, 0, sizeof(vis));
  }
  cout << ans;
  return 0;
}
