#include <bits/stdc++.h>
using namespace std;
template <class T>
T abs(T x) {
  return x > 0 ? x : -x;
}
template <class T>
T gcd(T a, T b) {
  return a ? gcd(b % a, a) : b;
}
template <class T>
T sqr(T a) {
  return a * a;
}
template <class T>
T sgn(T a) {
  return a > 0 ? 1 : (a < 0 ? -1 : 0);
}
int n;
int m;
const int N = 101;
bool was[N][N][N], ans;
char s[N];
void go(int i, int j, int k) {
  if (i == n) {
    ans |= k == m;
    return;
  }
  if (was[i][j][k]) return;
  if (s[i] == 'N')
    go(i + 1, j + 1, max(j + 1, k));
  else if (s[i] == 'Y')
    go(i + 1, 0, k);
  else if (s[i] == '?')
    go(i + 1, 0, k), go(i + 1, j + 1, max(j + 1, k));
  was[i][j][k] = true;
  return;
}
int main() {
  scanf("%d%d ", &n, &m);
  gets(s);
  go(0, 0, 0);
  if (ans)
    puts("YES");
  else
    puts("NO");
  return 0;
}
