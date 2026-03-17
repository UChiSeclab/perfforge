#include <bits/stdc++.h>
#pragma comment(linker, "/stack:102400000,102400000")
using namespace std;
int f_abs(int x) { return x < 0 ? -x : x; }
int lowbit(int x) { return (x & -x); }
int f_max(int a, int b) { return a > b ? a : b; }
int f_min(int a, int b) { return a < b ? a : b; }
int gcd(int a, int b) {
  while (int t = a % b) a = b, b = t;
  return b;
}
bool isdig(char ch) { return ch >= '0' && ch <= '9'; }
bool isup(char ch) { return ch >= 'A' && ch <= 'Z'; }
bool islow(char ch) { return ch >= 'a' && ch <= 'z'; }
void swap(int& a, int& b) {
  int t = a;
  a = b;
  b = t;
}
const int inf = 0x7fffffff;
const int mod = 1000000007;
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
void solve() {
  int i, j;
  dp[0] = 1;
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
