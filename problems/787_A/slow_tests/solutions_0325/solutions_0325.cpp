#include <bits/stdc++.h>
using namespace std;
long long bigmod(long long b, long long p) {
  if (p == 0) return 1;
  long long my = bigmod(b, p / 2);
  my *= my;
  my %= 1000000007;
  if (p & 1) my *= b, my %= 1000000007;
  return my;
}
int setb(int n, int pos) { return n = n | (1 << pos); }
int resb(int n, int pos) { return n = n & ~(1 << pos); }
bool checkb(int n, int pos) { return (bool)(n & (1 << pos)); }
int a, b, c, d;
int main() {
  int i;
  scanf("%d %d", &a, &b);
  scanf("%d %d", &c, &d);
  int ret = -1;
  int mn = max(b, d);
  for (i = mn; i <= 100000000; i++) {
    int ok = 0;
    int val1 = i - b;
    if (val1 % a == 0) ok++;
    int val2 = i - d;
    if (val2 % c == 0) ok++;
    if (ok == 2) {
      ret = i;
      break;
    }
  }
  printf("%d", ret);
  printf("\n");
  return 0;
}
